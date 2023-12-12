/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1294_main(void);

/* Function definitions */
int64_t _1294_main(void) {
    uint8_t _1295_x;
    int64_t _1295_z;
    uint8_t* _1294_t3;
    int64_t _1294_$retval;
    _1295_x = 1;
    _1295_z = 40;
    _1294_t3 = &_1295_x;
    if (*_1294_t3) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    goto BB3;
BB3:
    _1294_$retval = _1295_z;
    return _1294_$retval;
}

int main(void) {
  printf("%ld",_1294_main());
  return 0;
}
