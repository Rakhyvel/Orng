/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _309_main(void);

/* Function definitions */
int64_t _309_main(void) {
    int64_t _310_x;
    int64_t _311_i;
    int64_t _309_t3;
    uint8_t _309_t4;
    int64_t _309_t6;
    int64_t _309_t7;
    int64_t _309_t8;
    uint8_t _309_t10;
    int64_t _309_t11;
    int64_t _309_t13;
    int64_t _309_$retval;
    _310_x = 36;
    _311_i = 0;
    goto BB1;
BB1:
    _309_t3 = 70;
    _309_t4 = _311_i < _309_t3;
    if (_309_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _309_t6 = 2;
    _309_t7 = $mod_int64_t(_311_i, _309_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _309_t8 = 0;
    _309_t10 = _309_t7 == _309_t8;
    if (_309_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _310_x = 10;
    goto BB7;
BB7:
    _309_$retval = _310_x;
    return _309_$retval;
BB9:
    _309_t11 = 1;
    _310_x = $add_int64_t(_310_x, _309_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _309_t13 = 1;
    _311_i = $add_int64_t(_311_i, _309_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_309_main());
  return 0;
}
