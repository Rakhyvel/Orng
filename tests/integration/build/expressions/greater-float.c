/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _390_main(void);

/* Function definitions */
int64_t _390_main(void) {
    uint8_t _390_t3;
    int64_t _390_t0;
    int64_t _390_$retval;
    _390_t3 = 1;
    if (_390_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _390_t0 = 176;
    goto BB4;
BB5:
    _390_t0 = 4;
    goto BB4;
BB4:
    _390_$retval = _390_t0;
    return _390_$retval;
}

int main(void) {
  printf("%ld",_390_main());
  return 0;
}
