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
int64_t _1936_main(void);
int64_t _1938_a(int64_t _1938_n);
int64_t _1940_b(int64_t _1940_n);
int64_t _1942_c(int64_t _1942_n);


/* Function definitions */
int64_t _1936_main(void){
    function0 _1936_t0;
    int64_t _1936_t2;
    int64_t _1936_t1;
    int64_t _1936_$retval;
    _1936_t0 = (function0) _1938_a;
    _1936_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1936_t1 = _1936_t0(_1936_t2);
    $line_idx--;
    _1936_$retval = _1936_t1;
    return _1936_$retval;
}

int64_t _1938_a(int64_t _1938_n){
    function0 _1938_t0;
    int64_t _1938_t1;
    int64_t _1938_$retval;
    _1938_t0 = (function0) _1940_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1938_t1 = _1938_t0(_1938_n);
    $line_idx--;
    _1938_$retval = _1938_t1;
    return _1938_$retval;
}

int64_t _1940_b(int64_t _1940_n){
    function0 _1940_t0;
    int64_t _1940_t1;
    int64_t _1940_$retval;
    _1940_t0 = (function0) _1942_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1940_t1 = _1940_t0(_1940_n);
    $line_idx--;
    _1940_$retval = _1940_t1;
    return _1940_$retval;
}

int64_t _1942_c(int64_t _1942_n){
    int64_t _1942_t1;
    uint8_t _1942_t3;
    function0 _1942_t5;
    int64_t _1942_t6;
    int64_t _1942_t0;
    int64_t _1942_$retval;
    _1942_t1 = 47;
    _1942_t3 = _1942_n==_1942_t1;
    if (_1942_t3) {
        goto BB2121;
    } else {
        goto BB2125;
    }
BB2121:
    _1942_t0 = 47;
    goto BB2124;
BB2125:
    _1942_t5 = (function0) _1938_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1942_t6 = _1942_t5(_1942_n);
    $line_idx--;
    _1942_t0 = _1942_t6;
    goto BB2124;
BB2124:
    _1942_$retval = _1942_t0;
    return _1942_$retval;
}


int main(void) {
  printf("%ld",_1936_main());
  return 0;
}
