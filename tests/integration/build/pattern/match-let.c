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
int64_t _1338_main(void);


/* Function definitions */
int64_t _1338_main(void){
    int64_t _1338_t2;
    int64_t _1338_t3;
    int64_t _1338_t4;
    struct struct0 _1339_x;
    int64_t _1338_t6;
    int64_t _1338_t7;
    int64_t _1338_t8;
    uint8_t _1338_t9;
    int64_t _1338_t0;
    int64_t _1338_t12;
    uint8_t _1338_t13;
    int64_t _1338_$retval;
    int64_t _1338_t10;
    uint8_t _1338_t11;
    _1338_t2 = 1;
    _1338_t3 = 2;
    _1338_t4 = 3;
    _1339_x = (struct struct0) {_1338_t2, _1338_t3, _1338_t4};
    _1338_t6 = 2;
    _1338_t7 = 3;
    _1338_t8 = 1;
    $bounds_check(_1338_t6, _1338_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1338_t9 = *((int64_t*)&_1339_x + _1338_t6)==_1338_t8;
    if (_1338_t9) {
        goto BB1532;
    } else {
        goto BB1535;
    }
BB1532:
    _1338_t0 = 2;
    goto BB1534;
BB1535:
    _1338_t10 = 2;
    $bounds_check(_1338_t6, _1338_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1338_t11 = *((int64_t*)&_1339_x + _1338_t6)==_1338_t10;
    if (_1338_t11) {
        goto BB1537;
    } else {
        goto BB1538;
    }
BB1534:
    _1338_$retval = _1338_t0;
    return _1338_$retval;
BB1537:
    _1338_t0 = 22;
    goto BB1534;
BB1538:
    _1338_t12 = 3;
    $bounds_check(_1338_t6, _1338_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1338_t13 = *((int64_t*)&_1339_x + _1338_t6)==_1338_t12;
    if (_1338_t13) {
        goto BB1540;
    } else {
        goto BB1542;
    }
BB1540:
    _1338_t0 = 222;
    goto BB1534;
BB1542:
    _1338_t0 = 0;
    goto BB1534;
}


int main(void) {
  printf("%ld",_1338_main());
  return 0;
}
