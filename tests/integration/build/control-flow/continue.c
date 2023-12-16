/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _325_main(void);

/* Function definitions */
int64_t _325_main(void){
    int64_t _326_x;
    int64_t _327_i;
    int64_t _325_t3;
    uint8_t _325_t4;
    int64_t _325_t6;
    int64_t _325_t7;
    int64_t _325_t8;
    uint8_t _325_t10;
    int64_t _325_$retval;
    int64_t _325_t11;
    int64_t _325_t13;
    _326_x = 0;
    _327_i = 0;
    goto BB1;
BB1:
    _325_t3 = 70;
    _325_t4 = _327_i < _325_t3;
    if (_325_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _325_t6 = 2;
    _325_t7 = $mod_int64_t(_327_i, _325_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _325_t8 = 0;
    _325_t10 = _325_t7 == _325_t8;
    if (_325_t10) {
        goto BB6;
    } else {
        goto BB8;
    }
BB13:
    _325_$retval = _326_x;
    return _325_$retval;
BB6:
    _325_t13 = 1;
    _327_i = $add_int64_t(_327_i, _325_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB8:
    _325_t11 = 1;
    _326_x = $add_int64_t(_326_x, _325_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_325_main());
  return 0;
}
