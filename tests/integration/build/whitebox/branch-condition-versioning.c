/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1530_main(void);

/* Function definitions */
int64_t _1530_main(void){
    uint8_t _1531_found;
    int64_t _1532_n;
    int64_t _1530_t3;
    uint8_t _1530_t4;
    int64_t _1530_t12;
    int64_t _1530_t8;
    uint8_t _1530_t10;
    int64_t _1530_t14;
    int64_t _1530_$retval;
    _1531_found = 0;
    _1532_n = 0;
    goto BB1825;
BB1825:
    _1530_t3 = 10;
    _1530_t4 = _1532_n<_1530_t3;
    if (_1530_t4) {
        goto BB1826;
    } else {
        goto BB1841;
    }
BB1826:
    if (_1531_found) {
        goto BB1827;
    } else {
        goto BB1829;
    }
BB1841:
    if (_1531_found) {
        goto BB1842;
    } else {
        goto BB1846;
    }
BB1827:
    _1532_n = 100;
    goto BB1829;
BB1829:
    _1530_t8 = 6;
    _1530_t10 = _1532_n==_1530_t8;
    if (_1530_t10) {
        goto BB1832;
    } else {
        goto BB1836;
    }
BB1842:
    _1530_t14 = 15;
    goto BB1845;
BB1846:
    _1530_t14 = 4;
    goto BB1845;
BB1832:
    _1531_found = 1;
    goto BB1836;
BB1836:
    _1530_t12 = 1;
    _1532_n = $add_int64_t(_1532_n, _1530_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1825;
BB1845:
    _1530_$retval = _1530_t14;
    return _1530_$retval;
}

int main(void) {
  printf("%ld",_1530_main());
  return 0;
}
