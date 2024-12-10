/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1952_main(void);


/* Function definitions */
int64_t _1952_main(void){
    uint8_t _1953_found;
    int64_t _1954_n;
    int64_t _1952_t5;
    uint8_t _1952_t6;
    int64_t _1952_t14;
    int64_t _1952_t10;
    uint8_t _1952_t12;
    int64_t _1952_t16;
    int64_t _1952_$retval;
    _1953_found = 0;
    _1954_n = 0;
    goto BB2109;
BB2109:
    _1952_t5 = 10;
    _1952_t6 = _1954_n<_1952_t5;
    if (_1952_t6) {
        goto BB2110;
    } else {
        goto BB2125;
    }
BB2110:
    if (_1953_found) {
        goto BB2111;
    } else {
        goto BB2113;
    }
BB2125:
    if (_1953_found) {
        goto BB2126;
    } else {
        goto BB2130;
    }
BB2111:
    _1954_n = 100;
    goto BB2113;
BB2113:
    _1952_t10 = 6;
    _1952_t12 = _1954_n==_1952_t10;
    if (_1952_t12) {
        goto BB2116;
    } else {
        goto BB2120;
    }
BB2126:
    _1952_t16 = 15;
    goto BB2129;
BB2130:
    _1952_t16 = 4;
    goto BB2129;
BB2116:
    _1953_found = 1;
    goto BB2120;
BB2120:
    _1952_t14 = 1;
    _1954_n = $add_int64_t(_1954_n, _1952_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2109;
BB2129:
    _1952_$retval = _1952_t16;
    return _1952_$retval;
}


int main(void) {
  printf("%ld",_1952_main());
  return 0;
}
