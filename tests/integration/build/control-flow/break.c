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
    int64_t _414_t3;
    uint8_t _414_t4;
    int64_t _414_t6;
    int64_t _414_t7;
    int64_t _414_t8;
    uint8_t _414_t10;
    int64_t _414_t11;
    int64_t _414_t13;
    int64_t _414_$retval;
    _415_x = 36;
    _416_i = 0;
    goto BB461;
BB461:
    _414_t3 = 70;
    _414_t4 = _416_i<_414_t3;
    if (_414_t4) {
        goto BB462;
    } else {
        goto BB473;
    }
BB462:
    _414_t6 = 2;
    _414_t7 = $mod_int64_t(_416_i, _414_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _414_t8 = 0;
    _414_t10 = _414_t7==_414_t8;
    if (_414_t10) {
        goto BB467;
    } else {
        goto BB469;
    }
BB473:
    _415_x = 10;
    goto BB467;
BB467:
    _414_$retval = _415_x;
    return _414_$retval;
BB469:
    _414_t11 = 1;
    _415_x = $add_int64_t(_415_x, _414_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _414_t13 = 1;
    _416_i = $add_int64_t(_416_i, _414_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB461;
}


int main(void) {
  printf("%ld",_414_main());
  return 0;
}
