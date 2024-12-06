/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1924_main(void);


/* Function definitions */
int64_t _1924_main(void){
    uint8_t _1925_found;
    int64_t _1926_n;
    int64_t _1924_t5;
    uint8_t _1924_t6;
    int64_t _1924_t14;
    int64_t _1924_t10;
    uint8_t _1924_t12;
    int64_t _1924_t16;
    int64_t _1924_$retval;
    _1925_found = 0;
    _1926_n = 0;
    goto BB2080;
BB2080:
    _1924_t5 = 10;
    _1924_t6 = _1926_n<_1924_t5;
    if (_1924_t6) {
        goto BB2081;
    } else {
        goto BB2096;
    }
BB2081:
    if (_1925_found) {
        goto BB2082;
    } else {
        goto BB2084;
    }
BB2096:
    if (_1925_found) {
        goto BB2097;
    } else {
        goto BB2101;
    }
BB2082:
    _1926_n = 100;
    goto BB2084;
BB2084:
    _1924_t10 = 6;
    _1924_t12 = _1926_n==_1924_t10;
    if (_1924_t12) {
        goto BB2087;
    } else {
        goto BB2091;
    }
BB2097:
    _1924_t16 = 15;
    goto BB2100;
BB2101:
    _1924_t16 = 4;
    goto BB2100;
BB2087:
    _1925_found = 1;
    goto BB2091;
BB2091:
    _1924_t14 = 1;
    _1926_n = $add_int64_t(_1926_n, _1924_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2080;
BB2100:
    _1924_$retval = _1924_t16;
    return _1924_$retval;
}


int main(void) {
  printf("%ld",_1924_main());
  return 0;
}
