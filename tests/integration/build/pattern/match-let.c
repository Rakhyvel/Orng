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
int64_t _1304_main(void);


/* Function definitions */
int64_t _1304_main(void){
    int64_t _1304_t2;
    int64_t _1304_t3;
    int64_t _1304_t4;
    struct struct0 _1305_x;
    int64_t _1304_t6;
    int64_t _1304_t7;
    int64_t _1304_t8;
    uint8_t _1304_t9;
    int64_t _1304_t0;
    int64_t _1304_t12;
    uint8_t _1304_t13;
    int64_t _1304_$retval;
    int64_t _1304_t10;
    uint8_t _1304_t11;
    _1304_t2 = 1;
    _1304_t3 = 2;
    _1304_t4 = 3;
    _1305_x = (struct struct0) {_1304_t2, _1304_t3, _1304_t4};
    _1304_t6 = 2;
    _1304_t7 = 3;
    _1304_t8 = 1;
    $bounds_check(_1304_t6, _1304_t7, "tests/integration/pattern/match-let.orng:4:10:\n        1 => 2\n        ^");
    _1304_t9 = *((int64_t*)&_1305_x + _1304_t6)==_1304_t8;
    if (_1304_t9) {
        goto BB1494;
    } else {
        goto BB1497;
    }
BB1494:
    _1304_t0 = 2;
    goto BB1496;
BB1497:
    _1304_t10 = 2;
    $bounds_check(_1304_t6, _1304_t7, "tests/integration/pattern/match-let.orng:5:10:\n        2 => 22\n        ^");
    _1304_t11 = *((int64_t*)&_1305_x + _1304_t6)==_1304_t10;
    if (_1304_t11) {
        goto BB1499;
    } else {
        goto BB1500;
    }
BB1496:
    _1304_$retval = _1304_t0;
    return _1304_$retval;
BB1499:
    _1304_t0 = 22;
    goto BB1496;
BB1500:
    _1304_t12 = 3;
    $bounds_check(_1304_t6, _1304_t7, "tests/integration/pattern/match-let.orng:6:10:\n        3 => 222\n        ^");
    _1304_t13 = *((int64_t*)&_1305_x + _1304_t6)==_1304_t12;
    if (_1304_t13) {
        goto BB1502;
    } else {
        goto BB1504;
    }
BB1502:
    _1304_t0 = 222;
    goto BB1496;
BB1504:
    _1304_t0 = 0;
    goto BB1496;
}


int main(void) {
  printf("%ld",_1304_main());
  return 0;
}
