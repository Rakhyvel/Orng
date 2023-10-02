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
int64_t _1_main();
int64_t _3_a(int64_t _3_n);
int64_t _5_b(int64_t _5_n);
int64_t _7_c(int64_t _7_n);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1_t0 = _3_a(47);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_a(int64_t _3_n) {
    int64_t _3_t0;
    int64_t _3_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _3_t0 = _5_b(_3_n);
    $line_idx--;
    _3_$retval = _3_t0;
    return _3_$retval;
}

int64_t _5_b(int64_t _5_n) {
    int64_t _5_t0;
    int64_t _5_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _5_t0 = _7_c(_5_n);
    $line_idx--;
    _5_$retval = _5_t0;
    return _5_$retval;
}

int64_t _7_c(int64_t _7_n) {
    int64_t _7_t0;
    int64_t _7_t4;
    int64_t _7_$retval;
    if (_7_n == 47) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _7_t0 = 47;
    goto BB4;
BB5:
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _7_t4 = _3_a(_7_n);
    $line_idx--;
    _7_t0 = _7_t4;
BB4:
    _7_$retval = _7_t0;
    return _7_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
