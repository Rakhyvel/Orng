/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _494_main(void);

/* Function definitions */
int64_t _494_main(void) {
    uint8_t _494_t3;
    int64_t _494_t0;
    int64_t _494_$retval;
    _494_t3 = 1;
    if (_494_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _494_t0 = 175;
    goto BB4;
BB5:
    _494_t0 = 4;
    goto BB4;
BB4:
    _494_$retval = _494_t0;
    return _494_$retval;
}

int main(void) {
  printf("%ld",_494_main());
  return 0;
}
