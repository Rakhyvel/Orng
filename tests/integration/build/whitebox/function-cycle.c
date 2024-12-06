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
int64_t _1958_main(void);
int64_t _1960_a(int64_t _1960_n);
int64_t _1962_b(int64_t _1962_n);
int64_t _1964_c(int64_t _1964_n);


/* Function definitions */
int64_t _1958_main(void){
    function0 _1958_t0;
    int64_t _1958_t2;
    int64_t _1958_t1;
    int64_t _1958_$retval;
    _1958_t0 = (function0) _1960_a;
    _1958_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1958_t1 = _1958_t0(_1958_t2);
    $line_idx--;
    _1958_$retval = _1958_t1;
    return _1958_$retval;
}

int64_t _1960_a(int64_t _1960_n){
    function0 _1960_t0;
    int64_t _1960_t1;
    int64_t _1960_$retval;
    _1960_t0 = (function0) _1962_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1960_t1 = _1960_t0(_1960_n);
    $line_idx--;
    _1960_$retval = _1960_t1;
    return _1960_$retval;
}

int64_t _1962_b(int64_t _1962_n){
    function0 _1962_t0;
    int64_t _1962_t1;
    int64_t _1962_$retval;
    _1962_t0 = (function0) _1964_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1962_t1 = _1962_t0(_1962_n);
    $line_idx--;
    _1962_$retval = _1962_t1;
    return _1962_$retval;
}

int64_t _1964_c(int64_t _1964_n){
    int64_t _1964_t1;
    uint8_t _1964_t3;
    function0 _1964_t5;
    int64_t _1964_t6;
    int64_t _1964_t0;
    int64_t _1964_$retval;
    _1964_t1 = 47;
    _1964_t3 = _1964_n==_1964_t1;
    if (_1964_t3) {
        goto BB2141;
    } else {
        goto BB2145;
    }
BB2141:
    _1964_t0 = 47;
    goto BB2144;
BB2145:
    _1964_t5 = (function0) _1960_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1964_t6 = _1964_t5(_1964_n);
    $line_idx--;
    _1964_t0 = _1964_t6;
    goto BB2144;
BB2144:
    _1964_$retval = _1964_t0;
    return _1964_$retval;
}


int main(void) {
  printf("%ld",_1958_main());
  return 0;
}
