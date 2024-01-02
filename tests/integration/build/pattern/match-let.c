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
int64_t _1216_main(void);

/* Function definitions */
int64_t _1216_main(void){
    int64_t _1216_t2;
    int64_t _1216_t3;
    int64_t _1216_t4;
    struct struct0 _1217_x;
    int64_t _1216_t5;
    int64_t _1216_t6;
    int64_t _1216_t7;
    uint8_t _1216_t8;
    int64_t _1216_t0;
    int64_t _1216_t11;
    uint8_t _1216_t12;
    int64_t _1216_$retval;
    int64_t _1216_t9;
    uint8_t _1216_t10;
    _1216_t2 = 1;
    _1216_t3 = 2;
    _1216_t4 = 3;
    _1217_x = (struct struct0) {_1216_t2, _1216_t3, _1216_t4};
    _1216_t5 = 2;
    _1216_t6 = 3;
    _1216_t7 = 1;
    $bounds_check(_1216_t5, _1216_t6, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1216_t8 = *((int64_t*)&_1217_x + _1216_t5)==_1216_t7;
    if (_1216_t8) {
        goto BB1436;
    } else {
        goto BB1439;
    }
BB1436:
    _1216_t0 = 2;
    goto BB1438;
BB1439:
    _1216_t9 = 2;
    $bounds_check(_1216_t5, _1216_t6, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1216_t10 = *((int64_t*)&_1217_x + _1216_t5)==_1216_t9;
    if (_1216_t10) {
        goto BB1441;
    } else {
        goto BB1442;
    }
BB1438:
    _1216_$retval = _1216_t0;
    return _1216_$retval;
BB1441:
    _1216_t0 = 22;
    goto BB1438;
BB1442:
    _1216_t11 = 3;
    $bounds_check(_1216_t5, _1216_t6, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1216_t12 = *((int64_t*)&_1217_x + _1216_t5)==_1216_t11;
    if (_1216_t12) {
        goto BB1444;
    } else {
        goto BB1446;
    }
BB1444:
    _1216_t0 = 222;
    goto BB1438;
BB1446:
    _1216_t0 = 0;
    goto BB1438;
}

int main(void) {
  printf("%ld",_1216_main());
  return 0;
}
