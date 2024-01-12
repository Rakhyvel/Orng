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
int64_t _992_main(void);
int64_t _994_fib(int64_t _994_n);
int64_t _1000_add(int64_t _1000_x, int64_t _1000_y);

/* Function definitions */
int64_t _992_main(void){
    function0 _992_t0;
    int64_t _992_t2;
    int64_t _992_t1;
    int64_t _992_t3;
    int64_t _992_$retval;
    _992_t0 = _994_fib;
    _992_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _992_t1 = _992_t0(_992_t2);
    $line_idx--;
    _992_t3 = 10;
    _992_$retval = $sub_int64_t(_992_t1, _992_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _992_$retval;
}

int64_t _994_fib(int64_t _994_n){
    function1 _994_t7;
    function0 _994_t9;
    int64_t _994_t11;
    int64_t _994_t12;
    int64_t _994_t10;
    function0 _994_t13;
    int64_t _994_t15;
    int64_t _994_t16;
    int64_t _994_t14;
    int64_t _994_t8;
    int64_t _994_t0;
    int64_t _994_t1;
    uint8_t _994_t2;
    int64_t _994_t3;
    uint8_t _994_t4;
    int64_t _994_$retval;
    _994_t1 = 0;
    _994_t2 = _994_n==_994_t1;
    if (_994_t2) {
        goto BB1201;
    } else {
        goto BB1204;
    }
BB1201:
    _994_t0 = 0;
    goto BB1203;
BB1204:
    _994_t3 = 1;
    _994_t4 = _994_n==_994_t3;
    if (_994_t4) {
        goto BB1206;
    } else {
        goto BB1208;
    }
BB1203:
    _994_$retval = _994_t0;
    return _994_$retval;
BB1206:
    _994_t0 = 1;
    goto BB1203;
BB1208:
    _994_t7 = _1000_add;
    _994_t9 = _994_fib;
    _994_t11 = 1;
    _994_t12 = $sub_int64_t(_994_n, _994_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _994_t10 = _994_t9(_994_t12);
    $line_idx--;
    _994_t13 = _994_fib;
    _994_t15 = 2;
    _994_t16 = $sub_int64_t(_994_n, _994_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _994_t14 = _994_t13(_994_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _994_t8 = _994_t7(_994_t10, _994_t14);
    $line_idx--;
    _994_t0 = _994_t8;
    goto BB1203;
}

int64_t _1000_add(int64_t _1000_x, int64_t _1000_y){
    int64_t _1000_$retval;
    _1000_$retval = $add_int64_t(_1000_x, _1000_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _1000_$retval;
}

int main(void) {
  printf("%ld",_992_main());
  return 0;
}
