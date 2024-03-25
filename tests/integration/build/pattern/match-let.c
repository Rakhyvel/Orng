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
int64_t _1241_main(void);


/* Function definitions */
int64_t _1241_main(void){
    int64_t _1241_t2;
    int64_t _1241_t3;
    int64_t _1241_t4;
    struct struct0 _1242_x;
    int64_t _1241_t6;
    int64_t _1241_t7;
    int64_t _1241_t8;
    uint8_t _1241_t9;
    int64_t _1241_t0;
    int64_t _1241_t12;
    uint8_t _1241_t13;
    int64_t _1241_$retval;
    int64_t _1241_t10;
    uint8_t _1241_t11;
    _1241_t2 = 1;
    _1241_t3 = 2;
    _1241_t4 = 3;
    _1242_x = (struct struct0) {_1241_t2, _1241_t3, _1241_t4};
    _1241_t6 = 2;
    _1241_t7 = 3;
    _1241_t8 = 1;
    $bounds_check(_1241_t6, _1241_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1241_t9 = *((int64_t*)&_1242_x + _1241_t6)==_1241_t8;
    if (_1241_t9) {
        goto BB1425;
    } else {
        goto BB1428;
    }
BB1425:
    _1241_t0 = 2;
    goto BB1427;
BB1428:
    _1241_t10 = 2;
    $bounds_check(_1241_t6, _1241_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1241_t11 = *((int64_t*)&_1242_x + _1241_t6)==_1241_t10;
    if (_1241_t11) {
        goto BB1430;
    } else {
        goto BB1431;
    }
BB1427:
    _1241_$retval = _1241_t0;
    return _1241_$retval;
BB1430:
    _1241_t0 = 22;
    goto BB1427;
BB1431:
    _1241_t12 = 3;
    $bounds_check(_1241_t6, _1241_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1241_t13 = *((int64_t*)&_1242_x + _1241_t6)==_1241_t12;
    if (_1241_t13) {
        goto BB1433;
    } else {
        goto BB1435;
    }
BB1433:
    _1241_t0 = 222;
    goto BB1427;
BB1435:
    _1241_t0 = 0;
    goto BB1427;
}


int main(void) {
  printf("%ld",_1241_main());
  return 0;
}
