/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _443_main(void);


/* Function definitions */
int64_t _443_main(void){
    int64_t _444_x;
    int64_t _443_t3;
    uint8_t _443_t4;
    int64_t _443_t7;
    int64_t _443_t8;
    int64_t _443_t9;
    uint8_t _443_t11;
    int64_t _443_t12;
    int64_t _443_$retval;
    int64_t _443_t14;
    _444_x = 17;
    goto BB496;
BB496:
    _443_t3 = 36;
    _443_t4 = _444_x<_443_t3;
    if (_443_t4) {
        goto BB497;
    } else {
        goto BB509;
    }
BB497:
    _443_t7 = 2;
    _443_t8 = $mod_int64_t(_444_x, _443_t7, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _443_t9 = 0;
    _443_t11 = _443_t8==_443_t9;
    if (_443_t11) {
        goto BB501;
    } else {
        goto BB505;
    }
BB509:
    _443_$retval = _444_x;
    return _443_$retval;
BB501:
    _443_t14 = 9;
    _444_x = $add_int64_t(_444_x, _443_t14, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB496;
BB505:
    _443_t12 = 1;
    _444_x = $add_int64_t(_444_x, _443_t12, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB501;
}


int main(void) {
  printf("%ld",_443_main());
  return 0;
}
