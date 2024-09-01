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
int64_t _1880_main(void);
int64_t _1882_a(int64_t _1882_n);
int64_t _1884_b(int64_t _1884_n);
int64_t _1886_c(int64_t _1886_n);


/* Function definitions */
int64_t _1880_main(void){
    function0 _1880_t0;
    int64_t _1880_t2;
    int64_t _1880_t1;
    int64_t _1880_$retval;
    _1880_t0 = (function0) _1882_a;
    _1880_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1880_t1 = _1880_t0(_1880_t2);
    $line_idx--;
    _1880_$retval = _1880_t1;
    return _1880_$retval;
}

int64_t _1882_a(int64_t _1882_n){
    function0 _1882_t0;
    int64_t _1882_t1;
    int64_t _1882_$retval;
    _1882_t0 = (function0) _1884_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1882_t1 = _1882_t0(_1882_n);
    $line_idx--;
    _1882_$retval = _1882_t1;
    return _1882_$retval;
}

int64_t _1884_b(int64_t _1884_n){
    function0 _1884_t0;
    int64_t _1884_t1;
    int64_t _1884_$retval;
    _1884_t0 = (function0) _1886_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1884_t1 = _1884_t0(_1884_n);
    $line_idx--;
    _1884_$retval = _1884_t1;
    return _1884_$retval;
}

int64_t _1886_c(int64_t _1886_n){
    int64_t _1886_t1;
    uint8_t _1886_t3;
    function0 _1886_t5;
    int64_t _1886_t6;
    int64_t _1886_t0;
    int64_t _1886_$retval;
    _1886_t1 = 47;
    _1886_t3 = _1886_n==_1886_t1;
    if (_1886_t3) {
        goto BB2096;
    } else {
        goto BB2100;
    }
BB2096:
    _1886_t0 = 47;
    goto BB2099;
BB2100:
    _1886_t5 = (function0) _1882_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1886_t6 = _1886_t5(_1886_n);
    $line_idx--;
    _1886_t0 = _1886_t6;
    goto BB2099;
BB2099:
    _1886_$retval = _1886_t0;
    return _1886_$retval;
}


int main(void) {
  printf("%ld",_1880_main());
  return 0;
}
