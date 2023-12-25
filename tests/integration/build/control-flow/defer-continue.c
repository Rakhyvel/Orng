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
    goto BB509;
BB509:
    _409_t2 = 36;
    _409_t3 = _410_x<_409_t2;
    if (_409_t3) {
        goto BB510;
    } else {
        goto BB522;
    }
BB510:
    _409_t5 = 2;
    _409_t6 = $mod_int64_t(_410_x, _409_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _409_t7 = 0;
    _409_t9 = _409_t6==_409_t7;
    if (_409_t9) {
        goto BB514;
    } else {
        goto BB518;
    }
BB522:
    _409_$retval = _410_x;
    return _409_$retval;
BB514:
    _409_t12 = 9;
    _410_x = $add_int64_t(_410_x, _409_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB509;
BB518:
    _409_t10 = 1;
    _410_x = $add_int64_t(_410_x, _409_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB514;
}

int main(void) {
  printf("%ld",_409_main());
  return 0;
}
