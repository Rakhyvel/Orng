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
int64_t _1236_main(void);

/* Function definitions */
int64_t _1236_main(void){
    int64_t _1236_t2;
    int64_t _1236_t3;
    int64_t _1236_t4;
    struct struct0 _1237_x;
    int64_t _1236_t5;
    int64_t _1236_t6;
    int64_t _1236_t7;
    uint8_t _1236_t8;
    int64_t _1236_t0;
    int64_t _1236_t11;
    uint8_t _1236_t12;
    int64_t _1236_$retval;
    int64_t _1236_t9;
    uint8_t _1236_t10;
    _1236_t2 = 1;
    _1236_t3 = 2;
    _1236_t4 = 3;
    _1237_x = (struct struct0) {_1236_t2, _1236_t3, _1236_t4};
    _1236_t5 = 2;
    _1236_t6 = 3;
    _1236_t7 = 1;
    $bounds_check(_1236_t5, _1236_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1236_t8 = *((int64_t*)&_1237_x + _1236_t5)==_1236_t7;
    if (_1236_t8) {
        goto BB1456;
    } else {
        goto BB1459;
    }
BB1456:
    _1236_t0 = 2;
    goto BB1458;
BB1459:
    _1236_t9 = 2;
    $bounds_check(_1236_t5, _1236_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1236_t10 = *((int64_t*)&_1237_x + _1236_t5)==_1236_t9;
    if (_1236_t10) {
        goto BB1461;
    } else {
        goto BB1462;
    }
BB1458:
    _1236_$retval = _1236_t0;
    return _1236_$retval;
BB1461:
    _1236_t0 = 22;
    goto BB1458;
BB1462:
    _1236_t11 = 3;
    $bounds_check(_1236_t5, _1236_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1236_t12 = *((int64_t*)&_1237_x + _1236_t5)==_1236_t11;
    if (_1236_t12) {
        goto BB1464;
    } else {
        goto BB1466;
    }
BB1464:
    _1236_t0 = 222;
    goto BB1458;
BB1466:
    _1236_t0 = 0;
    goto BB1458;
}

int main(void) {
  printf("%ld",_1236_main());
  return 0;
}
