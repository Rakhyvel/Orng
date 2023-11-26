/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _307_main(void);

/* Function definitions */
int64_t _307_main(void) {
    uint8_t _307_t6;
    uint8_t _307_t5;
    int64_t _307_t0;
    int64_t _307_$retval;
    _307_t6 = 1;
    if (_307_t6) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _307_t5 = 1;
    goto BB2;
BB9:
    _307_t5 = 0;
    goto BB2;
BB2:
    if (_307_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _307_t0 = 181;
    goto BB6;
BB7:
    _307_t0 = 4;
    goto BB6;
BB6:
    _307_$retval = _307_t0;
    return _307_$retval;
}

int main(void) {
  printf("%ld",_307_main());
  return 0;
}
