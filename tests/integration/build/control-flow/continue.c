/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _195_main(void);

/* Function definitions */
int64_t _195_main(void) {
    int64_t _196_x;
    int64_t _197_i;
    int64_t _195_t3;
    uint8_t _195_t4;
    int64_t _195_t6;
    int64_t _195_t7;
    int64_t _195_t8;
    uint8_t _195_t10;
    int64_t _195_$retval;
    int64_t _195_t11;
    int64_t _195_t13;
    _196_x = 0;
    _197_i = 0;
    goto BB1;
BB1:
    _195_t3 = 70;
    _195_t4 = _197_i < _195_t3;
    if (_195_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _195_t6 = 2;
    _195_t7 = $mod_int64_t(_197_i, _195_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _195_t8 = 0;
    _195_t10 = _195_t7 == _195_t8;
    if (_195_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _195_$retval = _196_x;
    return _195_$retval;
BB6:
    _195_t13 = 1;
    _197_i = $add_int64_t(_197_i, _195_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _195_t11 = 1;
    _196_x = $add_int64_t(_196_x, _195_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_195_main());
  return 0;
}
