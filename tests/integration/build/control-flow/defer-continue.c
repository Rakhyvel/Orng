/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _458_main(void);


/* Function definitions */
int64_t _458_main(void){
    int64_t _459_x;
    int64_t _458_t3;
    uint8_t _458_t4;
    int64_t _458_t7;
    int64_t _458_t8;
    int64_t _458_t9;
    uint8_t _458_t11;
    int64_t _458_t12;
    int64_t _458_$retval;
    int64_t _458_t14;
    _459_x = 17;
    goto BB512;
BB512:
    _458_t3 = 36;
    _458_t4 = _459_x<_458_t3;
    if (_458_t4) {
        goto BB513;
    } else {
        goto BB525;
    }
BB513:
    _458_t7 = 2;
    _458_t8 = $mod_int64_t(_459_x, _458_t7, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _458_t9 = 0;
    _458_t11 = _458_t8==_458_t9;
    if (_458_t11) {
        goto BB517;
    } else {
        goto BB521;
    }
BB525:
    _458_$retval = _459_x;
    return _458_$retval;
BB517:
    _458_t14 = 9;
    _459_x = $add_int64_t(_459_x, _458_t14, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB512;
BB521:
    _458_t12 = 1;
    _459_x = $add_int64_t(_459_x, _458_t12, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB517;
}


int main(void) {
  printf("%ld",_458_main());
  return 0;
}
