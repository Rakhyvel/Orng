/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _187_main(void);

/* Function definitions */
int64_t _187_main(void) {
    int64_t _188_x;
    int64_t _189_i;
    int64_t _187_t3;
    uint8_t _187_t4;
    int64_t _187_t6;
    int64_t _187_t7;
    int64_t _187_t8;
    uint8_t _187_t10;
    int64_t _187_t11;
    int64_t _187_t13;
    int64_t _187_$retval;
    _188_x = 36;
    _189_i = 0;
    goto BB1;
BB1:
    _187_t3 = 70;
    _187_t4 = _189_i < _187_t3;
    if (_187_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _187_t6 = 2;
    _187_t7 = $mod_int64_t(_189_i, _187_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _187_t8 = 0;
    _187_t10 = _187_t7 == _187_t8;
    if (_187_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _188_x = 10;
    goto BB7;
BB7:
    _187_$retval = _188_x;
    return _187_$retval;
BB9:
    _187_t11 = 1;
    _188_x = $add_int64_t(_188_x, _187_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _187_t13 = 1;
    _189_i = $add_int64_t(_189_i, _187_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_187_main());
  return 0;
}
