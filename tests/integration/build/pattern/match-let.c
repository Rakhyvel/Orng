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
int64_t _1340_main(void);


/* Function definitions */
int64_t _1340_main(void){
    int64_t _1340_t2;
    int64_t _1340_t3;
    int64_t _1340_t4;
    struct struct0 _1341_x;
    int64_t _1340_t6;
    int64_t _1340_t7;
    int64_t _1340_t8;
    uint8_t _1340_t9;
    int64_t _1340_t0;
    int64_t _1340_t12;
    uint8_t _1340_t13;
    int64_t _1340_$retval;
    int64_t _1340_t10;
    uint8_t _1340_t11;
    _1340_t2 = 1;
    _1340_t3 = 2;
    _1340_t4 = 3;
    _1341_x = (struct struct0) {_1340_t2, _1340_t3, _1340_t4};
    _1340_t6 = 2;
    _1340_t7 = 3;
    _1340_t8 = 1;
    $bounds_check(_1340_t6, _1340_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1340_t9 = *((int64_t*)&_1341_x + _1340_t6)==_1340_t8;
    if (_1340_t9) {
        goto BB1534;
    } else {
        goto BB1537;
    }
BB1534:
    _1340_t0 = 2;
    goto BB1536;
BB1537:
    _1340_t10 = 2;
    $bounds_check(_1340_t6, _1340_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1340_t11 = *((int64_t*)&_1341_x + _1340_t6)==_1340_t10;
    if (_1340_t11) {
        goto BB1539;
    } else {
        goto BB1540;
    }
BB1536:
    _1340_$retval = _1340_t0;
    return _1340_$retval;
BB1539:
    _1340_t0 = 22;
    goto BB1536;
BB1540:
    _1340_t12 = 3;
    $bounds_check(_1340_t6, _1340_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1340_t13 = *((int64_t*)&_1341_x + _1340_t6)==_1340_t12;
    if (_1340_t13) {
        goto BB1542;
    } else {
        goto BB1544;
    }
BB1542:
    _1340_t0 = 222;
    goto BB1536;
BB1544:
    _1340_t0 = 0;
    goto BB1536;
}


int main(void) {
  printf("%ld",_1340_main());
  return 0;
}
