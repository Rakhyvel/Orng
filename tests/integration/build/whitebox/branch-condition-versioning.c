/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1807_main(void);


/* Function definitions */
int64_t _1807_main(void){
    uint8_t _1808_found;
    int64_t _1809_n;
    int64_t _1807_t5;
    uint8_t _1807_t6;
    int64_t _1807_t14;
    int64_t _1807_t10;
    uint8_t _1807_t12;
    int64_t _1807_t16;
    int64_t _1807_$retval;
    _1808_found = 0;
    _1809_n = 0;
    goto BB1987;
BB1987:
    _1807_t5 = 10;
    _1807_t6 = _1809_n<_1807_t5;
    if (_1807_t6) {
        goto BB1988;
    } else {
        goto BB2003;
    }
BB1988:
    if (_1808_found) {
        goto BB1989;
    } else {
        goto BB1991;
    }
BB2003:
    if (_1808_found) {
        goto BB2004;
    } else {
        goto BB2008;
    }
BB1989:
    _1809_n = 100;
    goto BB1991;
BB1991:
    _1807_t10 = 6;
    _1807_t12 = _1809_n==_1807_t10;
    if (_1807_t12) {
        goto BB1994;
    } else {
        goto BB1998;
    }
BB2004:
    _1807_t16 = 15;
    goto BB2007;
BB2008:
    _1807_t16 = 4;
    goto BB2007;
BB1994:
    _1808_found = 1;
    goto BB1998;
BB1998:
    _1807_t14 = 1;
    _1809_n = $add_int64_t(_1809_n, _1807_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1987;
BB2007:
    _1807_$retval = _1807_t16;
    return _1807_$retval;
}


int main(void) {
  printf("%ld",_1807_main());
  return 0;
}
