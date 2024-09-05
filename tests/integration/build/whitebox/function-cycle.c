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
int64_t _1891_main(void);
int64_t _1893_a(int64_t _1893_n);
int64_t _1895_b(int64_t _1895_n);
int64_t _1897_c(int64_t _1897_n);


/* Function definitions */
int64_t _1891_main(void){
    function0 _1891_t0;
    int64_t _1891_t2;
    int64_t _1891_t1;
    int64_t _1891_$retval;
    _1891_t0 = (function0) _1893_a;
    _1891_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1891_t1 = _1891_t0(_1891_t2);
    $line_idx--;
    _1891_$retval = _1891_t1;
    return _1891_$retval;
}

int64_t _1893_a(int64_t _1893_n){
    function0 _1893_t0;
    int64_t _1893_t1;
    int64_t _1893_$retval;
    _1893_t0 = (function0) _1895_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1893_t1 = _1893_t0(_1893_n);
    $line_idx--;
    _1893_$retval = _1893_t1;
    return _1893_$retval;
}

int64_t _1895_b(int64_t _1895_n){
    function0 _1895_t0;
    int64_t _1895_t1;
    int64_t _1895_$retval;
    _1895_t0 = (function0) _1897_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1895_t1 = _1895_t0(_1895_n);
    $line_idx--;
    _1895_$retval = _1895_t1;
    return _1895_$retval;
}

int64_t _1897_c(int64_t _1897_n){
    int64_t _1897_t1;
    uint8_t _1897_t3;
    function0 _1897_t5;
    int64_t _1897_t6;
    int64_t _1897_t0;
    int64_t _1897_$retval;
    _1897_t1 = 47;
    _1897_t3 = _1897_n==_1897_t1;
    if (_1897_t3) {
        goto BB2106;
    } else {
        goto BB2110;
    }
BB2106:
    _1897_t0 = 47;
    goto BB2109;
BB2110:
    _1897_t5 = (function0) _1893_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1897_t6 = _1897_t5(_1897_n);
    $line_idx--;
    _1897_t0 = _1897_t6;
    goto BB2109;
BB2109:
    _1897_$retval = _1897_t0;
    return _1897_$retval;
}


int main(void) {
  printf("%ld",_1891_main());
  return 0;
}
