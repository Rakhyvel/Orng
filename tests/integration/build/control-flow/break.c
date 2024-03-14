/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _414_main(void);


/* Function definitions */
int64_t _414_main(void){
    int64_t _415_x;
    int64_t _416_i;
    int64_t _414_t5;
    uint8_t _414_t6;
    int64_t _414_t8;
    int64_t _414_t9;
    int64_t _414_t10;
    uint8_t _414_t12;
    int64_t _414_t13;
    int64_t _414_t15;
    int64_t _414_$retval;
    _415_x = 36;
    _416_i = 0;
    goto BB454;
BB454:
    _414_t5 = 70;
    _414_t6 = _416_i<_414_t5;
    if (_414_t6) {
        goto BB455;
    } else {
        goto BB466;
    }
BB455:
    _414_t8 = 2;
    _414_t9 = $mod_int64_t(_416_i, _414_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _414_t10 = 0;
    _414_t12 = _414_t9==_414_t10;
    if (_414_t12) {
        goto BB460;
    } else {
        goto BB462;
    }
BB466:
    _415_x = 10;
    goto BB460;
BB460:
    _414_$retval = _415_x;
    return _414_$retval;
BB462:
    _414_t13 = 1;
    _415_x = $add_int64_t(_415_x, _414_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _414_t15 = 1;
    _416_i = $add_int64_t(_416_i, _414_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB454;
}


int main(void) {
  printf("%ld",_414_main());
  return 0;
}
