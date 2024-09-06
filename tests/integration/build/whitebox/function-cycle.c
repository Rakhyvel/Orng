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
int64_t _1906_main(void);
int64_t _1908_a(int64_t _1908_n);
int64_t _1910_b(int64_t _1910_n);
int64_t _1912_c(int64_t _1912_n);


/* Function definitions */
int64_t _1906_main(void){
    function0 _1906_t0;
    int64_t _1906_t2;
    int64_t _1906_t1;
    int64_t _1906_$retval;
    _1906_t0 = (function0) _1908_a;
    _1906_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1906_t1 = _1906_t0(_1906_t2);
    $line_idx--;
    _1906_$retval = _1906_t1;
    return _1906_$retval;
}

int64_t _1908_a(int64_t _1908_n){
    function0 _1908_t0;
    int64_t _1908_t1;
    int64_t _1908_$retval;
    _1908_t0 = (function0) _1910_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1908_t1 = _1908_t0(_1908_n);
    $line_idx--;
    _1908_$retval = _1908_t1;
    return _1908_$retval;
}

int64_t _1910_b(int64_t _1910_n){
    function0 _1910_t0;
    int64_t _1910_t1;
    int64_t _1910_$retval;
    _1910_t0 = (function0) _1912_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1910_t1 = _1910_t0(_1910_n);
    $line_idx--;
    _1910_$retval = _1910_t1;
    return _1910_$retval;
}

int64_t _1912_c(int64_t _1912_n){
    int64_t _1912_t1;
    uint8_t _1912_t3;
    function0 _1912_t5;
    int64_t _1912_t6;
    int64_t _1912_t0;
    int64_t _1912_$retval;
    _1912_t1 = 47;
    _1912_t3 = _1912_n==_1912_t1;
    if (_1912_t3) {
        goto BB2121;
    } else {
        goto BB2125;
    }
BB2121:
    _1912_t0 = 47;
    goto BB2124;
BB2125:
    _1912_t5 = (function0) _1908_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1912_t6 = _1912_t5(_1912_n);
    $line_idx--;
    _1912_t0 = _1912_t6;
    goto BB2124;
BB2124:
    _1912_$retval = _1912_t0;
    return _1912_$retval;
}


int main(void) {
  printf("%ld",_1906_main());
  return 0;
}
