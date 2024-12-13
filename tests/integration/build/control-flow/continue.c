/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _444_main(void);


/* Function definitions */
int64_t _444_main(void){
    int64_t _445_x;
    int64_t _446_i;
    int64_t _444_t5;
    uint8_t _444_t6;
    int64_t _444_t8;
    int64_t _444_t9;
    int64_t _444_t10;
    uint8_t _444_t12;
    int64_t _444_$retval;
    int64_t _444_t13;
    int64_t _444_t15;
    _445_x = 0;
    _446_i = 0;
    goto BB487;
BB487:
    _444_t5 = 70;
    _444_t6 = _446_i<_444_t5;
    if (_444_t6) {
        goto BB488;
    } else {
        goto BB499;
    }
BB488:
    _444_t8 = 2;
    _444_t9 = $mod_int64_t(_446_i, _444_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _444_t10 = 0;
    _444_t12 = _444_t9==_444_t10;
    if (_444_t12) {
        goto BB492;
    } else {
        goto BB494;
    }
BB499:
    _444_$retval = _445_x;
    return _444_$retval;
BB492:
    _444_t15 = 1;
    _446_i = $add_int64_t(_446_i, _444_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB487;
BB494:
    _444_t13 = 1;
    _445_x = $add_int64_t(_445_x, _444_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB492;
}


int main(void) {
  printf("%ld",_444_main());
  return 0;
}
