/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _422_main(void);


/* Function definitions */
int64_t _422_main(void){
    int64_t _423_x;
    int64_t _424_i;
    int64_t _422_t5;
    uint8_t _422_t6;
    int64_t _422_t8;
    int64_t _422_t9;
    int64_t _422_t10;
    uint8_t _422_t12;
    int64_t _422_$retval;
    int64_t _422_t13;
    int64_t _422_t15;
    _423_x = 0;
    _424_i = 0;
    goto BB466;
BB466:
    _422_t5 = 70;
    _422_t6 = _424_i<_422_t5;
    if (_422_t6) {
        goto BB467;
    } else {
        goto BB478;
    }
BB467:
    _422_t8 = 2;
    _422_t9 = $mod_int64_t(_424_i, _422_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _422_t10 = 0;
    _422_t12 = _422_t9==_422_t10;
    if (_422_t12) {
        goto BB471;
    } else {
        goto BB473;
    }
BB478:
    _422_$retval = _423_x;
    return _422_$retval;
BB471:
    _422_t15 = 1;
    _424_i = $add_int64_t(_424_i, _422_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB466;
BB473:
    _422_t13 = 1;
    _423_x = $add_int64_t(_423_x, _422_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB471;
}


int main(void) {
  printf("%ld",_422_main());
  return 0;
}
