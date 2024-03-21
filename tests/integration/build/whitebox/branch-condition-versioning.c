/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1793_main(void);


/* Function definitions */
int64_t _1793_main(void){
    uint8_t _1794_found;
    int64_t _1795_n;
    int64_t _1793_t5;
    uint8_t _1793_t6;
    int64_t _1793_t14;
    int64_t _1793_t10;
    uint8_t _1793_t12;
    int64_t _1793_t16;
    int64_t _1793_$retval;
    _1794_found = 0;
    _1795_n = 0;
    goto BB1977;
BB1977:
    _1793_t5 = 10;
    _1793_t6 = _1795_n<_1793_t5;
    if (_1793_t6) {
        goto BB1978;
    } else {
        goto BB1993;
    }
BB1978:
    if (_1794_found) {
        goto BB1979;
    } else {
        goto BB1981;
    }
BB1993:
    if (_1794_found) {
        goto BB1994;
    } else {
        goto BB1998;
    }
BB1979:
    _1795_n = 100;
    goto BB1981;
BB1981:
    _1793_t10 = 6;
    _1793_t12 = _1795_n==_1793_t10;
    if (_1793_t12) {
        goto BB1984;
    } else {
        goto BB1988;
    }
BB1994:
    _1793_t16 = 15;
    goto BB1997;
BB1998:
    _1793_t16 = 4;
    goto BB1997;
BB1984:
    _1794_found = 1;
    goto BB1988;
BB1988:
    _1793_t14 = 1;
    _1795_n = $add_int64_t(_1795_n, _1793_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1977;
BB1997:
    _1793_$retval = _1793_t16;
    return _1793_$retval;
}


int main(void) {
  printf("%ld",_1793_main());
  return 0;
}
