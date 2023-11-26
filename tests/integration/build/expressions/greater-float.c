/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _85_main(void);

/* Function definitions */
int64_t _85_main(void) {
    uint8_t _85_t3;
    int64_t _85_t0;
    int64_t _85_$retval;
    _85_t3 = 1;
    if (_85_t3) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _85_t0 = 176;
    goto BB4;
BB5:
    _85_t0 = 4;
    goto BB4;
BB4:
    _85_$retval = _85_t0;
    return _85_$retval;
}

int main(void) {
  printf("%ld",_85_main());
  return 0;
}
