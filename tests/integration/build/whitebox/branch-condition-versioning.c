/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1769_main(void);


/* Function definitions */
int64_t _1769_main(void){
    uint8_t _1770_found;
    int64_t _1771_n;
    int64_t _1769_t5;
    uint8_t _1769_t6;
    int64_t _1769_t14;
    int64_t _1769_t10;
    uint8_t _1769_t12;
    int64_t _1769_t16;
    int64_t _1769_$retval;
    _1770_found = 0;
    _1771_n = 0;
    goto BB1960;
BB1960:
    _1769_t5 = 10;
    _1769_t6 = _1771_n<_1769_t5;
    if (_1769_t6) {
        goto BB1961;
    } else {
        goto BB1976;
    }
BB1961:
    if (_1770_found) {
        goto BB1962;
    } else {
        goto BB1964;
    }
BB1976:
    if (_1770_found) {
        goto BB1977;
    } else {
        goto BB1981;
    }
BB1962:
    _1771_n = 100;
    goto BB1964;
BB1964:
    _1769_t10 = 6;
    _1769_t12 = _1771_n==_1769_t10;
    if (_1769_t12) {
        goto BB1967;
    } else {
        goto BB1971;
    }
BB1977:
    _1769_t16 = 15;
    goto BB1980;
BB1981:
    _1769_t16 = 4;
    goto BB1980;
BB1967:
    _1770_found = 1;
    goto BB1971;
BB1971:
    _1769_t14 = 1;
    _1771_n = $add_int64_t(_1771_n, _1769_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1960;
BB1980:
    _1769_$retval = _1769_t16;
    return _1769_$retval;
}


int main(void) {
  printf("%ld",_1769_main());
  return 0;
}
