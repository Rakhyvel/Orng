/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _498_main(void);

/* Function definitions */
int64_t _498_main(void){
    int64_t _499_x;
    int64_t _498_t2;
    uint8_t _498_t3;
    int64_t _498_t5;
    int64_t _498_t6;
    int64_t _498_t7;
    uint8_t _498_t9;
    int64_t _498_t10;
    int64_t _498_$retval;
    int64_t _498_t12;
    _499_x = 17;
    goto BB1;
BB1:
    _498_t2 = 36;
    _498_t3 = _499_x < _498_t2;
    if (_498_t3) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    _498_t5 = 2;
    _498_t6 = $mod_int64_t(_499_x, _498_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _498_t7 = 0;
    _498_t9 = _498_t6 == _498_t7;
    if (_498_t9) {
        goto BB6;
    } else {
        goto BB10;
    }
BB14:
    _498_$retval = _499_x;
    return _498_$retval;
BB6:
    _498_t12 = 9;
    _499_x = $add_int64_t(_499_x, _498_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB1;
BB10:
    _498_t10 = 1;
    _499_x = $add_int64_t(_499_x, _498_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_498_main());
  return 0;
}
