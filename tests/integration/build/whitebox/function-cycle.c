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
int64_t _1966_main(void);
int64_t _1968_a(int64_t _1968_n);
int64_t _1970_b(int64_t _1970_n);
int64_t _1972_c(int64_t _1972_n);


/* Function definitions */
int64_t _1966_main(void){
    function0 _1966_t0;
    int64_t _1966_t2;
    int64_t _1966_t1;
    int64_t _1966_$retval;
    _1966_t0 = (function0) _1968_a;
    _1966_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1966_t1 = _1966_t0(_1966_t2);
    $line_idx--;
    _1966_$retval = _1966_t1;
    return _1966_$retval;
}

int64_t _1968_a(int64_t _1968_n){
    function0 _1968_t0;
    int64_t _1968_t1;
    int64_t _1968_$retval;
    _1968_t0 = (function0) _1970_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1968_t1 = _1968_t0(_1968_n);
    $line_idx--;
    _1968_$retval = _1968_t1;
    return _1968_$retval;
}

int64_t _1970_b(int64_t _1970_n){
    function0 _1970_t0;
    int64_t _1970_t1;
    int64_t _1970_$retval;
    _1970_t0 = (function0) _1972_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1970_t1 = _1970_t0(_1970_n);
    $line_idx--;
    _1970_$retval = _1970_t1;
    return _1970_$retval;
}

int64_t _1972_c(int64_t _1972_n){
    int64_t _1972_t1;
    uint8_t _1972_t3;
    function0 _1972_t5;
    int64_t _1972_t6;
    int64_t _1972_t0;
    int64_t _1972_$retval;
    _1972_t1 = 47;
    _1972_t3 = _1972_n==_1972_t1;
    if (_1972_t3) {
        goto BB2151;
    } else {
        goto BB2155;
    }
BB2151:
    _1972_t0 = 47;
    goto BB2154;
BB2155:
    _1972_t5 = (function0) _1968_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1972_t6 = _1972_t5(_1972_n);
    $line_idx--;
    _1972_t0 = _1972_t6;
    goto BB2154;
BB2154:
    _1972_$retval = _1972_t0;
    return _1972_$retval;
}


int main(void) {
  printf("%ld",_1966_main());
  return 0;
}
