/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1857_main(void);


/* Function definitions */
int64_t _1857_main(void){
    uint8_t _1858_found;
    int64_t _1859_n;
    int64_t _1857_t5;
    uint8_t _1857_t6;
    int64_t _1857_t14;
    int64_t _1857_t10;
    uint8_t _1857_t12;
    int64_t _1857_t16;
    int64_t _1857_$retval;
    _1858_found = 0;
    _1859_n = 0;
    goto BB2045;
BB2045:
    _1857_t5 = 10;
    _1857_t6 = _1859_n<_1857_t5;
    if (_1857_t6) {
        goto BB2046;
    } else {
        goto BB2061;
    }
BB2046:
    if (_1858_found) {
        goto BB2047;
    } else {
        goto BB2049;
    }
BB2061:
    if (_1858_found) {
        goto BB2062;
    } else {
        goto BB2066;
    }
BB2047:
    _1859_n = 100;
    goto BB2049;
BB2049:
    _1857_t10 = 6;
    _1857_t12 = _1859_n==_1857_t10;
    if (_1857_t12) {
        goto BB2052;
    } else {
        goto BB2056;
    }
BB2062:
    _1857_t16 = 15;
    goto BB2065;
BB2066:
    _1857_t16 = 4;
    goto BB2065;
BB2052:
    _1858_found = 1;
    goto BB2056;
BB2056:
    _1857_t14 = 1;
    _1859_n = $add_int64_t(_1859_n, _1857_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2045;
BB2065:
    _1857_$retval = _1857_t16;
    return _1857_$retval;
}


int main(void) {
  printf("%ld",_1857_main());
  return 0;
}
