/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1791_main(void);


/* Function definitions */
int64_t _1791_main(void){
    uint8_t _1792_found;
    int64_t _1793_n;
    int64_t _1791_t5;
    uint8_t _1791_t6;
    int64_t _1791_t14;
    int64_t _1791_t10;
    uint8_t _1791_t12;
    int64_t _1791_t16;
    int64_t _1791_$retval;
    _1792_found = 0;
    _1793_n = 0;
    goto BB2007;
BB2007:
    _1791_t5 = 10;
    _1791_t6 = _1793_n<_1791_t5;
    if (_1791_t6) {
        goto BB2008;
    } else {
        goto BB2023;
    }
BB2008:
    if (_1792_found) {
        goto BB2009;
    } else {
        goto BB2011;
    }
BB2023:
    if (_1792_found) {
        goto BB2024;
    } else {
        goto BB2028;
    }
BB2009:
    _1793_n = 100;
    goto BB2011;
BB2011:
    _1791_t10 = 6;
    _1791_t12 = _1793_n==_1791_t10;
    if (_1791_t12) {
        goto BB2014;
    } else {
        goto BB2018;
    }
BB2024:
    _1791_t16 = 15;
    goto BB2027;
BB2028:
    _1791_t16 = 4;
    goto BB2027;
BB2014:
    _1792_found = 1;
    goto BB2018;
BB2018:
    _1791_t14 = 1;
    _1793_n = $add_int64_t(_1793_n, _1791_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2007;
BB2027:
    _1791_$retval = _1791_t16;
    return _1791_$retval;
}


int main(void) {
  printf("%ld",_1791_main());
  return 0;
}
