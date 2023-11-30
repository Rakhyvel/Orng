/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _280_main(void);

/* Function definitions */
int64_t _280_main(void) {
    int64_t _281_x;
    int64_t _282_i;
    int64_t _280_t3;
    uint8_t _280_t4;
    int64_t _280_t6;
    int64_t _280_t7;
    int64_t _280_t8;
    uint8_t _280_t10;
    int64_t _280_t11;
    int64_t _280_t13;
    int64_t _280_$retval;
    _281_x = 36;
    _282_i = 0;
    goto BB1;
BB1:
    _280_t3 = 70;
    _280_t4 = _282_i < _280_t3;
    if (_280_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _280_t6 = 2;
    _280_t7 = $mod_int64_t(_282_i, _280_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _280_t8 = 0;
    _280_t10 = _280_t7 == _280_t8;
    if (_280_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _281_x = 10;
    goto BB7;
BB7:
    _280_$retval = _281_x;
    return _280_$retval;
BB9:
    _280_t11 = 1;
    _281_x = $add_int64_t(_281_x, _280_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _280_t13 = 1;
    _282_i = $add_int64_t(_282_i, _280_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_280_main());
  return 0;
}
