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
int64_t _996_main(void);
int64_t _998_fib(int64_t _998_n);
int64_t _1004_add(int64_t _1004_x, int64_t _1004_y);


/* Function definitions */
int64_t _996_main(void){
    function0 _996_t0;
    int64_t _996_t2;
    int64_t _996_t1;
    int64_t _996_t3;
    int64_t _996_$retval;
    _996_t0 = (function0) _998_fib;
    _996_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _996_t1 = _996_t0(_996_t2);
    $line_idx--;
    _996_t3 = 10;
    _996_$retval = $sub_int64_t(_996_t1, _996_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _996_$retval;
}

int64_t _998_fib(int64_t _998_n){
    int64_t _998_t1;
    uint8_t _998_t2;
    function1 _998_t7;
    function0 _998_t9;
    int64_t _998_t11;
    int64_t _998_t12;
    int64_t _998_t10;
    function0 _998_t13;
    int64_t _998_t15;
    int64_t _998_t16;
    int64_t _998_t14;
    int64_t _998_t8;
    int64_t _998_t0;
    int64_t _998_$retval;
    int64_t _998_t3;
    uint8_t _998_t4;
    goto BB1174;
BB1174:
    _998_t1 = 0;
    _998_t2 = _998_n==_998_t1;
    if (_998_t2) {
        goto BB1176;
    } else {
        goto BB1179;
    }
BB1176:
    _998_t0 = 0;
    goto BB1178;
BB1179:
    _998_t3 = 1;
    _998_t4 = _998_n==_998_t3;
    if (_998_t4) {
        goto BB1181;
    } else {
        goto BB1183;
    }
BB1178:
    _998_$retval = _998_t0;
    return _998_$retval;
BB1181:
    _998_t0 = 1;
    goto BB1178;
BB1183:
    _998_t7 = (function1) _1004_add;
    _998_t9 = (function0) _998_fib;
    _998_t11 = 1;
    _998_t12 = $sub_int64_t(_998_n, _998_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _998_t10 = _998_t9(_998_t12);
    $line_idx--;
    _998_t13 = (function0) _998_fib;
    _998_t15 = 2;
    _998_t16 = $sub_int64_t(_998_n, _998_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _998_t14 = _998_t13(_998_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _998_t8 = _998_t7(_998_t10, _998_t14);
    $line_idx--;
    _998_t0 = _998_t8;
    goto BB1178;
}

int64_t _1004_add(int64_t _1004_x, int64_t _1004_y){
    int64_t _1004_$retval;
    _1004_$retval = $add_int64_t(_1004_x, _1004_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1004_$retval;
}


int main(void) {
  printf("%ld",_996_main());
  return 0;
}
