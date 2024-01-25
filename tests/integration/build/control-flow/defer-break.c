/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _431_main(void);


/* Function definitions */
int64_t _431_main(void){
    int64_t _432_x;
    int64_t _431_t2;
    uint8_t _431_t3;
    int64_t _431_t5;
    uint8_t _431_t6;
    int64_t _431_$retval;
    int64_t _431_t9;
    int64_t _431_t7;
    int64_t _431_t13;
    _432_x = 0;
    goto BB490;
BB490:
    _431_t2 = 100;
    _431_t3 = _432_x<_431_t2;
    if (_431_t3) {
        goto BB491;
    } else {
        goto BB495;
    }
BB491:
    _431_t5 = 36;
    _431_t6 = _432_x>=_431_t5;
    if (_431_t6) {
        goto BB493;
    } else {
        goto BB498;
    }
BB495:
    _431_$retval = _432_x;
    return _431_$retval;
BB493:
    _431_t9 = 2;
    _432_x = $add_int64_t(_432_x, _431_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB495;
BB498:
    _431_t7 = 2;
    _432_x = $add_int64_t(_432_x, _431_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _431_t13 = 1;
    _432_x = $add_int64_t(_432_x, _431_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB490;
}


int main(void) {
  printf("%ld",_431_main());
  return 0;
}
