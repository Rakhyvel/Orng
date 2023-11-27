/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _128_main(void);

/* Function definitions */
int64_t _128_main(void) {
    int64_t _129_x;
    int64_t _130_i;
    int64_t _128_t3;
    uint8_t _128_t4;
    int64_t _128_t6;
    int64_t _128_t7;
    int64_t _128_t8;
    uint8_t _128_t10;
    int64_t _128_t11;
    int64_t _128_t13;
    int64_t _128_$retval;
    _129_x = 36;
    _130_i = 0;
    goto BB1;
BB1:
    _128_t3 = 70;
    _128_t4 = _130_i < _128_t3;
    if (_128_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _128_t6 = 2;
    _128_t7 = $mod_int64_t(_130_i, _128_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _128_t8 = 0;
    _128_t10 = _128_t7 == _128_t8;
    if (_128_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _129_x = 10;
    goto BB7;
BB7:
    _128_$retval = _129_x;
    return _128_$retval;
BB9:
    _128_t11 = 1;
    _129_x = $add_int64_t(_129_x, _128_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _128_t13 = 1;
    _130_i = $add_int64_t(_130_i, _128_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_128_main());
  return 0;
}
