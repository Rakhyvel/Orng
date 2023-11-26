/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _363_main(void);

/* Function definitions */
int64_t _363_main(void) {
    uint8_t _363_t6;
    uint8_t _363_t5;
    int64_t _363_t0;
    int64_t _363_$retval;
    _363_t6 = 1;
    if (_363_t6) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _363_t5 = 1;
    goto BB2;
BB9:
    _363_t5 = 0;
    goto BB2;
BB2:
    if (_363_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _363_t0 = 189;
    goto BB6;
BB7:
    _363_t0 = 4;
    goto BB6;
BB6:
    _363_$retval = _363_t0;
    return _363_$retval;
}

int main(void) {
  printf("%ld",_363_main());
  return 0;
}
