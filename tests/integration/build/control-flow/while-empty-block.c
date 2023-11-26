/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _94_main(void);

/* Function definitions */
int64_t _94_main(void) {
    int64_t _94_$retval;
    uint8_t _94_t1;
BB1:
    _94_t1 = 0;
    if (_94_t1) {
        goto BB1;
    } else {
        goto BB5;
    }
BB5:
    _94_$retval = 25;
    return _94_$retval;
}

int main(void) {
  printf("%ld",_94_main());
  return 0;
}
