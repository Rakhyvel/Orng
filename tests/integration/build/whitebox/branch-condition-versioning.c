/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1560_main(void);

/* Function definitions */
int64_t _1560_main(void){
    uint8_t _1561_found;
    int64_t _1562_n;
    int64_t _1560_t3;
    uint8_t _1560_t4;
    int64_t _1560_t12;
    int64_t _1560_t8;
    uint8_t _1560_t10;
    int64_t _1560_t14;
    int64_t _1560_$retval;
    _1561_found = 0;
    _1562_n = 0;
    goto BB1826;
BB1826:
    _1560_t3 = 10;
    _1560_t4 = _1562_n<_1560_t3;
    if (_1560_t4) {
        goto BB1827;
    } else {
        goto BB1842;
    }
BB1827:
    if (_1561_found) {
        goto BB1828;
    } else {
        goto BB1830;
    }
BB1842:
    if (_1561_found) {
        goto BB1843;
    } else {
        goto BB1847;
    }
BB1828:
    _1562_n = 100;
    goto BB1830;
BB1830:
    _1560_t8 = 6;
    _1560_t10 = _1562_n==_1560_t8;
    if (_1560_t10) {
        goto BB1833;
    } else {
        goto BB1837;
    }
BB1843:
    _1560_t14 = 15;
    goto BB1846;
BB1847:
    _1560_t14 = 4;
    goto BB1846;
BB1833:
    _1561_found = 1;
    goto BB1837;
BB1837:
    _1560_t12 = 1;
    _1562_n = $add_int64_t(_1562_n, _1560_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1826;
BB1846:
    _1560_$retval = _1560_t14;
    return _1560_$retval;
}

int main(void) {
  printf("%ld",_1560_main());
  return 0;
}
