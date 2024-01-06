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
int64_t _1221_main(void);

/* Function definitions */
int64_t _1221_main(void){
    int64_t _1221_t2;
    int64_t _1221_t3;
    int64_t _1221_t4;
    struct struct0 _1222_x;
    int64_t _1221_t5;
    int64_t _1221_t6;
    int64_t _1221_t7;
    uint8_t _1221_t8;
    int64_t _1221_t0;
    int64_t _1221_t11;
    uint8_t _1221_t12;
    int64_t _1221_$retval;
    int64_t _1221_t9;
    uint8_t _1221_t10;
    _1221_t2 = 1;
    _1221_t3 = 2;
    _1221_t4 = 3;
    _1222_x = (struct struct0) {_1221_t2, _1221_t3, _1221_t4};
    _1221_t5 = 2;
    _1221_t6 = 3;
    _1221_t7 = 1;
    $bounds_check(_1221_t5, _1221_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1221_t8 = *((int64_t*)&_1222_x + _1221_t5)==_1221_t7;
    if (_1221_t8) {
        goto BB1440;
    } else {
        goto BB1443;
    }
BB1440:
    _1221_t0 = 2;
    goto BB1442;
BB1443:
    _1221_t9 = 2;
    $bounds_check(_1221_t5, _1221_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1221_t10 = *((int64_t*)&_1222_x + _1221_t5)==_1221_t9;
    if (_1221_t10) {
        goto BB1445;
    } else {
        goto BB1446;
    }
BB1442:
    _1221_$retval = _1221_t0;
    return _1221_$retval;
BB1445:
    _1221_t0 = 22;
    goto BB1442;
BB1446:
    _1221_t11 = 3;
    $bounds_check(_1221_t5, _1221_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1221_t12 = *((int64_t*)&_1222_x + _1221_t5)==_1221_t11;
    if (_1221_t12) {
        goto BB1448;
    } else {
        goto BB1450;
    }
BB1448:
    _1221_t0 = 222;
    goto BB1442;
BB1450:
    _1221_t0 = 0;
    goto BB1442;
}

int main(void) {
  printf("%ld",_1221_main());
  return 0;
}
