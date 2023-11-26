/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _112_main(void);

/* Function definitions */
int64_t _112_main(void) {
    uint8_t _112_t3;
    int64_t _112_t0;
    int64_t _112_$retval;
    _112_t3 = 1;
    if (_112_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _112_t0 = 225;
    goto BB4;
BB5:
    _112_t0 = 4;
    goto BB4;
BB4:
    _112_$retval = _112_t0;
    return _112_$retval;
}

int main(void) {
  printf("%ld",_112_main());
  return 0;
}
