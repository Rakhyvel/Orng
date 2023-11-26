/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _186_main(void);

/* Function definitions */
int64_t _186_main(void) {
    int64_t _186_$retval;
    uint8_t _186_t1;
BB1:
    _186_t1 = 0;
    if (_186_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _186_$retval = 25;
    return _186_$retval;
}

int main(void) {
  printf("%ld",_186_main());
  return 0;
}
