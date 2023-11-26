/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
uint8_t _2_main(void);

/* Function definitions */
uint8_t _2_main(void) {
    uint8_t _2_t2;
    uint8_t _2_t1;
    uint8_t _2_t0;
    uint8_t _2_$retval;
    _2_t2 = 1;
    if (_2_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _2_t1 = 1;
    goto BB2;
BB7:
    _2_t1 = 0;
    goto BB2;
BB2:
    if (_2_t1) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _2_t0 = 1;
    goto BB5;
BB6:
    _2_t0 = 0;
    goto BB5;
BB5:
    _2_$retval = _2_t0;
    return _2_$retval;
}

int main(void) {
  printf("%d",_2_main());
  return 0;
}
