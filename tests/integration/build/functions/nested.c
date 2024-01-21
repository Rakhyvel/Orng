/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct2;

/* Typedefs */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _997_main(void);
int64_t _999_fib(int64_t _999_n);
int64_t _1005_add(int64_t _1005_x, int64_t _1005_y);

/* Function definitions */
int64_t _997_main(void){
    function0 _997_t0;
    int64_t _997_t2;
    int64_t _997_t1;
    int64_t _997_t3;
    int64_t _997_$retval;
    _997_t0 = _999_fib;
    _997_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _997_t1 = _997_t0(_997_t2);
    $line_idx--;
    _997_t3 = 10;
    _997_$retval = $sub_int64_t(_997_t1, _997_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _997_$retval;
}

int64_t _999_fib(int64_t _999_n){
    function1 _999_t7;
    function0 _999_t9;
    int64_t _999_t11;
    int64_t _999_t12;
    int64_t _999_t10;
    function0 _999_t13;
    int64_t _999_t15;
    int64_t _999_t16;
    int64_t _999_t14;
    int64_t _999_t8;
    int64_t _999_t0;
    int64_t _999_t1;
    uint8_t _999_t2;
    int64_t _999_t3;
    uint8_t _999_t4;
    int64_t _999_$retval;
    _999_t1 = 0;
    _999_t2 = _999_n==_999_t1;
    if (_999_t2) {
        goto BB1205;
    } else {
        goto BB1208;
    }
BB1205:
    _999_t0 = 0;
    goto BB1207;
BB1208:
    _999_t3 = 1;
    _999_t4 = _999_n==_999_t3;
    if (_999_t4) {
        goto BB1210;
    } else {
        goto BB1212;
    }
BB1207:
    _999_$retval = _999_t0;
    return _999_$retval;
BB1210:
    _999_t0 = 1;
    goto BB1207;
BB1212:
    _999_t7 = _1005_add;
    _999_t9 = _999_fib;
    _999_t11 = 1;
    _999_t12 = $sub_int64_t(_999_n, _999_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _999_t10 = _999_t9(_999_t12);
    $line_idx--;
    _999_t13 = _999_fib;
    _999_t15 = 2;
    _999_t16 = $sub_int64_t(_999_n, _999_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _999_t14 = _999_t13(_999_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _999_t8 = _999_t7(_999_t10, _999_t14);
    $line_idx--;
    _999_t0 = _999_t8;
    goto BB1207;
}

int64_t _1005_add(int64_t _1005_x, int64_t _1005_y){
    int64_t _1005_$retval;
    _1005_$retval = $add_int64_t(_1005_x, _1005_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1005_$retval;
}

int main(void) {
  printf("%ld",_997_main());
  return 0;
}
