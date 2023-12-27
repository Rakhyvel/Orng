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
int64_t _1200_main(void);

/* Function definitions */
int64_t _1200_main(void){
    int64_t _1200_t2;
    int64_t _1200_t3;
    int64_t _1200_t4;
    struct0 _1201_x;
    int64_t _1200_t5;
    int64_t _1200_t6;
    int64_t _1200_t7;
    uint8_t _1200_t8;
    int64_t _1200_t0;
    int64_t _1200_t11;
    uint8_t _1200_t12;
    int64_t _1200_$retval;
    int64_t _1200_t9;
    uint8_t _1200_t10;
    _1200_t2 = 1;
    _1200_t3 = 2;
    _1200_t4 = 3;
    _1201_x = (struct0) {_1200_t2, _1200_t3, _1200_t4};
    _1200_t5 = 2;
    _1200_t6 = 3;
    _1200_t7 = 1;
    $bounds_check(_1200_t5, _1200_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1200_t8 = *((int64_t*)&_1201_x + _1200_t5)==_1200_t7;
    if (_1200_t8) {
        goto BB1447;
    } else {
        goto BB1450;
    }
BB1447:
    _1200_t0 = 2;
    goto BB1449;
BB1450:
    _1200_t9 = 2;
    $bounds_check(_1200_t5, _1200_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1200_t10 = *((int64_t*)&_1201_x + _1200_t5)==_1200_t9;
    if (_1200_t10) {
        goto BB1452;
    } else {
        goto BB1453;
    }
BB1449:
    _1200_$retval = _1200_t0;
    return _1200_$retval;
BB1452:
    _1200_t0 = 22;
    goto BB1449;
BB1453:
    _1200_t11 = 3;
    $bounds_check(_1200_t5, _1200_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1200_t12 = *((int64_t*)&_1201_x + _1200_t5)==_1200_t11;
    if (_1200_t12) {
        goto BB1455;
    } else {
        goto BB1457;
    }
BB1455:
    _1200_t0 = 222;
    goto BB1449;
BB1457:
    _1200_t0 = 0;
    goto BB1449;
}

int main(void) {
  printf("%ld",_1200_main());
  return 0;
}
