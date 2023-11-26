/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _384_main(void);

/* Function definitions */
int64_t _384_main(void) {
    uint8_t _384_t3;
    int64_t _384_t0;
    int64_t _384_$retval;
    _384_t3 = 1;
    if (_384_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _384_t0 = 178;
    goto BB4;
BB5:
    _384_t0 = 4;
    goto BB4;
BB4:
    _384_$retval = _384_t0;
    return _384_$retval;
}

int main(void) {
  printf("%ld",_384_main());
  return 0;
}
