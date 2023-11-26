/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _453_main(void);

/* Function definitions */
int64_t _453_main(void) {
    uint8_t _453_t6;
    uint8_t _453_t5;
    int64_t _453_t0;
    int64_t _453_$retval;
    _453_t6 = 1;
    if (_453_t6) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _453_t5 = 1;
    goto BB2;
BB9:
    _453_t5 = 0;
    goto BB2;
BB2:
    if (_453_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _453_t0 = 185;
    goto BB6;
BB7:
    _453_t0 = 4;
    goto BB6;
BB6:
    _453_$retval = _453_t0;
    return _453_$retval;
}

int main(void) {
  printf("%ld",_453_main());
  return 0;
}
