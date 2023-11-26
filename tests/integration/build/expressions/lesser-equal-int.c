/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _106_main(void);

/* Function definitions */
int64_t _106_main(void) {
    uint8_t _106_t3;
    int64_t _106_t0;
    int64_t _106_$retval;
    _106_t3 = 1;
    if (_106_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _106_t0 = 180;
    goto BB4;
BB5:
    _106_t0 = 4;
    goto BB4;
BB4:
    _106_$retval = _106_t0;
    return _106_$retval;
}

int main(void) {
  printf("%ld",_106_main());
  return 0;
}
