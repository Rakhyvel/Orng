/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1275_main(void);

/* Function definitions */
int64_t _1275_main(void) {
    uint8_t _1276_x;
    int64_t _1276_z;
    uint8_t* _1275_t3;
    int64_t _1275_$retval;
    _1276_x = 1;
    _1276_z = 40;
    _1275_t3 = &_1276_x;
    if (*_1275_t3) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    goto BB3;
BB3:
    _1275_$retval = _1276_z;
    return _1275_$retval;
}

int main(void) {
  printf("%ld",_1275_main());
  return 0;
}
