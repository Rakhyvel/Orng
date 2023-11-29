/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _197_main(void);

/* Function definitions */
int64_t _197_main(void) {
    int64_t _198_x;
    int64_t _199_i;
    int64_t _197_t3;
    uint8_t _197_t4;
    int64_t _197_t6;
    int64_t _197_t7;
    int64_t _197_t8;
    uint8_t _197_t10;
    int64_t _197_t11;
    int64_t _197_t13;
    int64_t _197_$retval;
    _198_x = 36;
    _199_i = 0;
    goto BB1;
BB1:
    _197_t3 = 70;
    _197_t4 = _199_i < _197_t3;
    if (_197_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _197_t6 = 2;
    _197_t7 = $mod_int64_t(_199_i, _197_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _197_t8 = 0;
    _197_t10 = _197_t7 == _197_t8;
    if (_197_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _198_x = 10;
    goto BB7;
BB7:
    _197_$retval = _198_x;
    return _197_$retval;
BB9:
    _197_t11 = 1;
    _198_x = $add_int64_t(_198_x, _197_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _197_t13 = 1;
    _199_i = $add_int64_t(_199_i, _197_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_197_main());
  return 0;
}
