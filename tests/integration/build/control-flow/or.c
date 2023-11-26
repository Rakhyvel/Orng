/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
uint8_t _70_main(void);

/* Function definitions */
uint8_t _70_main(void) {
    uint8_t _70_t2;
    uint8_t _70_t1;
    uint8_t _70_t0;
    uint8_t _70_$retval;
    _70_t2 = 0;
    if (_70_t2) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _70_t1 = 1;
    goto BB2;
BB7:
    _70_t1 = 0;
    goto BB2;
BB2:
    if (_70_t1) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _70_t0 = 1;
    goto BB5;
BB6:
    _70_t0 = 1;
    goto BB5;
BB5:
    _70_$retval = _70_t0;
    return _70_$retval;
}

int main(void) {
  printf("%d",_70_main());
  return 0;
}
