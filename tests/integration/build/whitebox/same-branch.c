/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1243_main(void);

/* Function definitions */
int64_t _1243_main(void) {
    uint8_t _1244_x;
    int64_t _1244_z;
    uint8_t* _1243_t3;
    int64_t _1243_$retval;
    _1244_x = 1;
    _1244_z = 40;
    _1243_t3 = &_1244_x;
    if (*_1243_t3) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    goto BB3;
BB3:
    _1243_$retval = _1244_z;
    return _1243_$retval;
}

int main(void) {
  printf("%ld",_1243_main());
  return 0;
}
