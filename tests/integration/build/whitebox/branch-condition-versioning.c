/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1912_main(void);


/* Function definitions */
int64_t _1912_main(void){
    uint8_t _1913_found;
    int64_t _1914_n;
    int64_t _1912_t5;
    uint8_t _1912_t6;
    int64_t _1912_t14;
    int64_t _1912_t10;
    uint8_t _1912_t12;
    int64_t _1912_t16;
    int64_t _1912_$retval;
    _1913_found = 0;
    _1914_n = 0;
    goto BB2068;
BB2068:
    _1912_t5 = 10;
    _1912_t6 = _1914_n<_1912_t5;
    if (_1912_t6) {
        goto BB2069;
    } else {
        goto BB2084;
    }
BB2069:
    if (_1913_found) {
        goto BB2070;
    } else {
        goto BB2072;
    }
BB2084:
    if (_1913_found) {
        goto BB2085;
    } else {
        goto BB2089;
    }
BB2070:
    _1914_n = 100;
    goto BB2072;
BB2072:
    _1912_t10 = 6;
    _1912_t12 = _1914_n==_1912_t10;
    if (_1912_t12) {
        goto BB2075;
    } else {
        goto BB2079;
    }
BB2085:
    _1912_t16 = 15;
    goto BB2088;
BB2089:
    _1912_t16 = 4;
    goto BB2088;
BB2075:
    _1913_found = 1;
    goto BB2079;
BB2079:
    _1912_t14 = 1;
    _1914_n = $add_int64_t(_1914_n, _1912_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2068;
BB2088:
    _1912_$retval = _1912_t16;
    return _1912_$retval;
}


int main(void) {
  printf("%ld",_1912_main());
  return 0;
}
