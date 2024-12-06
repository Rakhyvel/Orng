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
int64_t _1310_main(void);


/* Function definitions */
int64_t _1310_main(void){
    int64_t _1310_t2;
    int64_t _1310_t3;
    int64_t _1310_t4;
    struct struct0 _1311_x;
    int64_t _1310_t6;
    int64_t _1310_t7;
    int64_t _1310_t8;
    uint8_t _1310_t9;
    int64_t _1310_t0;
    int64_t _1310_t12;
    uint8_t _1310_t13;
    int64_t _1310_$retval;
    int64_t _1310_t10;
    uint8_t _1310_t11;
    _1310_t2 = 1;
    _1310_t3 = 2;
    _1310_t4 = 3;
    _1311_x = (struct struct0) {_1310_t2, _1310_t3, _1310_t4};
    _1310_t6 = 2;
    _1310_t7 = 3;
    _1310_t8 = 1;
    $bounds_check(_1310_t6, _1310_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1310_t9 = *((int64_t*)&_1311_x + _1310_t6)==_1310_t8;
    if (_1310_t9) {
        goto BB1503;
    } else {
        goto BB1506;
    }
BB1503:
    _1310_t0 = 2;
    goto BB1505;
BB1506:
    _1310_t10 = 2;
    $bounds_check(_1310_t6, _1310_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1310_t11 = *((int64_t*)&_1311_x + _1310_t6)==_1310_t10;
    if (_1310_t11) {
        goto BB1508;
    } else {
        goto BB1509;
    }
BB1505:
    _1310_$retval = _1310_t0;
    return _1310_$retval;
BB1508:
    _1310_t0 = 22;
    goto BB1505;
BB1509:
    _1310_t12 = 3;
    $bounds_check(_1310_t6, _1310_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1310_t13 = *((int64_t*)&_1311_x + _1310_t6)==_1310_t12;
    if (_1310_t13) {
        goto BB1511;
    } else {
        goto BB1513;
    }
BB1511:
    _1310_t0 = 222;
    goto BB1505;
BB1513:
    _1310_t0 = 0;
    goto BB1505;
}


int main(void) {
  printf("%ld",_1310_main());
  return 0;
}
