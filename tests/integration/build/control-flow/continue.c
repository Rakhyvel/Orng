/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _176_main(void);

/* Function definitions */
int64_t _176_main(void) {
    int64_t _177_x;
    int64_t _178_i;
    int64_t _176_t3;
    uint8_t _176_t4;
    int64_t _176_t6;
    int64_t _176_t7;
    int64_t _176_t8;
    uint8_t _176_t10;
    int64_t _176_$retval;
    int64_t _176_t11;
    int64_t _176_t13;
    _177_x = 0;
    _178_i = 0;
    goto BB1;
BB1:
    _176_t3 = 70;
    _176_t4 = _178_i < _176_t3;
    if (_176_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _176_t6 = 2;
    _176_t7 = $mod_int64_t(_178_i, _176_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _176_t8 = 0;
    _176_t10 = _176_t7 == _176_t8;
    if (_176_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _176_$retval = _177_x;
    return _176_$retval;
BB6:
    _176_t13 = 1;
    _178_i = $add_int64_t(_178_i, _176_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _176_t11 = 1;
    _177_x = $add_int64_t(_177_x, _176_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_176_main());
  return 0;
}
