/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1578_main(void);

/* Function definitions */
int64_t _1578_main(void){
    uint8_t _1579_found;
    int64_t _1580_n;
    int64_t _1578_t3;
    uint8_t _1578_t4;
    int64_t _1578_t12;
    int64_t _1578_t8;
    uint8_t _1578_t10;
    int64_t _1578_t14;
    int64_t _1578_$retval;
    _1579_found = 0;
    _1580_n = 0;
    goto BB1834;
BB1834:
    _1578_t3 = 10;
    _1578_t4 = _1580_n<_1578_t3;
    if (_1578_t4) {
        goto BB1835;
    } else {
        goto BB1850;
    }
BB1835:
    if (_1579_found) {
        goto BB1836;
    } else {
        goto BB1838;
    }
BB1850:
    if (_1579_found) {
        goto BB1851;
    } else {
        goto BB1855;
    }
BB1836:
    _1580_n = 100;
    goto BB1838;
BB1838:
    _1578_t8 = 6;
    _1578_t10 = _1580_n==_1578_t8;
    if (_1578_t10) {
        goto BB1841;
    } else {
        goto BB1845;
    }
BB1851:
    _1578_t14 = 15;
    goto BB1854;
BB1855:
    _1578_t14 = 4;
    goto BB1854;
BB1841:
    _1579_found = 1;
    goto BB1845;
BB1845:
    _1578_t12 = 1;
    _1580_n = $add_int64_t(_1580_n, _1578_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1834;
BB1854:
    _1578_$retval = _1578_t14;
    return _1578_$retval;
}

int main(void) {
  printf("%ld",_1578_main());
  return 0;
}
