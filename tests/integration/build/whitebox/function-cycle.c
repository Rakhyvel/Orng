/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1988_main(void);
int64_t _1990_a(int64_t _1990_n);
int64_t _1992_b(int64_t _1992_n);
int64_t _1994_c(int64_t _1994_n);


/* Function definitions */
int64_t _1988_main(void){
    function0 _1988_t0;
    int64_t _1988_t2;
    int64_t _1988_t1;
    int64_t _1988_$retval;
    _1988_t0 = (function0) _1990_a;
    _1988_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1988_t1 = _1988_t0(_1988_t2);
    $line_idx--;
    _1988_$retval = _1988_t1;
    return _1988_$retval;
}

int64_t _1990_a(int64_t _1990_n){
    function0 _1990_t0;
    int64_t _1990_t1;
    int64_t _1990_$retval;
    _1990_t0 = (function0) _1992_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1990_t1 = _1990_t0(_1990_n);
    $line_idx--;
    _1990_$retval = _1990_t1;
    return _1990_$retval;
}

int64_t _1992_b(int64_t _1992_n){
    function0 _1992_t0;
    int64_t _1992_t1;
    int64_t _1992_$retval;
    _1992_t0 = (function0) _1994_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1992_t1 = _1992_t0(_1992_n);
    $line_idx--;
    _1992_$retval = _1992_t1;
    return _1992_$retval;
}

int64_t _1994_c(int64_t _1994_n){
    int64_t _1994_t1;
    uint8_t _1994_t3;
    function0 _1994_t5;
    int64_t _1994_t6;
    int64_t _1994_t0;
    int64_t _1994_$retval;
    _1994_t1 = 47;
    _1994_t3 = _1994_n==_1994_t1;
    if (_1994_t3) {
        goto BB2172;
    } else {
        goto BB2176;
    }
BB2172:
    _1994_t0 = 47;
    goto BB2175;
BB2176:
    _1994_t5 = (function0) _1990_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1994_t6 = _1994_t5(_1994_n);
    $line_idx--;
    _1994_t0 = _1994_t6;
    goto BB2175;
BB2175:
    _1994_$retval = _1994_t0;
    return _1994_$retval;
}


int main(void) {
  printf("%ld",_1988_main());
  return 0;
}
