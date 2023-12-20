/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _384_main(void);

/* Function definitions */
int64_t _384_main(void){
    int64_t _385_x;
    int64_t _386_i;
    int64_t _384_t3;
    uint8_t _384_t4;
    int64_t _384_t6;
    int64_t _384_t7;
    int64_t _384_t8;
    uint8_t _384_t10;
    int64_t _384_t11;
    int64_t _384_t13;
    int64_t _384_$retval;
    _385_x = 36;
    _386_i = 0;
    goto BB1;
BB1:
    _384_t3 = 70;
    _384_t4 = _386_i < _384_t3;
    if (_384_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _384_t6 = 2;
    _384_t7 = $mod_int64_t(_386_i, _384_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _384_t8 = 0;
    _384_t10 = _384_t7 == _384_t8;
    if (_384_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _385_x = 10;
    goto BB7;
BB7:
    _384_$retval = _385_x;
    return _384_$retval;
BB9:
    _384_t11 = 1;
    _385_x = $add_int64_t(_385_x, _384_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _384_t13 = 1;
    _386_i = $add_int64_t(_386_i, _384_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_384_main());
  return 0;
}
