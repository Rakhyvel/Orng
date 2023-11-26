/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _73_main(void);

/* Function definitions */
int64_t _73_main(void) {
    uint8_t _73_t3;
    int64_t _73_t0;
    int64_t _73_$retval;
    _73_t3 = 1;
    if (_73_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _73_t0 = 179;
    goto BB4;
BB5:
    _73_t0 = 4;
    goto BB4;
BB4:
    _73_$retval = _73_t0;
    return _73_$retval;
}

int main(void) {
  printf("%ld",_73_main());
  return 0;
}
