/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _31_main(void);


/* Function definitions */
int64_t _31_main(void){
    int64_t _32_x;
    int64_t _31_t3;
    uint8_t _31_t4;
    int64_t _31_t6;
    uint8_t _31_t8;
    int64_t _31_t11;
    int64_t _31_$retval;
    int64_t _31_t9;
    _32_x = 0;
    goto BB48;
BB48:
    _31_t3 = 100;
    _31_t4 = _32_x<_31_t3;
    if (_31_t4) {
        goto BB49;
    } else {
        goto BB54;
    }
BB49:
    _31_t6 = 40;
    _31_t8 = _32_x==_31_t6;
    if (_31_t8) {
        goto BB52;
    } else {
        goto BB58;
    }
BB54:
    _31_$retval = _32_x;
    return _31_$retval;
BB52:
    _31_t9 = 1;
    _32_x = $add_int64_t(_32_x, _31_t9, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB54;
BB58:
    _31_t11 = 1;
    _32_x = $add_int64_t(_32_x, _31_t11, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB48;
}


int main(void) {
  printf("%ld",_31_main());
  return 0;
}
