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
int64_t _1232_main(void);


/* Function definitions */
int64_t _1232_main(void){
    int64_t _1232_t2;
    int64_t _1232_t3;
    int64_t _1232_t4;
    struct struct0 _1233_x;
    int64_t _1232_t6;
    int64_t _1232_t7;
    int64_t _1232_t8;
    uint8_t _1232_t9;
    int64_t _1232_t0;
    int64_t _1232_t12;
    uint8_t _1232_t13;
    int64_t _1232_$retval;
    int64_t _1232_t10;
    uint8_t _1232_t11;
    _1232_t2 = 1;
    _1232_t3 = 2;
    _1232_t4 = 3;
    _1233_x = (struct struct0) {_1232_t2, _1232_t3, _1232_t4};
    _1232_t6 = 2;
    _1232_t7 = 3;
    _1232_t8 = 1;
    $bounds_check(_1232_t6, _1232_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1232_t9 = *((int64_t*)&_1233_x + _1232_t6)==_1232_t8;
    if (_1232_t9) {
        goto BB1419;
    } else {
        goto BB1422;
    }
BB1419:
    _1232_t0 = 2;
    goto BB1421;
BB1422:
    _1232_t10 = 2;
    $bounds_check(_1232_t6, _1232_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1232_t11 = *((int64_t*)&_1233_x + _1232_t6)==_1232_t10;
    if (_1232_t11) {
        goto BB1424;
    } else {
        goto BB1425;
    }
BB1421:
    _1232_$retval = _1232_t0;
    return _1232_$retval;
BB1424:
    _1232_t0 = 22;
    goto BB1421;
BB1425:
    _1232_t12 = 3;
    $bounds_check(_1232_t6, _1232_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1232_t13 = *((int64_t*)&_1233_x + _1232_t6)==_1232_t12;
    if (_1232_t13) {
        goto BB1427;
    } else {
        goto BB1429;
    }
BB1427:
    _1232_t0 = 222;
    goto BB1421;
BB1429:
    _1232_t0 = 0;
    goto BB1421;
}


int main(void) {
  printf("%ld",_1232_main());
  return 0;
}
