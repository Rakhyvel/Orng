/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _165_main(void);

/* Function definitions */
int64_t _165_main(void) {
    uint8_t _165_t1;
    int64_t _165_$retval;
    _165_t1 = 0;
    if (_165_t1) {
        goto BB1;
    } else {
        goto BB3;
    }
BB1:
    _165_$retval = 1000;
    return _165_$retval;
BB3:
    _165_$retval = 37;
    return _165_$retval;
}

int main(void) {
  printf("%ld",_165_main());
  return 0;
}
