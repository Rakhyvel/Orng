/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _438_main(void);


/* Function definitions */
int64_t _438_main(void){
    int64_t _439_x;
    int64_t _438_t3;
    uint8_t _438_t4;
    int64_t _438_t7;
    int64_t _438_t8;
    int64_t _438_t9;
    uint8_t _438_t11;
    int64_t _438_t12;
    int64_t _438_$retval;
    int64_t _438_t14;
    _439_x = 17;
    goto BB493;
BB493:
    _438_t3 = 36;
    _438_t4 = _439_x<_438_t3;
    if (_438_t4) {
        goto BB494;
    } else {
        goto BB506;
    }
BB494:
    _438_t7 = 2;
    _438_t8 = $mod_int64_t(_439_x, _438_t7, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _438_t9 = 0;
    _438_t11 = _438_t8==_438_t9;
    if (_438_t11) {
        goto BB498;
    } else {
        goto BB502;
    }
BB506:
    _438_$retval = _439_x;
    return _438_$retval;
BB498:
    _438_t14 = 9;
    _439_x = $add_int64_t(_439_x, _438_t14, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB493;
BB502:
    _438_t12 = 1;
    _439_x = $add_int64_t(_439_x, _438_t12, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB498;
}


int main(void) {
  printf("%ld",_438_main());
  return 0;
}
