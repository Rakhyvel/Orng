/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1267_main(void);

/* Function definitions */
int64_t _1267_main(void) {
    uint8_t _1268_x;
    int64_t _1268_z;
    uint8_t* _1267_t3;
    int64_t _1267_$retval;
    _1268_x = 1;
    _1268_z = 40;
    _1267_t3 = &_1268_x;
    if (*_1267_t3) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    goto BB3;
BB3:
    _1267_$retval = _1268_z;
    return _1267_$retval;
}

int main(void) {
  printf("%ld",_1267_main());
  return 0;
}
