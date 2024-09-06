/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1865_main(void);


/* Function definitions */
int64_t _1865_main(void){
    uint8_t _1866_found;
    int64_t _1867_n;
    int64_t _1865_t5;
    uint8_t _1865_t6;
    int64_t _1865_t14;
    int64_t _1865_t10;
    uint8_t _1865_t12;
    int64_t _1865_t16;
    int64_t _1865_$retval;
    _1866_found = 0;
    _1867_n = 0;
    goto BB2056;
BB2056:
    _1865_t5 = 10;
    _1865_t6 = _1867_n<_1865_t5;
    if (_1865_t6) {
        goto BB2057;
    } else {
        goto BB2072;
    }
BB2057:
    if (_1866_found) {
        goto BB2058;
    } else {
        goto BB2060;
    }
BB2072:
    if (_1866_found) {
        goto BB2073;
    } else {
        goto BB2077;
    }
BB2058:
    _1867_n = 100;
    goto BB2060;
BB2060:
    _1865_t10 = 6;
    _1865_t12 = _1867_n==_1865_t10;
    if (_1865_t12) {
        goto BB2063;
    } else {
        goto BB2067;
    }
BB2073:
    _1865_t16 = 15;
    goto BB2076;
BB2077:
    _1865_t16 = 4;
    goto BB2076;
BB2063:
    _1866_found = 1;
    goto BB2067;
BB2067:
    _1865_t14 = 1;
    _1867_n = $add_int64_t(_1867_n, _1865_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2056;
BB2076:
    _1865_$retval = _1865_t16;
    return _1865_$retval;
}


int main(void) {
  printf("%ld",_1865_main());
  return 0;
}
