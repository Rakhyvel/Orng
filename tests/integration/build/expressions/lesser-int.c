/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _423_main(void);

/* Function definitions */
int64_t _423_main(void) {
    uint8_t _423_t3;
    int64_t _423_t0;
    int64_t _423_$retval;
    _423_t3 = 1;
    if (_423_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _423_t0 = 177;
    goto BB4;
BB5:
    _423_t0 = 4;
    goto BB4;
BB4:
    _423_$retval = _423_t0;
    return _423_$retval;
}

int main(void) {
  printf("%ld",_423_main());
  return 0;
}
