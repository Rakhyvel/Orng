/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1902_main(void);


/* Function definitions */
int64_t _1902_main(void){
    uint8_t _1903_found;
    int64_t _1904_n;
    int64_t _1902_t5;
    uint8_t _1902_t6;
    int64_t _1902_t14;
    int64_t _1902_t10;
    uint8_t _1902_t12;
    int64_t _1902_t16;
    int64_t _1902_$retval;
    _1903_found = 0;
    _1904_n = 0;
    goto BB2060;
BB2060:
    _1902_t5 = 10;
    _1902_t6 = _1904_n<_1902_t5;
    if (_1902_t6) {
        goto BB2061;
    } else {
        goto BB2076;
    }
BB2061:
    if (_1903_found) {
        goto BB2062;
    } else {
        goto BB2064;
    }
BB2076:
    if (_1903_found) {
        goto BB2077;
    } else {
        goto BB2081;
    }
BB2062:
    _1904_n = 100;
    goto BB2064;
BB2064:
    _1902_t10 = 6;
    _1902_t12 = _1904_n==_1902_t10;
    if (_1902_t12) {
        goto BB2067;
    } else {
        goto BB2071;
    }
BB2077:
    _1902_t16 = 15;
    goto BB2080;
BB2081:
    _1902_t16 = 4;
    goto BB2080;
BB2067:
    _1903_found = 1;
    goto BB2071;
BB2071:
    _1902_t14 = 1;
    _1904_n = $add_int64_t(_1904_n, _1902_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2060;
BB2080:
    _1902_$retval = _1902_t16;
    return _1902_$retval;
}


int main(void) {
  printf("%ld",_1902_main());
  return 0;
}
