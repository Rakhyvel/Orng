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
int64_t _905_main(void);
int64_t _907_fib(int64_t _907_n);
int64_t _913_add(int64_t _913_x,int64_t _913_y);

/* Function definitions */
int64_t _905_main(void) {
    function0 _905_t0;
    int64_t _905_t2;
    int64_t _905_t1;
    int64_t _905_t3;
    int64_t _905_$retval;
    _905_t0 = _907_fib;
    _905_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _905_t1 = _905_t0(_905_t2);
    $line_idx--;
    _905_t3 = 10;
    _905_$retval = $sub_int64_t(_905_t1, _905_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _905_$retval;
}

int64_t _907_fib(int64_t _907_n) {
    function1 _907_t7;
    function0 _907_t9;
    int64_t _907_t11;
    int64_t _907_t12;
    int64_t _907_t10;
    function0 _907_t13;
    int64_t _907_t15;
    int64_t _907_t16;
    int64_t _907_t14;
    int64_t _907_t8;
    int64_t _907_t0;
    int64_t _907_t1;
    uint8_t _907_t2;
    int64_t _907_t3;
    uint8_t _907_t4;
    int64_t _907_$retval;
    _907_t1 = 0;
    _907_t2 = _907_n == _907_t1;
    if (_907_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _907_t0 = 0;
    goto BB5;
BB6:
    _907_t3 = 1;
    _907_t4 = _907_n == _907_t3;
    if (_907_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _907_$retval = _907_t0;
    return _907_$retval;
BB8:
    _907_t0 = 1;
    goto BB5;
BB10:
    _907_t7 = _913_add;
    _907_t9 = _907_fib;
    _907_t11 = 1;
    _907_t12 = $sub_int64_t(_907_n, _907_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _907_t10 = _907_t9(_907_t12);
    $line_idx--;
    _907_t13 = _907_fib;
    _907_t15 = 2;
    _907_t16 = $sub_int64_t(_907_n, _907_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _907_t14 = _907_t13(_907_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _907_t8 = _907_t7(_907_t10, _907_t14);
    $line_idx--;
    _907_t0 = _907_t8;
    goto BB5;
}

int64_t _913_add(int64_t _913_x,int64_t _913_y) {
    int64_t _913_$retval;
    _913_$retval = $add_int64_t(_913_x, _913_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _913_$retval;
}

int main(void) {
  printf("%ld",_905_main());
  return 0;
}
