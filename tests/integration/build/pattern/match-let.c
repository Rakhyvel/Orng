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
int64_t _1296_main(void);


/* Function definitions */
int64_t _1296_main(void){
    int64_t _1296_t2;
    int64_t _1296_t3;
    int64_t _1296_t4;
    struct struct0 _1297_x;
    int64_t _1296_t6;
    int64_t _1296_t7;
    int64_t _1296_t8;
    uint8_t _1296_t9;
    int64_t _1296_t0;
    int64_t _1296_t12;
    uint8_t _1296_t13;
    int64_t _1296_$retval;
    int64_t _1296_t10;
    uint8_t _1296_t11;
    _1296_t2 = 1;
    _1296_t3 = 2;
    _1296_t4 = 3;
    _1297_x = (struct struct0) {_1296_t2, _1296_t3, _1296_t4};
    _1296_t6 = 2;
    _1296_t7 = 3;
    _1296_t8 = 1;
    $bounds_check(_1296_t6, _1296_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1296_t9 = *((int64_t*)&_1297_x + _1296_t6)==_1296_t8;
    if (_1296_t9) {
        goto BB1488;
    } else {
        goto BB1491;
    }
BB1488:
    _1296_t0 = 2;
    goto BB1490;
BB1491:
    _1296_t10 = 2;
    $bounds_check(_1296_t6, _1296_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1296_t11 = *((int64_t*)&_1297_x + _1296_t6)==_1296_t10;
    if (_1296_t11) {
        goto BB1493;
    } else {
        goto BB1494;
    }
BB1490:
    _1296_$retval = _1296_t0;
    return _1296_$retval;
BB1493:
    _1296_t0 = 22;
    goto BB1490;
BB1494:
    _1296_t12 = 3;
    $bounds_check(_1296_t6, _1296_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1296_t13 = *((int64_t*)&_1297_x + _1296_t6)==_1296_t12;
    if (_1296_t13) {
        goto BB1496;
    } else {
        goto BB1498;
    }
BB1496:
    _1296_t0 = 222;
    goto BB1490;
BB1498:
    _1296_t0 = 0;
    goto BB1490;
}


int main(void) {
  printf("%ld",_1296_main());
  return 0;
}
