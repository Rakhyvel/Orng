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
int64_t _39_main(void);
int64_t _41_a(int64_t _41_n);
int64_t _43_b(int64_t _43_n);
int64_t _45_c(int64_t _45_n);


/* Function definitions */
int64_t _39_main(void){
    function0 _39_t0;
    int64_t _39_t2;
    int64_t _39_t1;
    int64_t _39_$retval;
    _39_t0 = (function0) _41_a;
    _39_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _39_t1 = _39_t0(_39_t2);
    $line_idx--;
    _39_$retval = _39_t1;
    return _39_$retval;
}

int64_t _41_a(int64_t _41_n){
    function0 _41_t0;
    int64_t _41_t1;
    int64_t _41_$retval;
    _41_t0 = (function0) _43_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _41_t1 = _41_t0(_41_n);
    $line_idx--;
    _41_$retval = _41_t1;
    return _41_$retval;
}

int64_t _43_b(int64_t _43_n){
    function0 _43_t0;
    int64_t _43_t1;
    int64_t _43_$retval;
    _43_t0 = (function0) _45_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _43_t1 = _43_t0(_43_n);
    $line_idx--;
    _43_$retval = _43_t1;
    return _43_$retval;
}

int64_t _45_c(int64_t _45_n){
    int64_t _45_t1;
    uint8_t _45_t3;
    function0 _45_t5;
    int64_t _45_t6;
    int64_t _45_t0;
    int64_t _45_$retval;
    _45_t1 = 47;
    _45_t3 = _45_n==_45_t1;
    if (_45_t3) {
        goto BB64;
    } else {
        goto BB68;
    }
BB64:
    _45_t0 = 47;
    goto BB67;
BB68:
    _45_t5 = (function0) _41_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _45_t6 = _45_t5(_45_n);
    $line_idx--;
    _45_t0 = _45_t6;
    goto BB67;
BB67:
    _45_$retval = _45_t0;
    return _45_$retval;
}


int main(void) {
  printf("%ld",_39_main());
  return 0;
}
