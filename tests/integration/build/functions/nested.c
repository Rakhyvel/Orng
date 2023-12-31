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
int64_t _979_main(void);
int64_t _981_fib(int64_t _981_n);
int64_t _987_add(int64_t _987_x, int64_t _987_y);

/* Function definitions */
int64_t _979_main(void){
    function0 _979_t0;
    int64_t _979_t2;
    int64_t _979_t1;
    int64_t _979_t3;
    int64_t _979_$retval;
    _979_t0 = _981_fib;
    _979_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _979_t1 = _979_t0(_979_t2);
    $line_idx--;
    _979_t3 = 10;
    _979_$retval = $sub_int64_t(_979_t1, _979_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _979_$retval;
}

int64_t _981_fib(int64_t _981_n){
    function1 _981_t7;
    function0 _981_t9;
    int64_t _981_t11;
    int64_t _981_t12;
    int64_t _981_t10;
    function0 _981_t13;
    int64_t _981_t15;
    int64_t _981_t16;
    int64_t _981_t14;
    int64_t _981_t8;
    int64_t _981_t0;
    int64_t _981_t1;
    uint8_t _981_t2;
    int64_t _981_t3;
    uint8_t _981_t4;
    int64_t _981_$retval;
    _981_t1 = 0;
    _981_t2 = _981_n==_981_t1;
    if (_981_t2) {
        goto BB1197;
    } else {
        goto BB1200;
    }
BB1197:
    _981_t0 = 0;
    goto BB1199;
BB1200:
    _981_t3 = 1;
    _981_t4 = _981_n==_981_t3;
    if (_981_t4) {
        goto BB1202;
    } else {
        goto BB1204;
    }
BB1199:
    _981_$retval = _981_t0;
    return _981_$retval;
BB1202:
    _981_t0 = 1;
    goto BB1199;
BB1204:
    _981_t7 = _987_add;
    _981_t9 = _981_fib;
    _981_t11 = 1;
    _981_t12 = $sub_int64_t(_981_n, _981_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _981_t10 = _981_t9(_981_t12);
    $line_idx--;
    _981_t13 = _981_fib;
    _981_t15 = 2;
    _981_t16 = $sub_int64_t(_981_n, _981_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _981_t14 = _981_t13(_981_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _981_t8 = _981_t7(_981_t10, _981_t14);
    $line_idx--;
    _981_t0 = _981_t8;
    goto BB1199;
}

int64_t _987_add(int64_t _987_x, int64_t _987_y){
    int64_t _987_$retval;
    _987_$retval = $add_int64_t(_987_x, _987_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _987_$retval;
}

int main(void) {
  printf("%ld",_979_main());
  return 0;
}
