/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1827_main(void);

/* Function definitions */
int64_t _1827_main(void){
    uint8_t _1828_found;
    int64_t _1829_n;
    int64_t _1827_t3;
    uint8_t _1827_t4;
    int64_t _1827_t12;
    int64_t _1827_t8;
    uint8_t _1827_t10;
    int64_t _1827_t14;
    int64_t _1827_$retval;
    _1828_found = 0;
    _1829_n = 0;
    goto BB1;
BB1:
    _1827_t3 = 10;
    _1827_t4 = _1829_n < _1827_t3;
    if (_1827_t4) {
        goto BB2;
    } else {
        goto BB17;
    }
BB2:
    if (_1828_found) {
        goto BB3;
    } else {
        goto BB5;
    }
BB17:
    if (_1828_found) {
        goto BB18;
    } else {
        goto BB22;
    }
BB3:
    _1829_n = 100;
    goto BB5;
BB5:
    _1827_t8 = 6;
    _1827_t10 = _1829_n == _1827_t8;
    if (_1827_t10) {
        goto BB8;
    } else {
        goto BB12;
    }
BB18:
    _1827_t14 = 15;
    goto BB21;
BB22:
    _1827_t14 = 4;
    goto BB21;
BB8:
    _1828_found = 1;
    goto BB12;
BB12:
    _1827_t12 = 1;
    _1829_n = $add_int64_t(_1829_n, _1827_t12, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1;
BB21:
    _1827_$retval = _1827_t14;
    return _1827_$retval;
}

int main(void) {
  printf("%ld",_1827_main());
  return 0;
}
