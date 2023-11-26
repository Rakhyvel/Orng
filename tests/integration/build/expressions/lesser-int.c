/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _118_main(void);

/* Function definitions */
int64_t _118_main(void) {
    uint8_t _118_t3;
    int64_t _118_t0;
    int64_t _118_$retval;
    _118_t3 = 1;
    if (_118_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _118_t0 = 177;
    goto BB4;
BB5:
    _118_t0 = 4;
    goto BB4;
BB4:
    _118_$retval = _118_t0;
    return _118_$retval;
}

int main(void) {
  printf("%ld",_118_main());
  return 0;
}
