/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _336_main(void);

/* Function definitions */
int64_t _336_main(void){
    int64_t _337_x;
    int64_t _338_i;
    int64_t _336_t3;
    uint8_t _336_t4;
    int64_t _336_t6;
    int64_t _336_t7;
    int64_t _336_t8;
    uint8_t _336_t10;
    int64_t _336_$retval;
    int64_t _336_t11;
    int64_t _336_t13;
    _337_x = 0;
    _338_i = 0;
    goto BB1;
BB1:
    _336_t3 = 70;
    _336_t4 = _338_i < _336_t3;
    if (_336_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _336_t6 = 2;
    _336_t7 = $mod_int64_t(_338_i, _336_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _336_t8 = 0;
    _336_t10 = _336_t7 == _336_t8;
    if (_336_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _336_$retval = _337_x;
    return _336_$retval;
BB6:
    _336_t13 = 1;
    _338_i = $add_int64_t(_338_i, _336_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _336_t11 = 1;
    _337_x = $add_int64_t(_337_x, _336_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_336_main());
  return 0;
}
