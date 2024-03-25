/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1802_main(void);


/* Function definitions */
int64_t _1802_main(void){
    uint8_t _1803_found;
    int64_t _1804_n;
    int64_t _1802_t5;
    uint8_t _1802_t6;
    int64_t _1802_t14;
    int64_t _1802_t10;
    uint8_t _1802_t12;
    int64_t _1802_t16;
    int64_t _1802_$retval;
    _1803_found = 0;
    _1804_n = 0;
    goto BB1983;
BB1983:
    _1802_t5 = 10;
    _1802_t6 = _1804_n<_1802_t5;
    if (_1802_t6) {
        goto BB1984;
    } else {
        goto BB1999;
    }
BB1984:
    if (_1803_found) {
        goto BB1985;
    } else {
        goto BB1987;
    }
BB1999:
    if (_1803_found) {
        goto BB2000;
    } else {
        goto BB2004;
    }
BB1985:
    _1804_n = 100;
    goto BB1987;
BB1987:
    _1802_t10 = 6;
    _1802_t12 = _1804_n==_1802_t10;
    if (_1802_t12) {
        goto BB1990;
    } else {
        goto BB1994;
    }
BB2000:
    _1802_t16 = 15;
    goto BB2003;
BB2004:
    _1802_t16 = 4;
    goto BB2003;
BB1990:
    _1803_found = 1;
    goto BB1994;
BB1994:
    _1802_t14 = 1;
    _1804_n = $add_int64_t(_1804_n, _1802_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB1983;
BB2003:
    _1802_$retval = _1802_t16;
    return _1802_$retval;
}


int main(void) {
  printf("%ld",_1802_main());
  return 0;
}
