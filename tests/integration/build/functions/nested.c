/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

typedef struct {
    int64_t _0;
    int64_t _1;
} struct2;

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _732_main(void);
int64_t _734_fib(int64_t _734_n);
int64_t _739_add(int64_t _739_x,int64_t _739_y);

/* Function definitions */
int64_t _732_main(void) {
    function0 _732_t0;
    int64_t _732_t2;
    int64_t _732_t1;
    int64_t _732_t3;
    int64_t _732_$retval;
    _732_t0 = _734_fib;
    _732_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _732_t1 = _732_t0(_732_t2);
    $line_idx--;
    _732_t3 = 10;
    _732_$retval = $sub_int64_t(_732_t1, _732_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _732_$retval;
}

int64_t _734_fib(int64_t _734_n) {
    function1 _734_t7;
    function0 _734_t9;
    int64_t _734_t11;
    int64_t _734_t12;
    int64_t _734_t10;
    function0 _734_t13;
    int64_t _734_t15;
    int64_t _734_t16;
    int64_t _734_t14;
    int64_t _734_t8;
    int64_t _734_t0;
    int64_t _734_t1;
    uint8_t _734_t2;
    int64_t _734_t3;
    uint8_t _734_t4;
    int64_t _734_$retval;
    _734_t1 = 0;
    _734_t2 = _734_n == _734_t1;
    if (_734_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _734_t0 = 0;
    goto BB5;
BB6:
    _734_t3 = 1;
    _734_t4 = _734_n == _734_t3;
    if (_734_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _734_$retval = _734_t0;
    return _734_$retval;
BB8:
    _734_t0 = 1;
    goto BB5;
BB10:
    _734_t7 = _739_add;
    _734_t9 = _734_fib;
    _734_t11 = 1;
    _734_t12 = $sub_int64_t(_734_n, _734_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _734_t10 = _734_t9(_734_t12);
    $line_idx--;
    _734_t13 = _734_fib;
    _734_t15 = 2;
    _734_t16 = $sub_int64_t(_734_n, _734_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _734_t14 = _734_t13(_734_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _734_t8 = _734_t7(_734_t10, _734_t14);
    $line_idx--;
    _734_t0 = _734_t8;
    goto BB5;
}

int64_t _739_add(int64_t _739_x,int64_t _739_y) {
    int64_t _739_$retval;
    _739_$retval = $add_int64_t(_739_x, _739_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _739_$retval;
}

int main(void) {
  printf("%ld",_732_main());
  return 0;
}
