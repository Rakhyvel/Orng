/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _136_main(void);

/* Function definitions */
int64_t _136_main(void) {
    int64_t _137_x;
    int64_t _138_i;
    int64_t _136_t3;
    uint8_t _136_t4;
    int64_t _136_t6;
    int64_t _136_t7;
    int64_t _136_t8;
    uint8_t _136_t10;
    int64_t _136_$retval;
    int64_t _136_t11;
    int64_t _136_t13;
    _137_x = 0;
    _138_i = 0;
    goto BB1;
BB1:
    _136_t3 = 70;
    _136_t4 = _138_i < _136_t3;
    if (_136_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _136_t6 = 2;
    _136_t7 = $mod_int64_t(_138_i, _136_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _136_t8 = 0;
    _136_t10 = _136_t7 == _136_t8;
    if (_136_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _136_$retval = _137_x;
    return _136_$retval;
BB6:
    _136_t13 = 1;
    _138_i = $add_int64_t(_138_i, _136_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _136_t11 = 1;
    _137_x = $add_int64_t(_137_x, _136_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_136_main());
  return 0;
}
