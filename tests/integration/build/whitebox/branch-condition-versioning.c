/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1907_main(void);


/* Function definitions */
int64_t _1907_main(void){
    uint8_t _1908_found;
    int64_t _1909_n;
    int64_t _1907_t5;
    uint8_t _1907_t6;
    int64_t _1907_t14;
    int64_t _1907_t10;
    uint8_t _1907_t12;
    int64_t _1907_t16;
    int64_t _1907_$retval;
    _1908_found = 0;
    _1909_n = 0;
    goto BB2064;
BB2064:
    _1907_t5 = 10;
    _1907_t6 = _1909_n<_1907_t5;
    if (_1907_t6) {
        goto BB2065;
    } else {
        goto BB2080;
    }
BB2065:
    if (_1908_found) {
        goto BB2066;
    } else {
        goto BB2068;
    }
BB2080:
    if (_1908_found) {
        goto BB2081;
    } else {
        goto BB2085;
    }
BB2066:
    _1909_n = 100;
    goto BB2068;
BB2068:
    _1907_t10 = 6;
    _1907_t12 = _1909_n==_1907_t10;
    if (_1907_t12) {
        goto BB2071;
    } else {
        goto BB2075;
    }
BB2081:
    _1907_t16 = 15;
    goto BB2084;
BB2085:
    _1907_t16 = 4;
    goto BB2084;
BB2071:
    _1908_found = 1;
    goto BB2075;
BB2075:
    _1907_t14 = 1;
    _1909_n = $add_int64_t(_1909_n, _1907_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2064;
BB2084:
    _1907_$retval = _1907_t16;
    return _1907_$retval;
}


int main(void) {
  printf("%ld",_1907_main());
  return 0;
}
