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
    int64_t _430_t3;
    uint8_t _430_t4;
    int64_t _430_t7;
    uint8_t _430_t8;
    int64_t _430_$retval;
    int64_t _430_t11;
    int64_t _430_t9;
    int64_t _430_t15;
    _431_x = 0;
    goto BB480;
BB480:
    _430_t3 = 100;
    _430_t4 = _431_x<_430_t3;
    if (_430_t4) {
        goto BB481;
    } else {
        goto BB485;
    }
BB481:
    _430_t7 = 36;
    _430_t8 = _431_x>=_430_t7;
    if (_430_t8) {
        goto BB483;
    } else {
        goto BB488;
    }
BB485:
    _430_$retval = _431_x;
    return _430_$retval;
BB483:
    _430_t11 = 2;
    _431_x = $add_int64_t(_431_x, _430_t11, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB485;
BB488:
    _430_t9 = 2;
    _431_x = $add_int64_t(_431_x, _430_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _430_t15 = 1;
    _431_x = $add_int64_t(_431_x, _430_t15, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB480;
}


int main(void) {
  printf("%ld",_430_main());
  return 0;
}
