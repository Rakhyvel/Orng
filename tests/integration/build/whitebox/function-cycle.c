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
int64_t _1941_main(void);
int64_t _1943_a(int64_t _1943_n);
int64_t _1945_b(int64_t _1945_n);
int64_t _1947_c(int64_t _1947_n);


/* Function definitions */
int64_t _1941_main(void){
    function0 _1941_t0;
    int64_t _1941_t2;
    int64_t _1941_t1;
    int64_t _1941_$retval;
    _1941_t0 = (function0) _1943_a;
    _1941_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1941_t1 = _1941_t0(_1941_t2);
    $line_idx--;
    _1941_$retval = _1941_t1;
    return _1941_$retval;
}

int64_t _1943_a(int64_t _1943_n){
    function0 _1943_t0;
    int64_t _1943_t1;
    int64_t _1943_$retval;
    _1943_t0 = (function0) _1945_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1943_t1 = _1943_t0(_1943_n);
    $line_idx--;
    _1943_$retval = _1943_t1;
    return _1943_$retval;
}

int64_t _1945_b(int64_t _1945_n){
    function0 _1945_t0;
    int64_t _1945_t1;
    int64_t _1945_$retval;
    _1945_t0 = (function0) _1947_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1945_t1 = _1945_t0(_1945_n);
    $line_idx--;
    _1945_$retval = _1945_t1;
    return _1945_$retval;
}

int64_t _1947_c(int64_t _1947_n){
    int64_t _1947_t1;
    uint8_t _1947_t3;
    function0 _1947_t5;
    int64_t _1947_t6;
    int64_t _1947_t0;
    int64_t _1947_$retval;
    _1947_t1 = 47;
    _1947_t3 = _1947_n==_1947_t1;
    if (_1947_t3) {
        goto BB2125;
    } else {
        goto BB2129;
    }
BB2125:
    _1947_t0 = 47;
    goto BB2128;
BB2129:
    _1947_t5 = (function0) _1943_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1947_t6 = _1947_t5(_1947_n);
    $line_idx--;
    _1947_t0 = _1947_t6;
    goto BB2128;
BB2128:
    _1947_$retval = _1947_t0;
    return _1947_$retval;
}


int main(void) {
  printf("%ld",_1941_main());
  return 0;
}
