/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _60_main(void);


/* Function definitions */
int64_t _60_main(void){
    int64_t _61_x;
    int64_t* _61_y;
    int64_t _60_t5;
    uint8_t _60_t7;
    int64_t _60_t4;
    int64_t _60_$retval;
    int64_t _60_t9;
    uint8_t _60_t10;
    int64_t _60_t11;
    uint8_t _60_t12;
    _61_x = 3;
    _61_y = &_61_x;
    _60_t5 = 5;
    _60_t7 = *_61_y==_60_t5;
    if (_60_t7) {
        goto BB92;
    } else {
        goto BB94;
    }
BB92:
    _60_t9 = 4;
    _60_t10 = _60_t9>*_61_y;
    if (_60_t10) {
        goto BB94;
    } else {
        goto BB99;
    }
BB94:
    _60_t11 = 3;
    _60_t12 = *_61_y>=_60_t11;
    if (_60_t12) {
        goto BB95;
    } else {
        goto BB99;
    }
BB99:
    _60_t4 = 10;
    goto BB98;
BB95:
    _60_t4 = 33;
    goto BB98;
BB98:
    _60_$retval = _60_t4;
    return _60_$retval;
}


int main(void) {
  printf("%ld",_60_main());
  return 0;
}
