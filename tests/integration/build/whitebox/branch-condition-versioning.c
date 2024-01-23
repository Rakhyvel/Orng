/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1640_main(void);


/* Function definitions */
int64_t _1640_main(void){
    uint8_t _1641_found;
    int64_t _1642_n;
    int64_t _1640_t3;
    uint8_t _1640_t4;
    int64_t _1640_t12;
    int64_t _1640_t8;
    uint8_t _1640_t10;
    int64_t _1640_t14;
    int64_t _1640_$retval;
    _1641_found = 0;
    _1642_n = 0;
    goto BB1881;
BB1881:
    _1640_t3 = 10;
    _1640_t4 = _1642_n<_1640_t3;
    if (_1640_t4) {
        goto BB1882;
    } else {
        goto BB1897;
    }
BB1882:
    if (_1641_found) {
        goto BB1883;
    } else {
        goto BB1885;
    }
BB1897:
    if (_1641_found) {
        goto BB1898;
    } else {
        goto BB1902;
    }
BB1883:
    _1642_n = 100;
    goto BB1885;
BB1885:
    _1640_t8 = 6;
    _1640_t10 = _1642_n==_1640_t8;
    if (_1640_t10) {
        goto BB1888;
    } else {
        goto BB1892;
    }
BB1898:
    _1640_t14 = 15;
    goto BB1901;
BB1902:
    _1640_t14 = 4;
    goto BB1901;
BB1888:
    _1641_found = 1;
    goto BB1892;
BB1892:
    _1640_t12 = 1;
    _1642_n = $add_int64_t(_1642_n, _1640_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1881;
BB1901:
    _1640_$retval = _1640_t14;
    return _1640_$retval;
}


int main(void) {
  printf("%ld",_1640_main());
  return 0;
}
