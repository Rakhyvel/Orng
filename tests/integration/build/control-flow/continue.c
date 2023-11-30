/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _288_main(void);

/* Function definitions */
int64_t _288_main(void) {
    int64_t _289_x;
    int64_t _290_i;
    int64_t _288_t3;
    uint8_t _288_t4;
    int64_t _288_t6;
    int64_t _288_t7;
    int64_t _288_t8;
    uint8_t _288_t10;
    int64_t _288_$retval;
    int64_t _288_t11;
    int64_t _288_t13;
    _289_x = 0;
    _290_i = 0;
    goto BB1;
BB1:
    _288_t3 = 70;
    _288_t4 = _290_i < _288_t3;
    if (_288_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _288_t6 = 2;
    _288_t7 = $mod_int64_t(_290_i, _288_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _288_t8 = 0;
    _288_t10 = _288_t7 == _288_t8;
    if (_288_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _288_$retval = _289_x;
    return _288_$retval;
BB6:
    _288_t13 = 1;
    _290_i = $add_int64_t(_290_i, _288_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _288_t11 = 1;
    _289_x = $add_int64_t(_289_x, _288_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_288_main());
  return 0;
}
