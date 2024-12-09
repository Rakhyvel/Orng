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
int64_t _1009_main(void);
int64_t _1011_fib(int64_t _1011_n);
int64_t _1017_add(int64_t _1017_x, int64_t _1017_y);


/* Function definitions */
int64_t _1009_main(void){
    function0 _1009_t0;
    int64_t _1009_t2;
    int64_t _1009_t1;
    int64_t _1009_t3;
    int64_t _1009_$retval;
    _1009_t0 = (function0) _1011_fib;
    _1009_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _1009_t1 = _1009_t0(_1009_t2);
    $line_idx--;
    _1009_t3 = 10;
    _1009_$retval = $sub_int64_t(_1009_t1, _1009_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _1009_$retval;
}

int64_t _1011_fib(int64_t _1011_n){
    int64_t _1011_t1;
    uint8_t _1011_t2;
    function1 _1011_t7;
    function0 _1011_t9;
    int64_t _1011_t11;
    int64_t _1011_t12;
    int64_t _1011_t10;
    function0 _1011_t13;
    int64_t _1011_t15;
    int64_t _1011_t16;
    int64_t _1011_t14;
    int64_t _1011_t8;
    int64_t _1011_t0;
    int64_t _1011_$retval;
    int64_t _1011_t3;
    uint8_t _1011_t4;
    goto BB1187;
BB1187:
    _1011_t1 = 0;
    _1011_t2 = _1011_n==_1011_t1;
    if (_1011_t2) {
        goto BB1189;
    } else {
        goto BB1192;
    }
BB1189:
    _1011_t0 = 0;
    goto BB1191;
BB1192:
    _1011_t3 = 1;
    _1011_t4 = _1011_n==_1011_t3;
    if (_1011_t4) {
        goto BB1194;
    } else {
        goto BB1196;
    }
BB1191:
    _1011_$retval = _1011_t0;
    return _1011_$retval;
BB1194:
    _1011_t0 = 1;
    goto BB1191;
BB1196:
    _1011_t7 = (function1) _1017_add;
    _1011_t9 = (function0) _1011_fib;
    _1011_t11 = 1;
    _1011_t12 = $sub_int64_t(_1011_n, _1011_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _1011_t10 = _1011_t9(_1011_t12);
    $line_idx--;
    _1011_t13 = (function0) _1011_fib;
    _1011_t15 = 2;
    _1011_t16 = $sub_int64_t(_1011_n, _1011_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _1011_t14 = _1011_t13(_1011_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _1011_t8 = _1011_t7(_1011_t10, _1011_t14);
    $line_idx--;
    _1011_t0 = _1011_t8;
    goto BB1191;
}

int64_t _1017_add(int64_t _1017_x, int64_t _1017_y){
    int64_t _1017_$retval;
    _1017_$retval = $add_int64_t(_1017_x, _1017_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1017_$retval;
}


int main(void) {
  printf("%ld",_1009_main());
  return 0;
}
