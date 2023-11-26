/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _79_main(void);

/* Function definitions */
int64_t _79_main(void) {
    uint8_t _79_t3;
    int64_t _79_t0;
    int64_t _79_$retval;
    _79_t3 = 1;
    if (_79_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _79_t0 = 178;
    goto BB4;
BB5:
    _79_t0 = 4;
    goto BB4;
BB4:
    _79_$retval = _79_t0;
    return _79_$retval;
}

int main(void) {
  printf("%ld",_79_main());
  return 0;
}
