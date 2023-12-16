/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _410_main(void);

/* Function definitions */
int64_t _410_main(void){
    int64_t _411_x;
    int64_t _410_t2;
    uint8_t _410_t3;
    int64_t _410_t5;
    int64_t _410_t6;
    int64_t _410_t7;
    uint8_t _410_t9;
    int64_t _410_t10;
    int64_t _410_$retval;
    int64_t _410_t12;
    _411_x = 17;
    goto BB1;
BB1:
    _410_t2 = 36;
    _410_t3 = _411_x < _410_t2;
    if (_410_t3) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    _410_t5 = 2;
    _410_t6 = $mod_int64_t(_411_x, _410_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _410_t7 = 0;
    _410_t9 = _410_t6 == _410_t7;
    if (_410_t9) {
        goto BB6;
    } else {
        goto BB10;
    }
BB14:
    _410_$retval = _411_x;
    return _410_$retval;
BB6:
    _410_t12 = 9;
    _411_x = $add_int64_t(_411_x, _410_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB1;
BB10:
    _410_t10 = 1;
    _411_x = $add_int64_t(_411_x, _410_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_410_main());
  return 0;
}
