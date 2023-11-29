/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _286_main(void);

/* Function definitions */
int64_t _286_main(void) {
    int64_t _287_x;
    int64_t _288_i;
    int64_t _286_t3;
    uint8_t _286_t4;
    int64_t _286_t6;
    int64_t _286_t7;
    int64_t _286_t8;
    uint8_t _286_t10;
    int64_t _286_$retval;
    int64_t _286_t11;
    int64_t _286_t13;
    _287_x = 0;
    _288_i = 0;
    goto BB1;
BB1:
    _286_t3 = 70;
    _286_t4 = _288_i < _286_t3;
    if (_286_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _286_t6 = 2;
    _286_t7 = $mod_int64_t(_288_i, _286_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _286_t8 = 0;
    _286_t10 = _286_t7 == _286_t8;
    if (_286_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _286_$retval = _287_x;
    return _286_$retval;
BB6:
    _286_t13 = 1;
    _288_i = $add_int64_t(_288_i, _286_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _286_t11 = 1;
    _287_x = $add_int64_t(_287_x, _286_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_286_main());
  return 0;
}
