/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _430_main(void);


/* Function definitions */
int64_t _430_main(void){
    int64_t _431_x;
    int64_t _432_i;
    int64_t _430_t5;
    uint8_t _430_t6;
    int64_t _430_t8;
    int64_t _430_t9;
    int64_t _430_t10;
    uint8_t _430_t12;
    int64_t _430_$retval;
    int64_t _430_t13;
    int64_t _430_t15;
    _431_x = 0;
    _432_i = 0;
    goto BB472;
BB472:
    _430_t5 = 70;
    _430_t6 = _432_i<_430_t5;
    if (_430_t6) {
        goto BB473;
    } else {
        goto BB484;
    }
BB473:
    _430_t8 = 2;
    _430_t9 = $mod_int64_t(_432_i, _430_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _430_t10 = 0;
    _430_t12 = _430_t9==_430_t10;
    if (_430_t12) {
        goto BB477;
    } else {
        goto BB479;
    }
BB484:
    _430_$retval = _431_x;
    return _430_$retval;
BB477:
    _430_t15 = 1;
    _432_i = $add_int64_t(_432_i, _430_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB472;
BB479:
    _430_t13 = 1;
    _431_x = $add_int64_t(_431_x, _430_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB477;
}


int main(void) {
  printf("%ld",_430_main());
  return 0;
}
