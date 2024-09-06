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
int64_t _1899_main(void);
int64_t _1901_a(int64_t _1901_n);
int64_t _1903_b(int64_t _1903_n);
int64_t _1905_c(int64_t _1905_n);


/* Function definitions */
int64_t _1899_main(void){
    function0 _1899_t0;
    int64_t _1899_t2;
    int64_t _1899_t1;
    int64_t _1899_$retval;
    _1899_t0 = (function0) _1901_a;
    _1899_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1899_t1 = _1899_t0(_1899_t2);
    $line_idx--;
    _1899_$retval = _1899_t1;
    return _1899_$retval;
}

int64_t _1901_a(int64_t _1901_n){
    function0 _1901_t0;
    int64_t _1901_t1;
    int64_t _1901_$retval;
    _1901_t0 = (function0) _1903_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1901_t1 = _1901_t0(_1901_n);
    $line_idx--;
    _1901_$retval = _1901_t1;
    return _1901_$retval;
}

int64_t _1903_b(int64_t _1903_n){
    function0 _1903_t0;
    int64_t _1903_t1;
    int64_t _1903_$retval;
    _1903_t0 = (function0) _1905_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1903_t1 = _1903_t0(_1903_n);
    $line_idx--;
    _1903_$retval = _1903_t1;
    return _1903_$retval;
}

int64_t _1905_c(int64_t _1905_n){
    int64_t _1905_t1;
    uint8_t _1905_t3;
    function0 _1905_t5;
    int64_t _1905_t6;
    int64_t _1905_t0;
    int64_t _1905_$retval;
    _1905_t1 = 47;
    _1905_t3 = _1905_n==_1905_t1;
    if (_1905_t3) {
        goto BB2117;
    } else {
        goto BB2121;
    }
BB2117:
    _1905_t0 = 47;
    goto BB2120;
BB2121:
    _1905_t5 = (function0) _1901_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1905_t6 = _1905_t5(_1905_n);
    $line_idx--;
    _1905_t0 = _1905_t6;
    goto BB2120;
BB2120:
    _1905_$retval = _1905_t0;
    return _1905_$retval;
}


int main(void) {
  printf("%ld",_1899_main());
  return 0;
}
