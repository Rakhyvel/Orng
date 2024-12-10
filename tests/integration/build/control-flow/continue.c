/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _442_main(void);


/* Function definitions */
int64_t _442_main(void){
    int64_t _443_x;
    int64_t _444_i;
    int64_t _442_t5;
    uint8_t _442_t6;
    int64_t _442_t8;
    int64_t _442_t9;
    int64_t _442_t10;
    uint8_t _442_t12;
    int64_t _442_$retval;
    int64_t _442_t13;
    int64_t _442_t15;
    _443_x = 0;
    _444_i = 0;
    goto BB485;
BB485:
    _442_t5 = 70;
    _442_t6 = _444_i<_442_t5;
    if (_442_t6) {
        goto BB486;
    } else {
        goto BB497;
    }
BB486:
    _442_t8 = 2;
    _442_t9 = $mod_int64_t(_444_i, _442_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _442_t10 = 0;
    _442_t12 = _442_t9==_442_t10;
    if (_442_t12) {
        goto BB490;
    } else {
        goto BB492;
    }
BB497:
    _442_$retval = _443_x;
    return _442_$retval;
BB490:
    _442_t15 = 1;
    _444_i = $add_int64_t(_444_i, _442_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB485;
BB492:
    _442_t13 = 1;
    _443_x = $add_int64_t(_443_x, _442_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB490;
}


int main(void) {
  printf("%ld",_442_main());
  return 0;
}
