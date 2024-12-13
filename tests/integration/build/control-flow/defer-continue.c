/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _460_main(void);


/* Function definitions */
int64_t _460_main(void){
    int64_t _461_x;
    int64_t _460_t3;
    uint8_t _460_t4;
    int64_t _460_t7;
    int64_t _460_t8;
    int64_t _460_t9;
    uint8_t _460_t11;
    int64_t _460_t12;
    int64_t _460_$retval;
    int64_t _460_t14;
    _461_x = 17;
    goto BB514;
BB514:
    _460_t3 = 36;
    _460_t4 = _461_x<_460_t3;
    if (_460_t4) {
        goto BB515;
    } else {
        goto BB527;
    }
BB515:
    _460_t7 = 2;
    _460_t8 = $mod_int64_t(_461_x, _460_t7, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _460_t9 = 0;
    _460_t11 = _460_t8==_460_t9;
    if (_460_t11) {
        goto BB519;
    } else {
        goto BB523;
    }
BB527:
    _460_$retval = _461_x;
    return _460_$retval;
BB519:
    _460_t14 = 9;
    _461_x = $add_int64_t(_461_x, _460_t14, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB514;
BB523:
    _460_t12 = 1;
    _461_x = $add_int64_t(_461_x, _460_t12, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB519;
}


int main(void) {
  printf("%ld",_460_main());
  return 0;
}
