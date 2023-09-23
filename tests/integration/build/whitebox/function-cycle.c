/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Function forward definitions */
int64_t _2_main();
int64_t _4_a(int64_t _4_n);
int64_t _6_b(int64_t _6_n);
int64_t _8_c(int64_t _8_n);

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t0;
    int64_t _2_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _2_t0 = _4_a(47);
    $line_idx--;
    _2_$retval = _2_t0;
    return _2_$retval;
}

int64_t _4_a(int64_t _4_n) {
    int64_t _4_t0;
    int64_t _4_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _4_t0 = _6_b(_4_n);
    $line_idx--;
    _4_$retval = _4_t0;
    return _4_$retval;
}

int64_t _6_b(int64_t _6_n) {
    int64_t _6_t0;
    int64_t _6_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _6_t0 = _8_c(_6_n);
    $line_idx--;
    _6_$retval = _6_t0;
    return _6_$retval;
}

int64_t _8_c(int64_t _8_n) {
    int64_t _8_t0;
    int64_t _8_t4;
    int64_t _8_$retval;
    if (_8_n == 47) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _8_t0 = 47;
    goto BB4;
BB5:
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _8_t4 = _4_a(_8_n);
    $line_idx--;
    _8_t0 = _8_t4;
BB4:
    _8_$retval = _8_t0;
    return _8_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
