/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1596_main(void);

/* Function definitions */
int64_t _1596_main(void){
    uint8_t _1597_found;
    int64_t _1598_n;
    int64_t _1596_t3;
    uint8_t _1596_t4;
    int64_t _1596_t12;
    int64_t _1596_t8;
    uint8_t _1596_t10;
    int64_t _1596_t14;
    int64_t _1596_$retval;
    _1597_found = 0;
    _1598_n = 0;
    goto BB1841;
BB1841:
    _1596_t3 = 10;
    _1596_t4 = _1598_n<_1596_t3;
    if (_1596_t4) {
        goto BB1842;
    } else {
        goto BB1857;
    }
BB1842:
    if (_1597_found) {
        goto BB1843;
    } else {
        goto BB1845;
    }
BB1857:
    if (_1597_found) {
        goto BB1858;
    } else {
        goto BB1862;
    }
BB1843:
    _1598_n = 100;
    goto BB1845;
BB1845:
    _1596_t8 = 6;
    _1596_t10 = _1598_n==_1596_t8;
    if (_1596_t10) {
        goto BB1848;
    } else {
        goto BB1852;
    }
BB1858:
    _1596_t14 = 15;
    goto BB1861;
BB1862:
    _1596_t14 = 4;
    goto BB1861;
BB1848:
    _1597_found = 1;
    goto BB1852;
BB1852:
    _1596_t12 = 1;
    _1598_n = $add_int64_t(_1598_n, _1596_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1841;
BB1861:
    _1596_$retval = _1596_t14;
    return _1596_$retval;
}

int main(void) {
  printf("%ld",_1596_main());
  return 0;
}
