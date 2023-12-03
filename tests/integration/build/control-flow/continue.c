/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _168_main(void);

/* Function definitions */
int64_t _168_main(void) {
    int64_t _169_x;
    int64_t _170_i;
    int64_t _168_t3;
    uint8_t _168_t4;
    int64_t _168_t6;
    int64_t _168_t7;
    int64_t _168_t8;
    uint8_t _168_t10;
    int64_t _168_$retval;
    int64_t _168_t11;
    int64_t _168_t13;
    _169_x = 0;
    _170_i = 0;
    goto BB1;
BB1:
    _168_t3 = 70;
    _168_t4 = _170_i < _168_t3;
    if (_168_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _168_t6 = 2;
    _168_t7 = $mod_int64_t(_170_i, _168_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _168_t8 = 0;
    _168_t10 = _168_t7 == _168_t8;
    if (_168_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _168_$retval = _169_x;
    return _168_$retval;
BB6:
    _168_t13 = 1;
    _170_i = $add_int64_t(_170_i, _168_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _168_t11 = 1;
    _169_x = $add_int64_t(_169_x, _168_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_168_main());
  return 0;
}
