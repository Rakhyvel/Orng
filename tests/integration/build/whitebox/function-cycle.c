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
int64_t _1931_main(void);
int64_t _1933_a(int64_t _1933_n);
int64_t _1935_b(int64_t _1935_n);
int64_t _1937_c(int64_t _1937_n);


/* Function definitions */
int64_t _1931_main(void){
    function0 _1931_t0;
    int64_t _1931_t2;
    int64_t _1931_t1;
    int64_t _1931_$retval;
    _1931_t0 = (function0) _1933_a;
    _1931_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1931_t1 = _1931_t0(_1931_t2);
    $line_idx--;
    _1931_$retval = _1931_t1;
    return _1931_$retval;
}

int64_t _1933_a(int64_t _1933_n){
    function0 _1933_t0;
    int64_t _1933_t1;
    int64_t _1933_$retval;
    _1933_t0 = (function0) _1935_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1933_t1 = _1933_t0(_1933_n);
    $line_idx--;
    _1933_$retval = _1933_t1;
    return _1933_$retval;
}

int64_t _1935_b(int64_t _1935_n){
    function0 _1935_t0;
    int64_t _1935_t1;
    int64_t _1935_$retval;
    _1935_t0 = (function0) _1937_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1935_t1 = _1935_t0(_1935_n);
    $line_idx--;
    _1935_$retval = _1935_t1;
    return _1935_$retval;
}

int64_t _1937_c(int64_t _1937_n){
    int64_t _1937_t1;
    uint8_t _1937_t3;
    function0 _1937_t5;
    int64_t _1937_t6;
    int64_t _1937_t0;
    int64_t _1937_$retval;
    _1937_t1 = 47;
    _1937_t3 = _1937_n==_1937_t1;
    if (_1937_t3) {
        goto BB2121;
    } else {
        goto BB2125;
    }
BB2121:
    _1937_t0 = 47;
    goto BB2124;
BB2125:
    _1937_t5 = (function0) _1933_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1937_t6 = _1937_t5(_1937_n);
    $line_idx--;
    _1937_t0 = _1937_t6;
    goto BB2124;
BB2124:
    _1937_$retval = _1937_t0;
    return _1937_$retval;
}


int main(void) {
  printf("%ld",_1931_main());
  return 0;
}
