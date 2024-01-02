/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1563_main(void);

/* Function definitions */
int64_t _1563_main(void){
    uint8_t _1564_found;
    int64_t _1565_n;
    int64_t _1563_t3;
    uint8_t _1563_t4;
    int64_t _1563_t12;
    int64_t _1563_t8;
    uint8_t _1563_t10;
    int64_t _1563_t14;
    int64_t _1563_$retval;
    _1564_found = 0;
    _1565_n = 0;
    goto BB1818;
BB1818:
    _1563_t3 = 10;
    _1563_t4 = _1565_n<_1563_t3;
    if (_1563_t4) {
        goto BB1819;
    } else {
        goto BB1834;
    }
BB1819:
    if (_1564_found) {
        goto BB1820;
    } else {
        goto BB1822;
    }
BB1834:
    if (_1564_found) {
        goto BB1835;
    } else {
        goto BB1839;
    }
BB1820:
    _1565_n = 100;
    goto BB1822;
BB1822:
    _1563_t8 = 6;
    _1563_t10 = _1565_n==_1563_t8;
    if (_1563_t10) {
        goto BB1825;
    } else {
        goto BB1829;
    }
BB1835:
    _1563_t14 = 15;
    goto BB1838;
BB1839:
    _1563_t14 = 4;
    goto BB1838;
BB1825:
    _1564_found = 1;
    goto BB1829;
BB1829:
    _1563_t12 = 1;
    _1565_n = $add_int64_t(_1565_n, _1563_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1818;
BB1838:
    _1563_$retval = _1563_t14;
    return _1563_$retval;
}

int main(void) {
  printf("%ld",_1563_main());
  return 0;
}
