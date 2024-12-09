/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1937_main(void);


/* Function definitions */
int64_t _1937_main(void){
    uint8_t _1938_found;
    int64_t _1939_n;
    int64_t _1937_t5;
    uint8_t _1937_t6;
    int64_t _1937_t14;
    int64_t _1937_t10;
    uint8_t _1937_t12;
    int64_t _1937_t16;
    int64_t _1937_$retval;
    _1938_found = 0;
    _1939_n = 0;
    goto BB2093;
BB2093:
    _1937_t5 = 10;
    _1937_t6 = _1939_n<_1937_t5;
    if (_1937_t6) {
        goto BB2094;
    } else {
        goto BB2109;
    }
BB2094:
    if (_1938_found) {
        goto BB2095;
    } else {
        goto BB2097;
    }
BB2109:
    if (_1938_found) {
        goto BB2110;
    } else {
        goto BB2114;
    }
BB2095:
    _1939_n = 100;
    goto BB2097;
BB2097:
    _1937_t10 = 6;
    _1937_t12 = _1939_n==_1937_t10;
    if (_1937_t12) {
        goto BB2100;
    } else {
        goto BB2104;
    }
BB2110:
    _1937_t16 = 15;
    goto BB2113;
BB2114:
    _1937_t16 = 4;
    goto BB2113;
BB2100:
    _1938_found = 1;
    goto BB2104;
BB2104:
    _1937_t14 = 1;
    _1939_n = $add_int64_t(_1939_n, _1937_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2093;
BB2113:
    _1937_$retval = _1937_t16;
    return _1937_$retval;
}


int main(void) {
  printf("%ld",_1937_main());
  return 0;
}
