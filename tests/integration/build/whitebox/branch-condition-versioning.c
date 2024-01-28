/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1711_main(void);


/* Function definitions */
int64_t _1711_main(void){
    uint8_t _1712_found;
    int64_t _1713_n;
    int64_t _1711_t3;
    uint8_t _1711_t4;
    int64_t _1711_t12;
    int64_t _1711_t8;
    uint8_t _1711_t10;
    int64_t _1711_t14;
    int64_t _1711_$retval;
    _1712_found = 0;
    _1713_n = 0;
    goto BB1943;
BB1943:
    _1711_t3 = 10;
    _1711_t4 = _1713_n<_1711_t3;
    if (_1711_t4) {
        goto BB1944;
    } else {
        goto BB1959;
    }
BB1944:
    if (_1712_found) {
        goto BB1945;
    } else {
        goto BB1947;
    }
BB1959:
    if (_1712_found) {
        goto BB1960;
    } else {
        goto BB1964;
    }
BB1945:
    _1713_n = 100;
    goto BB1947;
BB1947:
    _1711_t8 = 6;
    _1711_t10 = _1713_n==_1711_t8;
    if (_1711_t10) {
        goto BB1950;
    } else {
        goto BB1954;
    }
BB1960:
    _1711_t14 = 15;
    goto BB1963;
BB1964:
    _1711_t14 = 4;
    goto BB1963;
BB1950:
    _1712_found = 1;
    goto BB1954;
BB1954:
    _1711_t12 = 1;
    _1713_n = $add_int64_t(_1713_n, _1711_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1943;
BB1963:
    _1711_$retval = _1711_t14;
    return _1711_$retval;
}


int main(void) {
  printf("%ld",_1711_main());
  return 0;
}
