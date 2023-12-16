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
int64_t _929_main(void);
int64_t _931_fib(int64_t _931_n);
int64_t _936_add(int64_t _936_x,int64_t _936_y);

/* Function definitions */
int64_t _929_main(void){
    function0 _929_t0;
    int64_t _929_t2;
    int64_t _929_t1;
    int64_t _929_t3;
    int64_t _929_$retval;
    _929_t0 = _931_fib;
    _929_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _929_t1 = _929_t0(_929_t2);
    $line_idx--;
    _929_t3 = 10;
    _929_$retval = $sub_int64_t(_929_t1, _929_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _929_$retval;
}

int64_t _931_fib(int64_t _931_n){
    function1 _931_t7;
    function0 _931_t9;
    int64_t _931_t11;
    int64_t _931_t12;
    int64_t _931_t10;
    function0 _931_t13;
    int64_t _931_t15;
    int64_t _931_t16;
    int64_t _931_t14;
    int64_t _931_t8;
    int64_t _931_t0;
    int64_t _931_t1;
    uint8_t _931_t2;
    int64_t _931_t3;
    uint8_t _931_t4;
    int64_t _931_$retval;
    _931_t1 = 0;
    _931_t2 = _931_n == _931_t1;
    if (_931_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _931_t0 = 0;
    goto BB5;
BB6:
    _931_t3 = 1;
    _931_t4 = _931_n == _931_t3;
    if (_931_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _931_$retval = _931_t0;
    return _931_$retval;
BB8:
    _931_t0 = 1;
    goto BB5;
BB10:
    _931_t7 = _936_add;
    _931_t9 = _931_fib;
    _931_t11 = 1;
    _931_t12 = $sub_int64_t(_931_n, _931_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _931_t10 = _931_t9(_931_t12);
    $line_idx--;
    _931_t13 = _931_fib;
    _931_t15 = 2;
    _931_t16 = $sub_int64_t(_931_n, _931_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _931_t14 = _931_t13(_931_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _931_t8 = _931_t7(_931_t10, _931_t14);
    $line_idx--;
    _931_t0 = _931_t8;
    goto BB5;
}

int64_t _936_add(int64_t _936_x,int64_t _936_y){
    int64_t _936_$retval;
    _936_$retval = $add_int64_t(_936_x, _936_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _936_$retval;
}

int main(void) {
  printf("%ld",_929_main());
  return 0;
}
