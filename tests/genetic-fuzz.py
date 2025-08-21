import random
import subprocess
import shutil
import os
from lxml import etree
import tempfile
from concurrent.futures import ThreadPoolExecutor
from concurrent.futures import ProcessPoolExecutor
from typing import Self
from static_analysis import ngram, collect_files, zig_scanner
from multiprocessing import Manager
import time
from collections import defaultdict
import statistics
import math
from itertools import groupby

TEST_DIR = os.path.dirname(os.path.realpath(__file__))
SRC_DIR = os.path.normpath(os.path.join(TEST_DIR, "..", "src"))

manager = Manager()
lines = manager.dict()
fitness_cache = manager.dict()
mutation_stats = manager.dict()
errors = manager.dict()

mutation_weights = {
    (k, n): 1.0
    for k in [
        "delete-smart",
        "insert-smart",
        "shuffle",
        "swap-smart",
        "swap-dumb",
        "insert-dumb",
    ]
    for n in range(3, 8)
}


def append_mutation_stat(mutation_type: str, delta):
    if mutation_type not in mutation_stats:
        mutation_stats[mutation_type] = manager.list()
    mutation_stats[mutation_type].append(delta)


def insert_line(file, line_number):
    lines[(file, line_number)] = True


def get_line(file, line_number):
    return lines.get((file, line_number), False)


def reset_mutation_stat(mutation_type: str):
    mutation_stats[mutation_type] = manager.list()


def add_error_program(error: str):
    errors[error] = True


def parse_coverage(xml_file):
    try:
        tree = etree.parse(xml_file)
        root = tree.getroot()
    except (etree.XMLSyntaxError, FileNotFoundError):
        return 0.0

    lines_covered = 0.0

    # XPath runs in compiled C and skips all non-matching nodes
    for line_elem in root.xpath(
        "//class[@filename]/lines/line[@hits and @number and number(@hits) > 0]"
    ):
        class_elem = line_elem.getparent()  # <lines>
        class_elem = class_elem.getparent()  # <class>
        filename = class_elem.get("filename")

        if filename:
            line_number = line_elem.get("number")
            lines_covered += 0 if get_line(filename, line_number) else 1
            insert_line(filename, line_number)

    return lines_covered


class Pop:
    def __init__(self, genes, prev_mut=""):
        self.genes = genes
        self.fitness = 0
        self.prev_mut = prev_mut

    def calculate_fitness(self):
        prev_fitness = self.fitness
        self._calculate_fitness()
        if self.prev_mut != "":
            append_mutation_stat(self.prev_mut, self.fitness - prev_fitness)
        append_mutation_stat("generation", self.fitness)

    def _calculate_fitness(self):
        program_text = self.convert_to_display()

        with tempfile.TemporaryDirectory() as tmpdir:
            kcov_out = os.path.join(tmpdir, "kcov-out")

            programs = [
                list(g)
                for k, g in groupby(self.genes, key=lambda x: x is not None)
                if k
            ]

            for program in programs:
                text = convert_to_string(program)
                self._run_program(tmpdir, kcov_out, text)

            cov_xml_path = os.path.join(
                kcov_out, "orng-test.164bd816b5697cd7", "cov.xml"
            )
            if len(self.genes) > 120:
                self.fitness = 0
            else:
                self.fitness = parse_coverage(cov_xml_path)

        fitness_cache[program_text] = self.fitness

    def _run_program(self, tmpdir: str, kcov_out: str, program_text: str):
        input_path = os.path.join(tmpdir, "out.orng")
        with open(input_path, "w") as f:
            f.write(program_text)

        try:
            result = subprocess.run(
                [
                    "kcov",
                    "--include-path",
                    SRC_DIR,
                    kcov_out,
                    "./zig-out/bin/orng-test",
                    "coverage",
                    input_path,
                ],
                timeout=15,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                cwd=None,
                preexec_fn=os.setsid if os.name != "nt" else None,
            )
            res = result.returncode
        except subprocess.TimeoutExpired:
            try:
                os.killpg(os.getpgid(result.pid), 9)  # no zombies
            except:
                pass
            print("timeout")
            res = 1

        if res != 0:
            add_error_program(self.convert_to_display())

    def convert_to_display(self):
        return " ".join(list(map(lambda x: str(x), self.genes)))

    def crossover(self, parent1: Self, parent2: Self):
        """Crossover that preserves high-coverage regions"""

        # Simple case: just concatenate sometimes
        if random.random() < 0.1 or len(parent1.genes) < 2 or len(parent2.genes) < 2:
            self.genes = parent1.genes + parent2.genes
            self.prev_mut = "concat"
            return

        # TODO: For more sophisticated crossover, we'd need to track which parts
        # of each parent contributed to coverage. This is a simplified version:

        # Bias crossover points toward the beginning and end of programs
        # since these often contain important structural elements
        def biased_point(length):
            if random.random() < 0.3:  # 30% chance of picking near start
                return random.randint(0, min(5, length - 1))
            elif random.random() < 0.3:  # 30% chance of picking near end
                return random.randint(max(0, length - 6), length - 1)
            else:  # 40% chance of uniform random
                return random.randint(0, length - 1)

        p1_start = biased_point(len(parent1.genes))
        p1_end = random.randint(p1_start, len(parent1.genes) - 1)

        p2_start = biased_point(len(parent2.genes))
        p2_end = random.randint(p2_start, len(parent2.genes) - 1)

        # Create child by combining segments
        self.genes = (
            parent1.genes[:p1_start]
            + parent2.genes[p2_start:p2_end]
            + parent1.genes[p1_end:]
        )

    def mutate(self, models):
        def shuffle(self, n):
            self.prev_mut = ("shuffle", n)
            if len(self.genes) > 2:
                i = random.randint(0, len(self.genes) - 2)
                j = random.randint(i + 1, len(self.genes))
                random.shuffle(self.genes[i:j])
            elif len(self.genes) == 2:
                self.genes[1], self.genes[0] = self.genes[0], self.genes[1]

        def delete_smart(self, n):
            ctx = tuple(self.genes[idx - n + 1 : idx])
            if len(ctx) != n - 1:
                return
            del self.genes[idx]
            next_token = models[n].predict(ctx)
            while len(self.genes) > idx + 1 and next_token != self.genes[idx]:
                del self.genes[idx]
            self.prev_mut = ("delete-smart", n)

        def swap_smart(self, n):
            if n - 1 <= idx < len(self.genes):
                ctx = tuple(self.genes[idx - n + 1 : idx])
            else:
                ctx = tuple([None] * (n - 1 - idx) + self.genes[0:idx])
            assert len(ctx) == n - 1
            if idx + 1 < len(self.genes) - 1:
                end_point = random.randint(idx + 1, len(self.genes) - 1)
            else:
                end_point = idx + 1
            end_token = self.genes[end_point] if idx < len(self.genes) - 1 else None
            insert_me = models[n].generate_until(ctx, lambda x: x == end_token)
            attempts = 0
            while len(insert_me) < 2 and attempts < 5:
                insert_me = models[n].generate_until(ctx, lambda x: x == end_token)
                attempts += 1
            self.genes[idx + 1 : end_point] = insert_me
            self.prev_mut = ("swap-smart", n)

        def insert_smart(self, n):
            if n - 1 <= idx < len(self.genes):
                ctx = tuple(self.genes[idx - n + 1 : idx])
            else:
                ctx = tuple([None] * (n - 1 - idx) + self.genes[0:idx])
            assert len(ctx) == n - 1
            insert_me = models[n].predict(ctx)
            self.genes.insert(idx, insert_me)
            self.prev_mut = ("insert-smart", n)

        def insert_dumb(self, n):
            self.genes.insert(idx, models[n].random_token() or " ")
            self.prev_mut = ("insert-dumb", n)

        def swap_dumb(self, n):
            self.genes[idx] = models[n].random_token() or " "
            self.prev_mut = ("swap-dumb", n)

        if len(self.genes) == 0:
            self.genes = [models[5].random_token() or " "]
            self.prev_mut = "random-token"
            return

        mutations = {
            "insert-smart": insert_smart,
            "swap-smart": swap_smart,
            "insert-dumb": insert_dumb,
            "delete-smart": delete_smart,
            "shuffle": shuffle,
            "swap-dumb": swap_dumb,
        }
        idx = random.randint(0, len(self.genes) - 1)
        prev_genes = self.genes[:]
        attempts = 0
        while self.genes == prev_genes and attempts < 10:
            merged = {
                (k, n): (mutations[k], mutation_weights[(k, n)], n)
                for k in mutations.keys()
                for n in range(3, 8)
            }
            chosen_mutation = random.choices(
                population=[merged[k] for k in merged.keys()],
                weights=[merged[k][1] for k in merged.keys()],
                k=1,
            )[0]
            chosen_mutation[0](self, chosen_mutation[2])
            attempts += 1


def convert_to_string(genes: list[str]):
    TOKEN_CONVERSION = {" ": "", "NEWLINE": "\n"}
    return " ".join(
        TOKEN_CONVERSION.get(token, token) for token in genes if token != " "
    )


def calculate_fitness_data(pop_data, prev_mut, fitness):
    pop = Pop(pop_data, prev_mut)
    pop.fitness = fitness
    pop.calculate_fitness()
    return pop


def main():
    shutil.rmtree("zig-cache", ignore_errors=True)
    shutil.rmtree("zig-out", ignore_errors=True)
    res = subprocess.run(
        ["zig", "build", "orng-test", "--release=safe", "-Doptimize=Debug"]
    ).returncode
    if res != 0:
        exit(1)

    models = build_ngram_model()

    population_size = 16
    high = 0
    low = 0
    population = [Pop(random_genes(models[4])) for _ in range(population_size)]

    best_score = 0
    lines_covered = 0
    gen = 0
    try:
        while lines_covered < 9320:
            start_time = time.perf_counter()
            with ProcessPoolExecutor(max_workers=os.cpu_count()) as executor:
                futures = [
                    executor.submit(
                        calculate_fitness_data, pop.genes, pop.prev_mut, pop.fitness
                    )
                    for pop in population
                ]
                for i, f in enumerate(futures):
                    population[i] = f.result()

            """
            population.sort(key=lambda pop: -pop.fitness)

            new_gen = population[:high]

            # TODO: Try tournament select
            def tournament_selection(population, tournament_size=3):
                tournament = random.sample(
                    population, min(tournament_size, len(population))
                )
                return max(tournament, key=lambda x: x.fitness)

            # In main loop, use tournament selection for parents
            for i in range(high, low):
                parent1 = tournament_selection(
                    population[: high * 2]
                )  # Select from top performers
                parent2 = tournament_selection(population[: high * 2])

                new_pop = Pop(population[i].genes, population[i].prev_mut)
                new_pop.fitness = population[i].fitness
                new_pop.crossover(parent1, parent2)
                new_gen.append(new_pop)

            # cross over mid - low
            for i in range(high, low):
                parent1, parent2 = random.choices(
                    population=[population[j] for j in range(0, population_size)],
                    weights=[
                        population[j].fitness + 0.01 for j in range(0, population_size)
                    ],
                    k=2,
                )
                new_pop = Pop(population[i].genes, population[i].prev_mut)
                new_pop.fitness = population[i].fitness
                new_pop.crossover(parent1, parent2)
                new_gen.append(new_pop)
            """

            # random low
            for i in range(low, population_size):
                population[i] = Pop(random_genes(models[4]))

            # population = new_gen

            # mutate high-low
            # for i in range(high, low):
            #     population[i].mutate(models)

            end_time = time.perf_counter()
            # for mut, deltas in mutation_stats.items():
            #     deltas = list(deltas)  # Convert manager list to plain list
            #     if not deltas:
            #         continue
            #     # print(
            #     #     f"{str(mut)} \tweight: {mutation_weights[mut] if mut in mutation_weights else 1.0}\tcount: {len(deltas)}\tavg: {statistics.mean(deltas):.3f}\tmin: {min(deltas):.3f}\tmax: {max(deltas):.3f}\tmedian: {statistics.median(deltas):.3f}"
            #     # )

            if lines_covered < len(lines):
                lines_covered = len(lines)
                print(
                    f"gen: {gen}  covered: {len(lines)}  time: {end_time - start_time:.1f}s  errors: {len(errors)}"
                )
            # reset_mutation_stat("generation")

            # temp = 0.01
            # if gen % 5 == 0:
            #     for key in mutation_weights.keys():
            #         if key in mutation_stats:
            #             if len(mutation_stats[key]) == 0:
            #                 mutation_stats[key].append(0)
            #             try:
            #                 mutation_weights[key] = math.exp(
            #                     statistics.mean(mutation_stats[key]) / temp
            #                 )
            #             except OverflowError:
            #                 mutation_weights[key] = 1.0
            #             # reset_mutation_stat(key)

            gen += 1
    except KeyboardInterrupt:
        for error in errors.keys():
            print("ERROR:", error)
        raise


def build_ngram_model():
    files = collect_files.collect_files(
        [
            "tests/integration",
            "tests/negative/comptime",
            "tests/negative/externs",
            "tests/negative/generics",
            "tests/negative/misc",
            "tests/negative/optimizer",
            "tests/negative/pattern",
            "tests/negative/regression",
            "tests/negative/symbols",
            "tests/negative/traits",
            "tests/negative/typecheck",
            "examples",
        ]
    )
    models = {n: ngram.NGram(n) for n in range(3, 9)}
    for file in files:
        with open(file, "r") as f:
            text = f.read() + "\n"
        text = zig_scanner.remove_comments(text)
        if len(text) == 0:
            continue
        scanner = zig_scanner.Scanner(text.replace("\n", " NEWLINE "))
        tokens = list(map(lambda token: token.value, scanner.tokenize()))
        for n in models.keys():
            models[n].train(tokens)
    return models


def random_genes(model: ngram.NGram):
    return [*random_program(model)]


def random_program(model: ngram.NGram):
    first_token = random.choice(
        [
            "fn",
            "const",
            "import",
            "extern",
            "trait",
            "impl",
        ]
    )
    gen = model.generate((None,) * (model.n - 2) + (first_token,))
    ret = list(filter(lambda x: x is not None, gen))
    return ret


if __name__ == "__main__":
    main()
