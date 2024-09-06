/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _413_main(void);


/* Function definitions */
int64_t _413_main(void){
    int64_t _414_x;
    int64_t _415_i;
    int64_t _413_t5;
    uint8_t _413_t6;
    int64_t _413_t8;
    int64_t _413_t9;
    int64_t _413_t10;
    uint8_t _413_t12;
    int64_t _413_t13;
    int64_t _413_t15;
    int64_t _413_$retval;
    _414_x = 36;
    _415_i = 0;
    goto BB451;
BB451:
    _413_t5 = 70;
    _413_t6 = _415_i<_413_t5;
    if (_413_t6) {
        goto BB452;
    } else {
        goto BB463;
    }
BB452:
    _413_t8 = 2;
    _413_t9 = $mod_int64_t(_415_i, _413_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _413_t10 = 0;
    _413_t12 = _413_t9==_413_t10;
    if (_413_t12) {
        goto BB457;
    } else {
        goto BB459;
    }
BB463:
    _414_x = 10;
    goto BB457;
BB457:
    _413_$retval = _414_x;
    return _413_$retval;
BB459:
    _413_t13 = 1;
    _414_x = $add_int64_t(_414_x, _413_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _413_t15 = 1;
    _415_i = $add_int64_t(_415_i, _413_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB451;
}


int main(void) {
  printf("%ld",_413_main());
  return 0;
}
