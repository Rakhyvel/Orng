/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _278_main(void);

/* Function definitions */
int64_t _278_main(void) {
    int64_t _279_x;
    int64_t _280_i;
    int64_t _278_t3;
    uint8_t _278_t4;
    int64_t _278_t6;
    int64_t _278_t7;
    int64_t _278_t8;
    uint8_t _278_t10;
    int64_t _278_t11;
    int64_t _278_t13;
    int64_t _278_$retval;
    _279_x = 36;
    _280_i = 0;
    goto BB1;
BB1:
    _278_t3 = 70;
    _278_t4 = _280_i < _278_t3;
    if (_278_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _278_t6 = 2;
    _278_t7 = $mod_int64_t(_280_i, _278_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _278_t8 = 0;
    _278_t10 = _278_t7 == _278_t8;
    if (_278_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _279_x = 10;
    goto BB7;
BB7:
    _278_$retval = _279_x;
    return _278_$retval;
BB9:
    _278_t11 = 1;
    _279_x = $add_int64_t(_279_x, _278_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _278_t13 = 1;
    _280_i = $add_int64_t(_280_i, _278_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_278_main());
  return 0;
}
