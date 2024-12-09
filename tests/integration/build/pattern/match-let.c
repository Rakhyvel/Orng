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
int64_t _1323_main(void);


/* Function definitions */
int64_t _1323_main(void){
    int64_t _1323_t2;
    int64_t _1323_t3;
    int64_t _1323_t4;
    struct struct0 _1324_x;
    int64_t _1323_t6;
    int64_t _1323_t7;
    int64_t _1323_t8;
    uint8_t _1323_t9;
    int64_t _1323_t0;
    int64_t _1323_t12;
    uint8_t _1323_t13;
    int64_t _1323_$retval;
    int64_t _1323_t10;
    uint8_t _1323_t11;
    _1323_t2 = 1;
    _1323_t3 = 2;
    _1323_t4 = 3;
    _1324_x = (struct struct0) {_1323_t2, _1323_t3, _1323_t4};
    _1323_t6 = 2;
    _1323_t7 = 3;
    _1323_t8 = 1;
    $bounds_check(_1323_t6, _1323_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1323_t9 = *((int64_t*)&_1324_x + _1323_t6)==_1323_t8;
    if (_1323_t9) {
        goto BB1516;
    } else {
        goto BB1519;
    }
BB1516:
    _1323_t0 = 2;
    goto BB1518;
BB1519:
    _1323_t10 = 2;
    $bounds_check(_1323_t6, _1323_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1323_t11 = *((int64_t*)&_1324_x + _1323_t6)==_1323_t10;
    if (_1323_t11) {
        goto BB1521;
    } else {
        goto BB1522;
    }
BB1518:
    _1323_$retval = _1323_t0;
    return _1323_$retval;
BB1521:
    _1323_t0 = 22;
    goto BB1518;
BB1522:
    _1323_t12 = 3;
    $bounds_check(_1323_t6, _1323_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1323_t13 = *((int64_t*)&_1324_x + _1323_t6)==_1323_t12;
    if (_1323_t13) {
        goto BB1524;
    } else {
        goto BB1526;
    }
BB1524:
    _1323_t0 = 222;
    goto BB1518;
BB1526:
    _1323_t0 = 0;
    goto BB1518;
}


int main(void) {
  printf("%ld",_1323_main());
  return 0;
}
