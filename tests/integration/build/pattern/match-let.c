/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t _0;
        int64_t _1;
        int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _1213_main(void);

/* Function definitions */
int64_t _1213_main(void){
    int64_t _1213_t2;
    int64_t _1213_t3;
    int64_t _1213_t4;
    struct0 _1214_x;
    int64_t _1213_t5;
    int64_t _1213_t6;
    int64_t _1213_t7;
    uint8_t _1213_t8;
    int64_t _1213_t0;
    int64_t _1213_t11;
    uint8_t _1213_t12;
    int64_t _1213_$retval;
    int64_t _1213_t9;
    uint8_t _1213_t10;
    _1213_t2 = 1;
    _1213_t3 = 2;
    _1213_t4 = 3;
    _1214_x = (struct0) {_1213_t2, _1213_t3, _1213_t4};
    _1213_t5 = 2;
    _1213_t6 = 3;
    _1213_t7 = 1;
    $bounds_check(_1213_t5, _1213_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1213_t8 = *((int64_t*)&_1214_x + _1213_t5)==_1213_t7;
    if (_1213_t8) {
        goto BB1444;
    } else {
        goto BB1447;
    }
BB1444:
    _1213_t0 = 2;
    goto BB1446;
BB1447:
    _1213_t9 = 2;
    $bounds_check(_1213_t5, _1213_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1213_t10 = *((int64_t*)&_1214_x + _1213_t5)==_1213_t9;
    if (_1213_t10) {
        goto BB1449;
    } else {
        goto BB1450;
    }
BB1446:
    _1213_$retval = _1213_t0;
    return _1213_$retval;
BB1449:
    _1213_t0 = 22;
    goto BB1446;
BB1450:
    _1213_t11 = 3;
    $bounds_check(_1213_t5, _1213_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1213_t12 = *((int64_t*)&_1214_x + _1213_t5)==_1213_t11;
    if (_1213_t12) {
        goto BB1452;
    } else {
        goto BB1454;
    }
BB1452:
    _1213_t0 = 222;
    goto BB1446;
BB1454:
    _1213_t0 = 0;
    goto BB1446;
}

int main(void) {
  printf("%ld",_1213_main());
  return 0;
}
