/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _189_main(void);

/* Function definitions */
int64_t _189_main(void) {
    uint8_t _189_t3;
    int64_t _189_t0;
    int64_t _189_$retval;
    _189_t3 = 1;
    if (_189_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _189_t0 = 175;
    goto BB4;
BB5:
    _189_t0 = 4;
    goto BB4;
BB4:
    _189_$retval = _189_t0;
    return _189_$retval;
}

int main(void) {
  printf("%ld",_189_main());
  return 0;
}
