/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _481_main(void);

/* Function definitions */
int64_t _481_main(void){
    int64_t _482_x;
    int64_t _483_i;
    int64_t _481_t3;
    uint8_t _481_t4;
    int64_t _481_t6;
    int64_t _481_t7;
    int64_t _481_t8;
    uint8_t _481_t10;
    int64_t _481_$retval;
    int64_t _481_t11;
    int64_t _481_t13;
    _482_x = 0;
    _483_i = 0;
    goto BB1;
BB1:
    _481_t3 = 70;
    _481_t4 = _483_i < _481_t3;
    if (_481_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _481_t6 = 2;
    _481_t7 = $mod_int64_t(_483_i, _481_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _481_t8 = 0;
    _481_t10 = _481_t7 == _481_t8;
    if (_481_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _481_$retval = _482_x;
    return _481_$retval;
BB6:
    _481_t13 = 1;
    _483_i = $add_int64_t(_483_i, _481_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _481_t11 = 1;
    _482_x = $add_int64_t(_482_x, _481_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_481_main());
  return 0;
}
