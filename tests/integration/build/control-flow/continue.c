/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _105_main(void);

/* Function definitions */
int64_t _105_main(void) {
    int64_t _106_x;
    int64_t _107_i;
    int64_t _105_t3;
    uint8_t _105_t4;
    int64_t _105_t6;
    int64_t _105_t7;
    int64_t _105_t8;
    uint8_t _105_t10;
    uint8_t _105_t9;
    int64_t _105_$retval;
    int64_t _105_t13;
    int64_t _105_t11;
    _106_x = 0;
    _107_i = 0;
    goto BB1;
BB1:
    _105_t3 = 70;
    _105_t4 = _107_i < _105_t3;
    if (_105_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _105_t6 = 2;
    _105_t7 = $mod_int64_t(_107_i, _105_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _105_t8 = 0;
    _105_t10 = _105_t7 == _105_t8;
    if (_105_t10) {
        goto BB3;
    } else {
        goto BB10;
    }
BB13:
    _105_$retval = _106_x;
    return _105_$retval;
BB3:
    _105_t9 = 1;
    goto BB4;
BB10:
    _105_t9 = 0;
    goto BB4;
BB4:
    if (_105_t9) {
        goto BB6;
    } else {
        goto BB8;
    }
BB6:
    _105_t13 = 1;
    _107_i = $add_int64_t(_107_i, _105_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _105_t11 = 1;
    _106_x = $add_int64_t(_106_x, _105_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_105_main());
  return 0;
}
