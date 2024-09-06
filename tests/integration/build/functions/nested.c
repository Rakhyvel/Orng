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
int64_t _990_main(void);
int64_t _992_fib(int64_t _992_n);
int64_t _998_add(int64_t _998_x, int64_t _998_y);


/* Function definitions */
int64_t _990_main(void){
    function0 _990_t0;
    int64_t _990_t2;
    int64_t _990_t1;
    int64_t _990_t3;
    int64_t _990_$retval;
    _990_t0 = (function0) _992_fib;
    _990_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _990_t1 = _990_t0(_990_t2);
    $line_idx--;
    _990_t3 = 10;
    _990_$retval = $sub_int64_t(_990_t1, _990_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _990_$retval;
}

int64_t _992_fib(int64_t _992_n){
    int64_t _992_t1;
    uint8_t _992_t2;
    function1 _992_t7;
    function0 _992_t9;
    int64_t _992_t11;
    int64_t _992_t12;
    int64_t _992_t10;
    function0 _992_t13;
    int64_t _992_t15;
    int64_t _992_t16;
    int64_t _992_t14;
    int64_t _992_t8;
    int64_t _992_t0;
    int64_t _992_$retval;
    int64_t _992_t3;
    uint8_t _992_t4;
    goto BB1165;
BB1165:
    _992_t1 = 0;
    _992_t2 = _992_n==_992_t1;
    if (_992_t2) {
        goto BB1167;
    } else {
        goto BB1170;
    }
BB1167:
    _992_t0 = 0;
    goto BB1169;
BB1170:
    _992_t3 = 1;
    _992_t4 = _992_n==_992_t3;
    if (_992_t4) {
        goto BB1172;
    } else {
        goto BB1174;
    }
BB1169:
    _992_$retval = _992_t0;
    return _992_$retval;
BB1172:
    _992_t0 = 1;
    goto BB1169;
BB1174:
    _992_t7 = (function1) _998_add;
    _992_t9 = (function0) _992_fib;
    _992_t11 = 1;
    _992_t12 = $sub_int64_t(_992_n, _992_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _992_t10 = _992_t9(_992_t12);
    $line_idx--;
    _992_t13 = (function0) _992_fib;
    _992_t15 = 2;
    _992_t16 = $sub_int64_t(_992_n, _992_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _992_t14 = _992_t13(_992_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _992_t8 = _992_t7(_992_t10, _992_t14);
    $line_idx--;
    _992_t0 = _992_t8;
    goto BB1169;
}

int64_t _998_add(int64_t _998_x, int64_t _998_y){
    int64_t _998_$retval;
    _998_$retval = $add_int64_t(_998_x, _998_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _998_$retval;
}


int main(void) {
  printf("%ld",_990_main());
  return 0;
}
