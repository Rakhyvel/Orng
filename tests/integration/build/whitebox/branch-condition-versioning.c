/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1904_main(void);


/* Function definitions */
int64_t _1904_main(void){
    uint8_t _1905_found;
    int64_t _1906_n;
    int64_t _1904_t5;
    uint8_t _1904_t6;
    int64_t _1904_t14;
    int64_t _1904_t10;
    uint8_t _1904_t12;
    int64_t _1904_t16;
    int64_t _1904_$retval;
    _1905_found = 0;
    _1906_n = 0;
    goto BB2062;
BB2062:
    _1904_t5 = 10;
    _1904_t6 = _1906_n<_1904_t5;
    if (_1904_t6) {
        goto BB2063;
    } else {
        goto BB2078;
    }
BB2063:
    if (_1905_found) {
        goto BB2064;
    } else {
        goto BB2066;
    }
BB2078:
    if (_1905_found) {
        goto BB2079;
    } else {
        goto BB2083;
    }
BB2064:
    _1906_n = 100;
    goto BB2066;
BB2066:
    _1904_t10 = 6;
    _1904_t12 = _1906_n==_1904_t10;
    if (_1904_t12) {
        goto BB2069;
    } else {
        goto BB2073;
    }
BB2079:
    _1904_t16 = 15;
    goto BB2082;
BB2083:
    _1904_t16 = 4;
    goto BB2082;
BB2069:
    _1905_found = 1;
    goto BB2073;
BB2073:
    _1904_t14 = 1;
    _1906_n = $add_int64_t(_1906_n, _1904_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2062;
BB2082:
    _1904_$retval = _1904_t16;
    return _1904_$retval;
}


int main(void) {
  printf("%ld",_1904_main());
  return 0;
}
