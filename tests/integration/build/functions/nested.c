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
int64_t _668_main(void);
int64_t _670_fib(int64_t _670_n);
int64_t _675_add(int64_t _675_x,int64_t _675_y);

/* Function definitions */
int64_t _668_main(void) {
    function0 _668_t0;
    int64_t _668_t2;
    int64_t _668_t1;
    int64_t _668_t3;
    int64_t _668_$retval;
    _668_t0 = _670_fib;
    _668_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _668_t1 = _668_t0(_668_t2);
    $line_idx--;
    _668_t3 = 10;
    _668_$retval = $sub_int64_t(_668_t1, _668_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _668_$retval;
}

int64_t _670_fib(int64_t _670_n) {
    function1 _670_t7;
    function0 _670_t9;
    int64_t _670_t11;
    int64_t _670_t12;
    int64_t _670_t10;
    function0 _670_t13;
    int64_t _670_t15;
    int64_t _670_t16;
    int64_t _670_t14;
    int64_t _670_t8;
    int64_t _670_t0;
    int64_t _670_t1;
    uint8_t _670_t2;
    int64_t _670_t3;
    uint8_t _670_t4;
    int64_t _670_$retval;
    _670_t1 = 0;
    _670_t2 = _670_n == _670_t1;
    if (_670_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _670_t0 = 0;
    goto BB5;
BB6:
    _670_t3 = 1;
    _670_t4 = _670_n == _670_t3;
    if (_670_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _670_$retval = _670_t0;
    return _670_$retval;
BB8:
    _670_t0 = 1;
    goto BB5;
BB10:
    _670_t7 = _675_add;
    _670_t9 = _670_fib;
    _670_t11 = 1;
    _670_t12 = $sub_int64_t(_670_n, _670_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _670_t10 = _670_t9(_670_t12);
    $line_idx--;
    _670_t13 = _670_fib;
    _670_t15 = 2;
    _670_t16 = $sub_int64_t(_670_n, _670_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _670_t14 = _670_t13(_670_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _670_t8 = _670_t7(_670_t10, _670_t14);
    $line_idx--;
    _670_t0 = _670_t8;
    goto BB5;
}

int64_t _675_add(int64_t _675_x,int64_t _675_y) {
    int64_t _675_$retval;
    _675_$retval = $add_int64_t(_675_x, _675_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _675_$retval;
}

int main(void) {
  printf("%ld",_668_main());
  return 0;
}
