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
    goto BB1839;
BB1839:
    _1530_t3 = 10;
    _1530_t4 = _1532_n < _1530_t3;
    if (_1530_t4) {
        goto BB1840;
    } else {
        goto BB1855;
    }
BB1840:
    if (_1531_found) {
        goto BB1841;
    } else {
        goto BB1843;
    }
BB1855:
    if (_1531_found) {
        goto BB1856;
    } else {
        goto BB1860;
    }
BB1841:
    _1532_n = 100;
    goto BB1843;
BB1843:
    _1530_t8 = 6;
    _1530_t10 = _1532_n == _1530_t8;
    if (_1530_t10) {
        goto BB1846;
    } else {
        goto BB1850;
    }
BB1856:
    _1530_t14 = 15;
    goto BB1859;
BB1860:
    _1530_t14 = 4;
    goto BB1859;
BB1846:
    _1531_found = 1;
    goto BB1850;
BB1850:
    _1530_t12 = 1;
    _1532_n = $add_int64_t(_1532_n, _1530_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1839;
BB1859:
    _1530_$retval = _1530_t14;
    return _1530_$retval;
}

int main(void) {
  printf("%ld",_1530_main());
  return 0;
}
