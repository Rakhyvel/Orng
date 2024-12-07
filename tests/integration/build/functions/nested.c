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
int64_t _1004_main(void);
int64_t _1006_fib(int64_t _1006_n);
int64_t _1012_add(int64_t _1012_x, int64_t _1012_y);


/* Function definitions */
int64_t _1004_main(void){
    function0 _1004_t0;
    int64_t _1004_t2;
    int64_t _1004_t1;
    int64_t _1004_t3;
    int64_t _1004_$retval;
    _1004_t0 = (function0) _1006_fib;
    _1004_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1004_t1 = _1004_t0(_1004_t2);
    $line_idx--;
    _1004_t3 = 10;
    _1004_$retval = $sub_int64_t(_1004_t1, _1004_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _1004_$retval;
}

int64_t _1006_fib(int64_t _1006_n){
    int64_t _1006_t1;
    uint8_t _1006_t2;
    function1 _1006_t7;
    function0 _1006_t9;
    int64_t _1006_t11;
    int64_t _1006_t12;
    int64_t _1006_t10;
    function0 _1006_t13;
    int64_t _1006_t15;
    int64_t _1006_t16;
    int64_t _1006_t14;
    int64_t _1006_t8;
    int64_t _1006_t0;
    int64_t _1006_$retval;
    int64_t _1006_t3;
    uint8_t _1006_t4;
    goto BB1184;
BB1184:
    _1006_t1 = 0;
    _1006_t2 = _1006_n==_1006_t1;
    if (_1006_t2) {
        goto BB1186;
    } else {
        goto BB1189;
    }
BB1186:
    _1006_t0 = 0;
    goto BB1188;
BB1189:
    _1006_t3 = 1;
    _1006_t4 = _1006_n==_1006_t3;
    if (_1006_t4) {
        goto BB1191;
    } else {
        goto BB1193;
    }
BB1188:
    _1006_$retval = _1006_t0;
    return _1006_$retval;
BB1191:
    _1006_t0 = 1;
    goto BB1188;
BB1193:
    _1006_t7 = (function1) _1012_add;
    _1006_t9 = (function0) _1006_fib;
    _1006_t11 = 1;
    _1006_t12 = $sub_int64_t(_1006_n, _1006_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _1006_t10 = _1006_t9(_1006_t12);
    $line_idx--;
    _1006_t13 = (function0) _1006_fib;
    _1006_t15 = 2;
    _1006_t16 = $sub_int64_t(_1006_n, _1006_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _1006_t14 = _1006_t13(_1006_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _1006_t8 = _1006_t7(_1006_t10, _1006_t14);
    $line_idx--;
    _1006_t0 = _1006_t8;
    goto BB1188;
}

int64_t _1012_add(int64_t _1012_x, int64_t _1012_y){
    int64_t _1012_$retval;
    _1012_$retval = $add_int64_t(_1012_x, _1012_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1012_$retval;
}


int main(void) {
  printf("%ld",_1004_main());
  return 0;
}
