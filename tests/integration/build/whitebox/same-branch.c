/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1631_main(void);

/* Function definitions */
int64_t _1631_main(void) {
    uint8_t _1632_x;
    int64_t _1632_z;
    uint8_t* _1631_t3;
    int64_t _1631_$retval;
    _1632_x = 1;
    _1632_z = 40;
    _1631_t3 = &_1632_x;
    if (*_1631_t3) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    goto BB3;
BB3:
    _1631_$retval = _1632_z;
    return _1631_$retval;
}

int main(void) {
  printf("%ld",_1631_main());
  return 0;
}
