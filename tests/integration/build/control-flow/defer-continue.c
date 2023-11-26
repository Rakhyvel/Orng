/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _119_main(void);

/* Function definitions */
int64_t _119_main(void) {
    int64_t _120_x;
    int64_t _119_t2;
    uint8_t _119_t3;
    int64_t _119_t5;
    int64_t _119_t6;
    int64_t _119_t7;
    uint8_t _119_t9;
    uint8_t _119_t8;
    int64_t _119_t12;
    int64_t _119_$retval;
    int64_t _119_t10;
    _120_x = 17;
    goto BB1;
BB1:
    _119_t2 = 36;
    _119_t3 = _120_x < _119_t2;
    if (_119_t3) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    _119_t5 = 2;
    _119_t6 = $mod_int64_t(_120_x, _119_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _119_t7 = 0;
    _119_t9 = _119_t6 == _119_t7;
    if (_119_t9) {
        goto BB3;
    } else {
        goto BB11;
    }
BB14:
    _119_$retval = _120_x;
    return _119_$retval;
BB3:
    _119_t8 = 1;
    goto BB4;
BB11:
    _119_t8 = 0;
    goto BB4;
BB4:
    if (_119_t8) {
        goto BB6;
    } else {
        goto BB10;
    }
BB6:
    _119_t12 = 9;
    _120_x = $add_int64_t(_120_x, _119_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB1;
BB10:
    _119_t10 = 1;
    _120_x = $add_int64_t(_120_x, _119_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_119_main());
  return 0;
}
