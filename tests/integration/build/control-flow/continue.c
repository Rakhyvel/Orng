/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _482_main(void);

/* Function definitions */
int64_t _482_main(void){
    int64_t _483_x;
    int64_t _484_i;
    int64_t _482_t3;
    uint8_t _482_t4;
    int64_t _482_t6;
    int64_t _482_t7;
    int64_t _482_t8;
    uint8_t _482_t10;
    int64_t _482_$retval;
    int64_t _482_t11;
    int64_t _482_t13;
    _483_x = 0;
    _484_i = 0;
    goto BB1;
BB1:
    _482_t3 = 70;
    _482_t4 = _484_i < _482_t3;
    if (_482_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _482_t6 = 2;
    _482_t7 = $mod_int64_t(_484_i, _482_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _482_t8 = 0;
    _482_t10 = _482_t7 == _482_t8;
    if (_482_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _482_$retval = _483_x;
    return _482_$retval;
BB6:
    _482_t13 = 1;
    _484_i = $add_int64_t(_484_i, _482_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _482_t11 = 1;
    _483_x = $add_int64_t(_483_x, _482_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_482_main());
  return 0;
}
