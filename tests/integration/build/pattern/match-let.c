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
int64_t _1246_main(void);


/* Function definitions */
int64_t _1246_main(void){
    int64_t _1246_t2;
    int64_t _1246_t3;
    int64_t _1246_t4;
    struct struct0 _1247_x;
    int64_t _1246_t6;
    int64_t _1246_t7;
    int64_t _1246_t8;
    uint8_t _1246_t9;
    int64_t _1246_t0;
    int64_t _1246_t12;
    uint8_t _1246_t13;
    int64_t _1246_$retval;
    int64_t _1246_t10;
    uint8_t _1246_t11;
    _1246_t2 = 1;
    _1246_t3 = 2;
    _1246_t4 = 3;
    _1247_x = (struct struct0) {_1246_t2, _1246_t3, _1246_t4};
    _1246_t6 = 2;
    _1246_t7 = 3;
    _1246_t8 = 1;
    $bounds_check(_1246_t6, _1246_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1246_t9 = *((int64_t*)&_1247_x + _1246_t6)==_1246_t8;
    if (_1246_t9) {
        goto BB1429;
    } else {
        goto BB1432;
    }
BB1429:
    _1246_t0 = 2;
    goto BB1431;
BB1432:
    _1246_t10 = 2;
    $bounds_check(_1246_t6, _1246_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1246_t11 = *((int64_t*)&_1247_x + _1246_t6)==_1246_t10;
    if (_1246_t11) {
        goto BB1434;
    } else {
        goto BB1435;
    }
BB1431:
    _1246_$retval = _1246_t0;
    return _1246_$retval;
BB1434:
    _1246_t0 = 22;
    goto BB1431;
BB1435:
    _1246_t12 = 3;
    $bounds_check(_1246_t6, _1246_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1246_t13 = *((int64_t*)&_1247_x + _1246_t6)==_1246_t12;
    if (_1246_t13) {
        goto BB1437;
    } else {
        goto BB1439;
    }
BB1437:
    _1246_t0 = 222;
    goto BB1431;
BB1439:
    _1246_t0 = 0;
    goto BB1431;
}


int main(void) {
  printf("%ld",_1246_main());
  return 0;
}
