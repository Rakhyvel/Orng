/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1568_main(void);

/* Function definitions */
int64_t _1568_main(void){
    uint8_t _1569_found;
    int64_t _1570_n;
    int64_t _1568_t3;
    uint8_t _1568_t4;
    int64_t _1568_t12;
    int64_t _1568_t8;
    uint8_t _1568_t10;
    int64_t _1568_t14;
    int64_t _1568_$retval;
    _1569_found = 0;
    _1570_n = 0;
    goto BB1822;
BB1822:
    _1568_t3 = 10;
    _1568_t4 = _1570_n<_1568_t3;
    if (_1568_t4) {
        goto BB1823;
    } else {
        goto BB1838;
    }
BB1823:
    if (_1569_found) {
        goto BB1824;
    } else {
        goto BB1826;
    }
BB1838:
    if (_1569_found) {
        goto BB1839;
    } else {
        goto BB1843;
    }
BB1824:
    _1570_n = 100;
    goto BB1826;
BB1826:
    _1568_t8 = 6;
    _1568_t10 = _1570_n==_1568_t8;
    if (_1568_t10) {
        goto BB1829;
    } else {
        goto BB1833;
    }
BB1839:
    _1568_t14 = 15;
    goto BB1842;
BB1843:
    _1568_t14 = 4;
    goto BB1842;
BB1829:
    _1569_found = 1;
    goto BB1833;
BB1833:
    _1568_t12 = 1;
    _1570_n = $add_int64_t(_1570_n, _1568_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1822;
BB1842:
    _1568_$retval = _1568_t14;
    return _1568_$retval;
}

int main(void) {
  printf("%ld",_1568_main());
  return 0;
}
