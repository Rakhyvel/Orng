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
int64_t _3_fib(int64_t _3_n);
int64_t _8_add(int64_t _8_x,int64_t _8_y);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1_t0 = _3_fib(10);
    $line_idx--;
    _1_$retval = _1_t0 - 10;
    return _1_$retval;
}

int64_t _3_fib(int64_t _3_n) {
    int64_t _3_t8;
    int64_t _3_t11;
    int64_t _3_t7;
    int64_t _3_t0;
    int64_t _3_$retval;
    if (_3_n) {
        goto BB6;
    } else {
        goto BB3;
    }
BB6:
    if (_3_n == 1) {
        goto BB8;
    } else {
        goto BB10;
    }
BB3:
    _3_t0 = 0;
    goto BB5;
BB8:
    _3_t0 = 1;
    goto BB5;
BB10:
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _3_t8 = _3_fib(_3_n - 1);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _3_t11 = _3_fib(_3_n - 2);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _3_t7 = _8_add(_3_t8, _3_t11);
    $line_idx--;
    _3_t0 = _3_t7;
BB5:
    _3_$retval = _3_t0;
    return _3_$retval;
}

int64_t _8_add(int64_t _8_x,int64_t _8_y) {
    int64_t _8_$retval;
    _8_$retval = _8_x + _8_y;
    return _8_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
