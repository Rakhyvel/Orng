/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _418_main(void);


/* Function definitions */
int64_t _418_main(void){
    int64_t _419_x;
    int64_t _420_i;
    int64_t _418_t5;
    uint8_t _418_t6;
    int64_t _418_t8;
    int64_t _418_t9;
    int64_t _418_t10;
    uint8_t _418_t12;
    int64_t _418_t13;
    int64_t _418_t15;
    int64_t _418_$retval;
    _419_x = 36;
    _420_i = 0;
    goto BB454;
BB454:
    _418_t5 = 70;
    _418_t6 = _420_i<_418_t5;
    if (_418_t6) {
        goto BB455;
    } else {
        goto BB466;
    }
BB455:
    _418_t8 = 2;
    _418_t9 = $mod_int64_t(_420_i, _418_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _418_t10 = 0;
    _418_t12 = _418_t9==_418_t10;
    if (_418_t12) {
        goto BB460;
    } else {
        goto BB462;
    }
BB466:
    _419_x = 10;
    goto BB460;
BB460:
    _418_$retval = _419_x;
    return _418_$retval;
BB462:
    _418_t13 = 1;
    _419_x = $add_int64_t(_419_x, _418_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _418_t15 = 1;
    _420_i = $add_int64_t(_420_i, _418_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB454;
}


int main(void) {
  printf("%ld",_418_main());
  return 0;
}
