/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _205_main(void);

/* Function definitions */
int64_t _205_main(void) {
    int64_t _206_x;
    int64_t _207_i;
    int64_t _205_t3;
    uint8_t _205_t4;
    int64_t _205_t6;
    int64_t _205_t7;
    int64_t _205_t8;
    uint8_t _205_t10;
    int64_t _205_$retval;
    int64_t _205_t11;
    int64_t _205_t13;
    _206_x = 0;
    _207_i = 0;
    goto BB1;
BB1:
    _205_t3 = 70;
    _205_t4 = _207_i < _205_t3;
    if (_205_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _205_t6 = 2;
    _205_t7 = $mod_int64_t(_207_i, _205_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _205_t8 = 0;
    _205_t10 = _205_t7 == _205_t8;
    if (_205_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _205_$retval = _206_x;
    return _205_$retval;
BB6:
    _205_t13 = 1;
    _207_i = $add_int64_t(_207_i, _205_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _205_t11 = 1;
    _206_x = $add_int64_t(_206_x, _205_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_205_main());
  return 0;
}
