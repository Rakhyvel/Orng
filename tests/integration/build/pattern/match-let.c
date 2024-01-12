/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1231_main(void);

/* Function definitions */
int64_t _1231_main(void){
    int64_t _1231_t2;
    int64_t _1231_t3;
    int64_t _1231_t4;
    struct struct0 _1232_x;
    int64_t _1231_t5;
    int64_t _1231_t6;
    int64_t _1231_t7;
    uint8_t _1231_t8;
    int64_t _1231_t0;
    int64_t _1231_t11;
    uint8_t _1231_t12;
    int64_t _1231_$retval;
    int64_t _1231_t9;
    uint8_t _1231_t10;
    _1231_t2 = 1;
    _1231_t3 = 2;
    _1231_t4 = 3;
    _1232_x = (struct struct0) {_1231_t2, _1231_t3, _1231_t4};
    _1231_t5 = 2;
    _1231_t6 = 3;
    _1231_t7 = 1;
    $bounds_check(_1231_t5, _1231_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1231_t8 = *((int64_t*)&_1232_x + _1231_t5)==_1231_t7;
    if (_1231_t8) {
        goto BB1452;
    } else {
        goto BB1455;
    }
BB1452:
    _1231_t0 = 2;
    goto BB1454;
BB1455:
    _1231_t9 = 2;
    $bounds_check(_1231_t5, _1231_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1231_t10 = *((int64_t*)&_1232_x + _1231_t5)==_1231_t9;
    if (_1231_t10) {
        goto BB1457;
    } else {
        goto BB1458;
    }
BB1454:
    _1231_$retval = _1231_t0;
    return _1231_$retval;
BB1457:
    _1231_t0 = 22;
    goto BB1454;
BB1458:
    _1231_t11 = 3;
    $bounds_check(_1231_t5, _1231_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1231_t12 = *((int64_t*)&_1232_x + _1231_t5)==_1231_t11;
    if (_1231_t12) {
        goto BB1460;
    } else {
        goto BB1462;
    }
BB1460:
    _1231_t0 = 222;
    goto BB1454;
BB1462:
    _1231_t0 = 0;
    goto BB1454;
}

int main(void) {
  printf("%ld",_1231_main());
  return 0;
}
