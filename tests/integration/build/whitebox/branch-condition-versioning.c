/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _5_main(void);


/* Function definitions */
int64_t _5_main(void){
    uint8_t _6_found;
    int64_t _7_n;
    int64_t _5_t5;
    uint8_t _5_t6;
    int64_t _5_t14;
    int64_t _5_t10;
    uint8_t _5_t12;
    int64_t _5_t16;
    int64_t _5_$retval;
    _6_found = 0;
    _7_n = 0;
    goto BB3;
BB3:
    _5_t5 = 10;
    _5_t6 = _7_n<_5_t5;
    if (_5_t6) {
        goto BB4;
    } else {
        goto BB19;
    }
BB4:
    if (_6_found) {
        goto BB5;
    } else {
        goto BB7;
    }
BB19:
    if (_6_found) {
        goto BB20;
    } else {
        goto BB24;
    }
BB5:
    _7_n = 100;
    goto BB7;
BB7:
    _5_t10 = 6;
    _5_t12 = _7_n==_5_t10;
    if (_5_t12) {
        goto BB10;
    } else {
        goto BB14;
    }
BB20:
    _5_t16 = 15;
    goto BB23;
BB24:
    _5_t16 = 4;
    goto BB23;
BB10:
    _6_found = 1;
    goto BB14;
BB14:
    _5_t14 = 1;
    _7_n = $add_int64_t(_7_n, _5_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB3;
BB23:
    _5_$retval = _5_t16;
    return _5_$retval;
}


int main(void) {
  printf("%ld",_5_main());
  return 0;
}
