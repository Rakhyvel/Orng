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
int64_t _998_main(void);
int64_t _1000_fib(int64_t _1000_n);
int64_t _1006_add(int64_t _1006_x, int64_t _1006_y);


/* Function definitions */
int64_t _998_main(void){
    function0 _998_t0;
    int64_t _998_t2;
    int64_t _998_t1;
    int64_t _998_t3;
    int64_t _998_$retval;
    _998_t0 = (function0) _1000_fib;
    _998_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _998_t1 = _998_t0(_998_t2);
    $line_idx--;
    _998_t3 = 10;
    _998_$retval = $sub_int64_t(_998_t1, _998_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _998_$retval;
}

int64_t _1000_fib(int64_t _1000_n){
    int64_t _1000_t1;
    uint8_t _1000_t2;
    function1 _1000_t7;
    function0 _1000_t9;
    int64_t _1000_t11;
    int64_t _1000_t12;
    int64_t _1000_t10;
    function0 _1000_t13;
    int64_t _1000_t15;
    int64_t _1000_t16;
    int64_t _1000_t14;
    int64_t _1000_t8;
    int64_t _1000_t0;
    int64_t _1000_$retval;
    int64_t _1000_t3;
    uint8_t _1000_t4;
    goto BB1171;
BB1171:
    _1000_t1 = 0;
    _1000_t2 = _1000_n==_1000_t1;
    if (_1000_t2) {
        goto BB1173;
    } else {
        goto BB1176;
    }
BB1173:
    _1000_t0 = 0;
    goto BB1175;
BB1176:
    _1000_t3 = 1;
    _1000_t4 = _1000_n==_1000_t3;
    if (_1000_t4) {
        goto BB1178;
    } else {
        goto BB1180;
    }
BB1175:
    _1000_$retval = _1000_t0;
    return _1000_$retval;
BB1178:
    _1000_t0 = 1;
    goto BB1175;
BB1180:
    _1000_t7 = (function1) _1006_add;
    _1000_t9 = (function0) _1000_fib;
    _1000_t11 = 1;
    _1000_t12 = $sub_int64_t(_1000_n, _1000_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _1000_t10 = _1000_t9(_1000_t12);
    $line_idx--;
    _1000_t13 = (function0) _1000_fib;
    _1000_t15 = 2;
    _1000_t16 = $sub_int64_t(_1000_n, _1000_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _1000_t14 = _1000_t13(_1000_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _1000_t8 = _1000_t7(_1000_t10, _1000_t14);
    $line_idx--;
    _1000_t0 = _1000_t8;
    goto BB1175;
}

int64_t _1006_add(int64_t _1006_x, int64_t _1006_y){
    int64_t _1006_$retval;
    _1006_$retval = $add_int64_t(_1006_x, _1006_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1006_$retval;
}


int main(void) {
  printf("%ld",_998_main());
  return 0;
}
