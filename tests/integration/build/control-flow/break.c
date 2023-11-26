/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _5_main(void);

/* Function definitions */
int64_t _5_main(void) {
    int64_t _6_x;
    int64_t _7_i;
    int64_t _5_t3;
    uint8_t _5_t4;
    int64_t _5_t6;
    int64_t _5_t7;
    int64_t _5_t8;
    uint8_t _5_t10;
    uint8_t _5_t9;
    int64_t _5_t11;
    int64_t _5_t13;
    int64_t _5_$retval;
    _6_x = 36;
    _7_i = 0;
    goto BB1;
BB1:
    _5_t3 = 70;
    _5_t4 = _7_i < _5_t3;
    if (_5_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _5_t6 = 2;
    _5_t7 = $mod_int64_t(_7_i, _5_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _5_t8 = 0;
    _5_t10 = _5_t7 == _5_t8;
    if (_5_t10) {
        goto BB3;
    } else {
        goto BB12;
    }
BB13:
    _6_x = 10;
    goto BB7;
BB3:
    _5_t9 = 1;
    goto BB4;
BB12:
    _5_t9 = 0;
    goto BB4;
BB7:
    _5_$retval = _6_x;
    return _5_$retval;
BB4:
    if (_5_t9) {
        goto BB7;
    } else {
        goto BB9;
    }
BB9:
    _5_t11 = 1;
    _6_x = $add_int64_t(_6_x, _5_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _5_t13 = 1;
    _7_i = $add_int64_t(_7_i, _5_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_5_main());
  return 0;
}
