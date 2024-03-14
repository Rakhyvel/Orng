/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _423_main(void);


/* Function definitions */
int64_t _423_main(void){
    int64_t _424_x;
    int64_t _425_i;
    int64_t _423_t5;
    uint8_t _423_t6;
    int64_t _423_t8;
    int64_t _423_t9;
    int64_t _423_t10;
    uint8_t _423_t12;
    int64_t _423_$retval;
    int64_t _423_t13;
    int64_t _423_t15;
    _424_x = 0;
    _425_i = 0;
    goto BB469;
BB469:
    _423_t5 = 70;
    _423_t6 = _425_i<_423_t5;
    if (_423_t6) {
        goto BB470;
    } else {
        goto BB481;
    }
BB470:
    _423_t8 = 2;
    _423_t9 = $mod_int64_t(_425_i, _423_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _423_t10 = 0;
    _423_t12 = _423_t9==_423_t10;
    if (_423_t12) {
        goto BB474;
    } else {
        goto BB476;
    }
BB481:
    _423_$retval = _424_x;
    return _423_$retval;
BB474:
    _423_t15 = 1;
    _425_i = $add_int64_t(_425_i, _423_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB469;
BB476:
    _423_t13 = 1;
    _424_x = $add_int64_t(_424_x, _423_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB474;
}


int main(void) {
  printf("%ld",_423_main());
  return 0;
}
