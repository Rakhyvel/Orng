/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _409_main(void);

/* Function definitions */
int64_t _409_main(void){
    int64_t _410_x;
    int64_t _409_t2;
    uint8_t _409_t3;
    int64_t _409_t5;
    int64_t _409_t6;
    int64_t _409_t7;
    uint8_t _409_t9;
    int64_t _409_t10;
    int64_t _409_$retval;
    int64_t _409_t12;
    _410_x = 17;
    goto BB490;
BB490:
    _409_t2 = 36;
    _409_t3 = _410_x<_409_t2;
    if (_409_t3) {
        goto BB491;
    } else {
        goto BB503;
    }
BB491:
    _409_t5 = 2;
    _409_t6 = $mod_int64_t(_410_x, _409_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _409_t7 = 0;
    _409_t9 = _409_t6==_409_t7;
    if (_409_t9) {
        goto BB495;
    } else {
        goto BB499;
    }
BB503:
    _409_$retval = _410_x;
    return _409_$retval;
BB495:
    _409_t12 = 9;
    _410_x = $add_int64_t(_410_x, _409_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB490;
BB499:
    _409_t10 = 1;
    _410_x = $add_int64_t(_410_x, _409_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB495;
}

int main(void) {
  printf("%ld",_409_main());
  return 0;
}
