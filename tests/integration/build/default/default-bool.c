/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2_main(void);

/* Function definitions */
int64_t _2_main(void) {
    uint8_t _2_t2;
    int64_t _2_t1;
    int64_t _2_$retval;
    _2_t2 = 1;
    if (_2_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _2_t1 = 130;
    goto BB4;
BB5:
    _2_t1 = 4;
    goto BB4;
BB4:
    _2_$retval = _2_t1;
    return _2_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
