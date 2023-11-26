/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _411_main(void);

/* Function definitions */
int64_t _411_main(void) {
    uint8_t _411_t3;
    int64_t _411_t0;
    int64_t _411_$retval;
    _411_t3 = 1;
    if (_411_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _411_t0 = 180;
    goto BB4;
BB5:
    _411_t0 = 4;
    goto BB4;
BB4:
    _411_$retval = _411_t0;
    return _411_$retval;
}

int main(void) {
  printf("%ld",_411_main());
  return 0;
}
