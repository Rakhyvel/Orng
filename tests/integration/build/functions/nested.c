/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct2;

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _1024_main(void);
int64_t _1026_fib(int64_t _1026_n);
int64_t _1032_add(int64_t _1032_x, int64_t _1032_y);


/* Function definitions */
int64_t _1024_main(void){
    function0 _1024_t0;
    int64_t _1024_t2;
    int64_t _1024_t1;
    int64_t _1024_t3;
    int64_t _1024_$retval;
    _1024_t0 = (function0) _1026_fib;
    _1024_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1024_t1 = _1024_t0(_1024_t2);
    $line_idx--;
    _1024_t3 = 10;
    _1024_$retval = $sub_int64_t(_1024_t1, _1024_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _1024_$retval;
}

int64_t _1026_fib(int64_t _1026_n){
    function1 _1026_t7;
    function0 _1026_t9;
    int64_t _1026_t11;
    int64_t _1026_t12;
    int64_t _1026_t10;
    function0 _1026_t13;
    int64_t _1026_t15;
    int64_t _1026_t16;
    int64_t _1026_t14;
    int64_t _1026_t8;
    int64_t _1026_t0;
    int64_t _1026_t1;
    uint8_t _1026_t2;
    int64_t _1026_t3;
    uint8_t _1026_t4;
    int64_t _1026_$retval;
    _1026_t1 = 0;
    _1026_t2 = _1026_n==_1026_t1;
    if (_1026_t2) {
        goto BB1220;
    } else {
        goto BB1223;
    }
BB1220:
    _1026_t0 = 0;
    goto BB1222;
BB1223:
    _1026_t3 = 1;
    _1026_t4 = _1026_n==_1026_t3;
    if (_1026_t4) {
        goto BB1225;
    } else {
        goto BB1227;
    }
BB1222:
    _1026_$retval = _1026_t0;
    return _1026_$retval;
BB1225:
    _1026_t0 = 1;
    goto BB1222;
BB1227:
    _1026_t7 = (function1) _1032_add;
    _1026_t9 = (function0) _1026_fib;
    _1026_t11 = 1;
    _1026_t12 = $sub_int64_t(_1026_n, _1026_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _1026_t10 = _1026_t9(_1026_t12);
    $line_idx--;
    _1026_t13 = (function0) _1026_fib;
    _1026_t15 = 2;
    _1026_t16 = $sub_int64_t(_1026_n, _1026_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _1026_t14 = _1026_t13(_1026_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _1026_t8 = _1026_t7(_1026_t10, _1026_t14);
    $line_idx--;
    _1026_t0 = _1026_t8;
    goto BB1222;
}

int64_t _1032_add(int64_t _1032_x, int64_t _1032_y){
    int64_t _1032_$retval;
    _1032_$retval = $add_int64_t(_1032_x, _1032_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1032_$retval;
}


int main(void) {
  printf("%ld",_1024_main());
  return 0;
}
