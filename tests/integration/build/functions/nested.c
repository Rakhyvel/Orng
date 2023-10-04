/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_fib(int64_t _3_n);
int64_t _8_add(int64_t _8_x,int64_t _8_y);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1_t0 = _3_fib(10);
    $line_idx--;
    _1_$retval = $sub_int64_t(_1_t0, 10, "tests/integration/functions/nested.orng:2:3:\nfn main()->Int {\n ^");
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
    _3_t8 = _3_fib($sub_int64_t(_3_n, 1, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^"));
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _3_t11 = _3_fib($sub_int64_t(_3_n, 2, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^"));
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
    _8_$retval = $add_int64_t(_8_x, _8_y, "tests/integration/functions/nested.orng:14:3:\nfn add(x: Int, y: Int)->Int {x + y}\n ^");
    return _8_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
