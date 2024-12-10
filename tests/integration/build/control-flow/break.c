/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _433_main(void);


/* Function definitions */
int64_t _433_main(void){
    int64_t _434_x;
    int64_t _435_i;
    int64_t _433_t5;
    uint8_t _433_t6;
    int64_t _433_t8;
    int64_t _433_t9;
    int64_t _433_t10;
    uint8_t _433_t12;
    int64_t _433_t13;
    int64_t _433_t15;
    int64_t _433_$retval;
    _434_x = 36;
    _435_i = 0;
    goto BB470;
BB470:
    _433_t5 = 70;
    _433_t6 = _435_i<_433_t5;
    if (_433_t6) {
        goto BB471;
    } else {
        goto BB482;
    }
BB471:
    _433_t8 = 2;
    _433_t9 = $mod_int64_t(_435_i, _433_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _433_t10 = 0;
    _433_t12 = _433_t9==_433_t10;
    if (_433_t12) {
        goto BB476;
    } else {
        goto BB478;
    }
BB482:
    _434_x = 10;
    goto BB476;
BB476:
    _433_$retval = _434_x;
    return _433_$retval;
BB478:
    _433_t13 = 1;
    _434_x = $add_int64_t(_434_x, _433_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _433_t15 = 1;
    _435_i = $add_int64_t(_435_i, _433_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB470;
}


int main(void) {
  printf("%ld",_433_main());
  return 0;
}
