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
int64_t _1952_main(void);
int64_t _1954_a(int64_t _1954_n);
int64_t _1956_b(int64_t _1956_n);
int64_t _1958_c(int64_t _1958_n);


/* Function definitions */
int64_t _1952_main(void){
    function0 _1952_t0;
    int64_t _1952_t2;
    int64_t _1952_t1;
    int64_t _1952_$retval;
    _1952_t0 = (function0) _1954_a;
    _1952_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1952_t1 = _1952_t0(_1952_t2);
    $line_idx--;
    _1952_$retval = _1952_t1;
    return _1952_$retval;
}

int64_t _1954_a(int64_t _1954_n){
    function0 _1954_t0;
    int64_t _1954_t1;
    int64_t _1954_$retval;
    _1954_t0 = (function0) _1956_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1954_t1 = _1954_t0(_1954_n);
    $line_idx--;
    _1954_$retval = _1954_t1;
    return _1954_$retval;
}

int64_t _1956_b(int64_t _1956_n){
    function0 _1956_t0;
    int64_t _1956_t1;
    int64_t _1956_$retval;
    _1956_t0 = (function0) _1958_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1956_t1 = _1956_t0(_1956_n);
    $line_idx--;
    _1956_$retval = _1956_t1;
    return _1956_$retval;
}

int64_t _1958_c(int64_t _1958_n){
    int64_t _1958_t1;
    uint8_t _1958_t3;
    function0 _1958_t5;
    int64_t _1958_t6;
    int64_t _1958_t0;
    int64_t _1958_$retval;
    _1958_t1 = 47;
    _1958_t3 = _1958_n==_1958_t1;
    if (_1958_t3) {
        goto BB2132;
    } else {
        goto BB2136;
    }
BB2132:
    _1958_t0 = 47;
    goto BB2135;
BB2136:
    _1958_t5 = (function0) _1954_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1958_t6 = _1958_t5(_1958_n);
    $line_idx--;
    _1958_t0 = _1958_t6;
    goto BB2135;
BB2135:
    _1958_$retval = _1958_t0;
    return _1958_$retval;
}


int main(void) {
  printf("%ld",_1952_main());
  return 0;
}
