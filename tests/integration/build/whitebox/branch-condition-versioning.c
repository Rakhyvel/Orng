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
    goto BB2046;
BB2046:
    _1857_t5 = 10;
    _1857_t6 = _1859_n<_1857_t5;
    if (_1857_t6) {
        goto BB2047;
    } else {
        goto BB2062;
    }
BB2047:
    if (_1858_found) {
        goto BB2048;
    } else {
        goto BB2050;
    }
BB2062:
    if (_1858_found) {
        goto BB2063;
    } else {
        goto BB2067;
    }
BB2048:
    _1859_n = 100;
    goto BB2050;
BB2050:
    _1857_t10 = 6;
    _1857_t12 = _1859_n==_1857_t10;
    if (_1857_t12) {
        goto BB2053;
    } else {
        goto BB2057;
    }
BB2063:
    _1857_t16 = 15;
    goto BB2066;
BB2067:
    _1857_t16 = 4;
    goto BB2066;
BB2053:
    _1858_found = 1;
    goto BB2057;
BB2057:
    _1857_t14 = 1;
    _1859_n = $add_int64_t(_1859_n, _1857_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2046;
BB2066:
    _1857_$retval = _1857_t16;
    return _1857_$retval;
}


int main(void) {
  printf("%ld",_1857_main());
  return 0;
}
