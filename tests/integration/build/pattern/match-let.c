/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1285_main(void);


/* Function definitions */
int64_t _1285_main(void){
    int64_t _1285_t2;
    int64_t _1285_t3;
    int64_t _1285_t4;
    struct struct0 _1286_x;
    int64_t _1285_t6;
    int64_t _1285_t7;
    int64_t _1285_t8;
    uint8_t _1285_t9;
    int64_t _1285_t0;
    int64_t _1285_t12;
    uint8_t _1285_t13;
    int64_t _1285_$retval;
    int64_t _1285_t10;
    uint8_t _1285_t11;
    _1285_t2 = 1;
    _1285_t3 = 2;
    _1285_t4 = 3;
    _1286_x = (struct struct0) {_1285_t2, _1285_t3, _1285_t4};
    _1285_t6 = 2;
    _1285_t7 = 3;
    _1285_t8 = 1;
    $bounds_check(_1285_t6, _1285_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1285_t9 = *((int64_t*)&_1286_x + _1285_t6)==_1285_t8;
    if (_1285_t9) {
        goto BB1477;
    } else {
        goto BB1480;
    }
BB1477:
    _1285_t0 = 2;
    goto BB1479;
BB1480:
    _1285_t10 = 2;
    $bounds_check(_1285_t6, _1285_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1285_t11 = *((int64_t*)&_1286_x + _1285_t6)==_1285_t10;
    if (_1285_t11) {
        goto BB1482;
    } else {
        goto BB1483;
    }
BB1479:
    _1285_$retval = _1285_t0;
    return _1285_$retval;
BB1482:
    _1285_t0 = 22;
    goto BB1479;
BB1483:
    _1285_t12 = 3;
    $bounds_check(_1285_t6, _1285_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1285_t13 = *((int64_t*)&_1286_x + _1285_t6)==_1285_t12;
    if (_1285_t13) {
        goto BB1485;
    } else {
        goto BB1487;
    }
BB1485:
    _1285_t0 = 222;
    goto BB1479;
BB1487:
    _1285_t0 = 0;
    goto BB1479;
}


int main(void) {
  printf("%ld",_1285_main());
  return 0;
}
