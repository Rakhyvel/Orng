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
int64_t _967_main(void);
int64_t _969_fib(int64_t _969_n);
int64_t _974_add(int64_t _974_x,int64_t _974_y);

/* Function definitions */
int64_t _967_main(void){
    function0 _967_t0;
    int64_t _967_t2;
    int64_t _967_t1;
    int64_t _967_t3;
    int64_t _967_$retval;
    _967_t0 = _969_fib;
    _967_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _967_t1 = _967_t0(_967_t2);
    $line_idx--;
    _967_t3 = 10;
    _967_$retval = $sub_int64_t(_967_t1, _967_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _967_$retval;
}

int64_t _969_fib(int64_t _969_n){
    function1 _969_t7;
    function0 _969_t9;
    int64_t _969_t11;
    int64_t _969_t12;
    int64_t _969_t10;
    function0 _969_t13;
    int64_t _969_t15;
    int64_t _969_t16;
    int64_t _969_t14;
    int64_t _969_t8;
    int64_t _969_t0;
    int64_t _969_t1;
    uint8_t _969_t2;
    int64_t _969_t3;
    uint8_t _969_t4;
    int64_t _969_$retval;
    _969_t1 = 0;
    _969_t2 = _969_n == _969_t1;
    if (_969_t2) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _969_t0 = 0;
    goto BB5;
BB6:
    _969_t3 = 1;
    _969_t4 = _969_n == _969_t3;
    if (_969_t4) {
        goto BB8;
    } else {
        goto BB10;
    }
BB5:
    _969_$retval = _969_t0;
    return _969_$retval;
BB8:
    _969_t0 = 1;
    goto BB5;
BB10:
    _969_t7 = _974_add;
    _969_t9 = _969_fib;
    _969_t11 = 1;
    _969_t12 = $sub_int64_t(_969_n, _969_t11, "tests/integration/functions/nested.orng:8:32:\n            else => add(fib(n - 1), fib(n - 2))\n                              ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:29:\n            else => add(fib(n - 1), fib(n - 2))\n                           ^";
    _969_t10 = _969_t9(_969_t12);
    $line_idx--;
    _969_t13 = _969_fib;
    _969_t15 = 2;
    _969_t16 = $sub_int64_t(_969_n, _969_t15, "tests/integration/functions/nested.orng:8:44:\n            else => add(fib(n - 1), fib(n - 2))\n                                          ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:41:\n            else => add(fib(n - 1), fib(n - 2))\n                                       ^";
    _969_t14 = _969_t13(_969_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:25:\n            else => add(fib(n - 1), fib(n - 2))\n                       ^";
    _969_t8 = _969_t7(_969_t10, _969_t14);
    $line_idx--;
    _969_t0 = _969_t8;
    goto BB5;
}

int64_t _974_add(int64_t _974_x,int64_t _974_y){
    int64_t _974_$retval;
    _974_$retval = $add_int64_t(_974_x, _974_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _974_$retval;
}

int main(void) {
  printf("%ld",_967_main());
  return 0;
}
