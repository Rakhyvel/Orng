/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _446_main(void);


/* Function definitions */
int64_t _446_main(void){
    int64_t _447_x;
    int64_t _446_t3;
    uint8_t _446_t4;
    int64_t _446_t7;
    int64_t _446_t8;
    int64_t _446_t9;
    uint8_t _446_t11;
    int64_t _446_t12;
    int64_t _446_$retval;
    int64_t _446_t14;
    _447_x = 17;
    goto BB499;
BB499:
    _446_t3 = 36;
    _446_t4 = _447_x<_446_t3;
    if (_446_t4) {
        goto BB500;
    } else {
        goto BB512;
    }
BB500:
    _446_t7 = 2;
    _446_t8 = $mod_int64_t(_447_x, _446_t7, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _446_t9 = 0;
    _446_t11 = _446_t8==_446_t9;
    if (_446_t11) {
        goto BB504;
    } else {
        goto BB508;
    }
BB512:
    _446_$retval = _447_x;
    return _446_$retval;
BB504:
    _446_t14 = 9;
    _447_x = $add_int64_t(_447_x, _446_t14, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB499;
BB508:
    _446_t12 = 1;
    _447_x = $add_int64_t(_447_x, _446_t12, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB504;
}


int main(void) {
  printf("%ld",_446_main());
  return 0;
}
