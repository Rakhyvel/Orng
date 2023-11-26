/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _206_main(void);

/* Function definitions */
int64_t _206_main(void) {
    double _207_x;
    double _206_t2;
    uint8_t _206_t4;
    uint8_t _206_t3;
    int64_t _206_t1;
    int64_t _206_$retval;
    _207_x = 0;
    _206_t2 = 0.0e+00;
    _206_t4 = _207_x == _206_t2;
    if (_206_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _206_t3 = 1;
    goto BB2;
BB9:
    _206_t3 = 0;
    goto BB2;
BB2:
    if (_206_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _206_t1 = 132;
    goto BB6;
BB7:
    _206_t1 = 0;
    goto BB6;
BB6:
    _206_$retval = _206_t1;
    return _206_$retval;
}

int main(void) {
  printf("%ld",_206_main());
  return 0;
}
