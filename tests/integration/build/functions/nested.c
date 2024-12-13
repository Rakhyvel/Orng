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
int64_t _1026_main(void);
int64_t _1028_fib(int64_t _1028_n);
int64_t _1034_add(int64_t _1034_x, int64_t _1034_y);


/* Function definitions */
int64_t _1026_main(void){
    function0 _1026_t0;
    int64_t _1026_t2;
    int64_t _1026_t1;
    int64_t _1026_t3;
    int64_t _1026_$retval;
    _1026_t0 = (function0) _1028_fib;
    _1026_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1026_t1 = _1026_t0(_1026_t2);
    $line_idx--;
    _1026_t3 = 10;
    _1026_$retval = $sub_int64_t(_1026_t1, _1026_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _1026_$retval;
}

int64_t _1028_fib(int64_t _1028_n){
    int64_t _1028_t1;
    uint8_t _1028_t2;
    function1 _1028_t7;
    function0 _1028_t9;
    int64_t _1028_t11;
    int64_t _1028_t12;
    int64_t _1028_t10;
    function0 _1028_t13;
    int64_t _1028_t15;
    int64_t _1028_t16;
    int64_t _1028_t14;
    int64_t _1028_t8;
    int64_t _1028_t0;
    int64_t _1028_$retval;
    int64_t _1028_t3;
    uint8_t _1028_t4;
    goto BB1205;
BB1205:
    _1028_t1 = 0;
    _1028_t2 = _1028_n==_1028_t1;
    if (_1028_t2) {
        goto BB1207;
    } else {
        goto BB1210;
    }
BB1207:
    _1028_t0 = 0;
    goto BB1209;
BB1210:
    _1028_t3 = 1;
    _1028_t4 = _1028_n==_1028_t3;
    if (_1028_t4) {
        goto BB1212;
    } else {
        goto BB1214;
    }
BB1209:
    _1028_$retval = _1028_t0;
    return _1028_$retval;
BB1212:
    _1028_t0 = 1;
    goto BB1209;
BB1214:
    _1028_t7 = (function1) _1034_add;
    _1028_t9 = (function0) _1028_fib;
    _1028_t11 = 1;
    _1028_t12 = $sub_int64_t(_1028_n, _1028_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _1028_t10 = _1028_t9(_1028_t12);
    $line_idx--;
    _1028_t13 = (function0) _1028_fib;
    _1028_t15 = 2;
    _1028_t16 = $sub_int64_t(_1028_n, _1028_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _1028_t14 = _1028_t13(_1028_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _1028_t8 = _1028_t7(_1028_t10, _1028_t14);
    $line_idx--;
    _1028_t0 = _1028_t8;
    goto BB1209;
}

int64_t _1034_add(int64_t _1034_x, int64_t _1034_y){
    int64_t _1034_$retval;
    _1034_$retval = $add_int64_t(_1034_x, _1034_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1034_$retval;
}


int main(void) {
  printf("%ld",_1026_main());
  return 0;
}
