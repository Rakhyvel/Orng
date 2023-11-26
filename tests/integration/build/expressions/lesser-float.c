/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _417_main(void);

/* Function definitions */
int64_t _417_main(void) {
    uint8_t _417_t3;
    int64_t _417_t0;
    int64_t _417_$retval;
    _417_t3 = 1;
    if (_417_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _417_t0 = 225;
    goto BB4;
BB5:
    _417_t0 = 4;
    goto BB4;
BB4:
    _417_$retval = _417_t0;
    return _417_$retval;
}

int main(void) {
  printf("%ld",_417_main());
  return 0;
}
