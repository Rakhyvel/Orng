/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1954_main(void);


/* Function definitions */
int64_t _1954_main(void){
    uint8_t _1955_found;
    int64_t _1956_n;
    int64_t _1954_t5;
    uint8_t _1954_t6;
    int64_t _1954_t14;
    int64_t _1954_t10;
    uint8_t _1954_t12;
    int64_t _1954_t16;
    int64_t _1954_$retval;
    _1955_found = 0;
    _1956_n = 0;
    goto BB2111;
BB2111:
    _1954_t5 = 10;
    _1954_t6 = _1956_n<_1954_t5;
    if (_1954_t6) {
        goto BB2112;
    } else {
        goto BB2127;
    }
BB2112:
    if (_1955_found) {
        goto BB2113;
    } else {
        goto BB2115;
    }
BB2127:
    if (_1955_found) {
        goto BB2128;
    } else {
        goto BB2132;
    }
BB2113:
    _1956_n = 100;
    goto BB2115;
BB2115:
    _1954_t10 = 6;
    _1954_t12 = _1956_n==_1954_t10;
    if (_1954_t12) {
        goto BB2118;
    } else {
        goto BB2122;
    }
BB2128:
    _1954_t16 = 15;
    goto BB2131;
BB2132:
    _1954_t16 = 4;
    goto BB2131;
BB2118:
    _1955_found = 1;
    goto BB2122;
BB2122:
    _1954_t14 = 1;
    _1956_n = $add_int64_t(_1956_n, _1954_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2111;
BB2131:
    _1954_$retval = _1954_t16;
    return _1954_$retval;
}


int main(void) {
  printf("%ld",_1954_main());
  return 0;
}
