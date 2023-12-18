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
int64_t _1093_main(void);
int64_t _1095_fib(int64_t _1095_n);
int64_t _1100_add(int64_t _1100_x,int64_t _1100_y);

/* Function definitions */
int64_t _1093_main(void){
    function0 _1093_t0;
    int64_t _1093_t2;
    int64_t _1093_t1;
    int64_t _1093_t3;
    int64_t _1093_$retval;
    _1093_t0 = _1095_fib;
    _1093_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1093_t1 = _1093_t0(_1093_t2);
    $line_idx--;
    _1093_t3 = 10;
    _1093_$retval = $sub_int64_t(_1093_t1, _1093_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _1093_$retval;
}

int64_t _1095_fib(int64_t _1095_n){
    function1 _1095_t7;
    function0 _1095_t9;
    int64_t _1095_t11;
    int64_t _1095_t12;
    int64_t _1095_t10;
    function0 _1095_t13;
    int64_t _1095_t15;
    int64_t _1095_t16;
    int64_t _1095_t14;
    int64_t _1095_t8;
    int64_t _1095_t0;
    int64_t _1095_t1;
    uint8_t _1095_t2;
    int64_t _1095_t3;
    uint8_t _1095_t4;
    int64_t _1095_$retval;
    _1095_t1 = 0;
    _1095_t2 = _1095_n == _1095_t1;
    if (_1095_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1095_t0 = 0;
    goto BB5;
BB6:
    _1095_t3 = 1;
    _1095_t4 = _1095_n == _1095_t3;
    if (_1095_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _1095_$retval = _1095_t0;
    return _1095_$retval;
BB8:
    _1095_t0 = 1;
    goto BB5;
BB10:
    _1095_t7 = _1100_add;
    _1095_t9 = _1095_fib;
    _1095_t11 = 1;
    _1095_t12 = $sub_int64_t(_1095_n, _1095_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _1095_t10 = _1095_t9(_1095_t12);
    $line_idx--;
    _1095_t13 = _1095_fib;
    _1095_t15 = 2;
    _1095_t16 = $sub_int64_t(_1095_n, _1095_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _1095_t14 = _1095_t13(_1095_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _1095_t8 = _1095_t7(_1095_t10, _1095_t14);
    $line_idx--;
    _1095_t0 = _1095_t8;
    goto BB5;
}

int64_t _1100_add(int64_t _1100_x,int64_t _1100_y){
    int64_t _1100_$retval;
    _1100_$retval = $add_int64_t(_1100_x, _1100_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1100_$retval;
}

int main(void) {
  printf("%ld",_1093_main());
  return 0;
}
