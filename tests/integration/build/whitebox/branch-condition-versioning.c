/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1918_main(void);


/* Function definitions */
int64_t _1918_main(void){
    uint8_t _1919_found;
    int64_t _1920_n;
    int64_t _1918_t5;
    uint8_t _1918_t6;
    int64_t _1918_t14;
    int64_t _1918_t10;
    uint8_t _1918_t12;
    int64_t _1918_t16;
    int64_t _1918_$retval;
    _1919_found = 0;
    _1920_n = 0;
    goto BB2071;
BB2071:
    _1918_t5 = 10;
    _1918_t6 = _1920_n<_1918_t5;
    if (_1918_t6) {
        goto BB2072;
    } else {
        goto BB2087;
    }
BB2072:
    if (_1919_found) {
        goto BB2073;
    } else {
        goto BB2075;
    }
BB2087:
    if (_1919_found) {
        goto BB2088;
    } else {
        goto BB2092;
    }
BB2073:
    _1920_n = 100;
    goto BB2075;
BB2075:
    _1918_t10 = 6;
    _1918_t12 = _1920_n==_1918_t10;
    if (_1918_t12) {
        goto BB2078;
    } else {
        goto BB2082;
    }
BB2088:
    _1918_t16 = 15;
    goto BB2091;
BB2092:
    _1918_t16 = 4;
    goto BB2091;
BB2078:
    _1919_found = 1;
    goto BB2082;
BB2082:
    _1918_t14 = 1;
    _1920_n = $add_int64_t(_1920_n, _1918_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2071;
BB2091:
    _1918_$retval = _1918_t16;
    return _1918_$retval;
}


int main(void) {
  printf("%ld",_1918_main());
  return 0;
}
