/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1846_main(void);


/* Function definitions */
int64_t _1846_main(void){
    uint8_t _1847_found;
    int64_t _1848_n;
    int64_t _1846_t5;
    uint8_t _1846_t6;
    int64_t _1846_t14;
    int64_t _1846_t10;
    uint8_t _1846_t12;
    int64_t _1846_t16;
    int64_t _1846_$retval;
    _1847_found = 0;
    _1848_n = 0;
    goto BB2035;
BB2035:
    _1846_t5 = 10;
    _1846_t6 = _1848_n<_1846_t5;
    if (_1846_t6) {
        goto BB2036;
    } else {
        goto BB2051;
    }
BB2036:
    if (_1847_found) {
        goto BB2037;
    } else {
        goto BB2039;
    }
BB2051:
    if (_1847_found) {
        goto BB2052;
    } else {
        goto BB2056;
    }
BB2037:
    _1848_n = 100;
    goto BB2039;
BB2039:
    _1846_t10 = 6;
    _1846_t12 = _1848_n==_1846_t10;
    if (_1846_t12) {
        goto BB2042;
    } else {
        goto BB2046;
    }
BB2052:
    _1846_t16 = 15;
    goto BB2055;
BB2056:
    _1846_t16 = 4;
    goto BB2055;
BB2042:
    _1847_found = 1;
    goto BB2046;
BB2046:
    _1846_t14 = 1;
    _1848_n = $add_int64_t(_1848_n, _1846_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2035;
BB2055:
    _1846_$retval = _1846_t16;
    return _1846_$retval;
}


int main(void) {
  printf("%ld",_1846_main());
  return 0;
}
