/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _393_main(void);

/* Function definitions */
int64_t _393_main(void){
    int64_t _394_x;
    int64_t _395_i;
    int64_t _393_t3;
    uint8_t _393_t4;
    int64_t _393_t6;
    int64_t _393_t7;
    int64_t _393_t8;
    uint8_t _393_t10;
    int64_t _393_$retval;
    int64_t _393_t11;
    int64_t _393_t13;
    _394_x = 0;
    _395_i = 0;
    goto BB482;
BB482:
    _393_t3 = 70;
    _393_t4 = _395_i < _393_t3;
    if (_393_t4) {
        goto BB483;
    } else {
        goto BB494;
    }
BB483:
    _393_t6 = 2;
    _393_t7 = $mod_int64_t(_395_i, _393_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _393_t8 = 0;
    _393_t10 = _393_t7 == _393_t8;
    if (_393_t10) {
        goto BB487;
    } else {
        goto BB489;
    }
BB494:
    _393_$retval = _394_x;
    return _393_$retval;
BB487:
    _393_t13 = 1;
    _395_i = $add_int64_t(_395_i, _393_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB482;
BB489:
    _393_t11 = 1;
    _394_x = $add_int64_t(_394_x, _393_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB487;
}

int main(void) {
  printf("%ld",_393_main());
  return 0;
}
