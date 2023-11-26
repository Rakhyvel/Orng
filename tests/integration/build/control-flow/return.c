/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _73_main(void);

/* Function definitions */
int64_t _73_main(void) {
    uint8_t _73_t1;
    int64_t _73_$retval;
    _73_t1 = 0;
    if (_73_t1) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _73_$retval = 1000;
    return _73_$retval;
BB3:
    _73_$retval = 37;
    return _73_$retval;
}

int main(void) {
  printf("%ld",_73_main());
  return 0;
}
