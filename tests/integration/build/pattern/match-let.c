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
int64_t _1263_main(void);


/* Function definitions */
int64_t _1263_main(void){
    int64_t _1263_t2;
    int64_t _1263_t3;
    int64_t _1263_t4;
    struct struct0 _1264_x;
    int64_t _1263_t5;
    int64_t _1263_t6;
    int64_t _1263_t7;
    uint8_t _1263_t8;
    int64_t _1263_t0;
    int64_t _1263_t11;
    uint8_t _1263_t12;
    int64_t _1263_$retval;
    int64_t _1263_t9;
    uint8_t _1263_t10;
    _1263_t2 = 1;
    _1263_t3 = 2;
    _1263_t4 = 3;
    _1264_x = (struct struct0) {_1263_t2, _1263_t3, _1263_t4};
    _1263_t5 = 2;
    _1263_t6 = 3;
    _1263_t7 = 1;
    $bounds_check(_1263_t5, _1263_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1263_t8 = *((int64_t*)&_1264_x + _1263_t5)==_1263_t7;
    if (_1263_t8) {
        goto BB1478;
    } else {
        goto BB1481;
    }
BB1478:
    _1263_t0 = 2;
    goto BB1480;
BB1481:
    _1263_t9 = 2;
    $bounds_check(_1263_t5, _1263_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1263_t10 = *((int64_t*)&_1264_x + _1263_t5)==_1263_t9;
    if (_1263_t10) {
        goto BB1483;
    } else {
        goto BB1484;
    }
BB1480:
    _1263_$retval = _1263_t0;
    return _1263_$retval;
BB1483:
    _1263_t0 = 22;
    goto BB1480;
BB1484:
    _1263_t11 = 3;
    $bounds_check(_1263_t5, _1263_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1263_t12 = *((int64_t*)&_1264_x + _1263_t5)==_1263_t11;
    if (_1263_t12) {
        goto BB1486;
    } else {
        goto BB1488;
    }
BB1486:
    _1263_t0 = 222;
    goto BB1480;
BB1488:
    _1263_t0 = 0;
    goto BB1480;
}


int main(void) {
  printf("%ld",_1263_main());
  return 0;
}
