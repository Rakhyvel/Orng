/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1932_main(void);


/* Function definitions */
int64_t _1932_main(void){
    uint8_t _1933_found;
    int64_t _1934_n;
    int64_t _1932_t5;
    uint8_t _1932_t6;
    int64_t _1932_t14;
    int64_t _1932_t10;
    uint8_t _1932_t12;
    int64_t _1932_t16;
    int64_t _1932_$retval;
    _1933_found = 0;
    _1934_n = 0;
    goto BB2090;
BB2090:
    _1932_t5 = 10;
    _1932_t6 = _1934_n<_1932_t5;
    if (_1932_t6) {
        goto BB2091;
    } else {
        goto BB2106;
    }
BB2091:
    if (_1933_found) {
        goto BB2092;
    } else {
        goto BB2094;
    }
BB2106:
    if (_1933_found) {
        goto BB2107;
    } else {
        goto BB2111;
    }
BB2092:
    _1934_n = 100;
    goto BB2094;
BB2094:
    _1932_t10 = 6;
    _1932_t12 = _1934_n==_1932_t10;
    if (_1932_t12) {
        goto BB2097;
    } else {
        goto BB2101;
    }
BB2107:
    _1932_t16 = 15;
    goto BB2110;
BB2111:
    _1932_t16 = 4;
    goto BB2110;
BB2097:
    _1933_found = 1;
    goto BB2101;
BB2101:
    _1932_t14 = 1;
    _1934_n = $add_int64_t(_1934_n, _1932_t14, "tests/integration/whitebox/branch-condition-versioning.orng:4:43:\n    while let mut n: Int = 0; n < 10; n += 1 {\n                                         ^");
    goto BB2090;
BB2110:
    _1932_$retval = _1932_t16;
    return _1932_$retval;
}


int main(void) {
  printf("%ld",_1932_main());
  return 0;
}
