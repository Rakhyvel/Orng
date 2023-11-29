/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _398_main(void);

/* Function definitions */
int64_t _398_main(void) {
    double _399_x;
    double _398_t2;
    uint8_t _398_t4;
    int64_t _398_t1;
    int64_t _398_$retval;
    _399_x = 0;
    _398_t2 = 0.0e+00;
    _398_t4 = _399_x == _398_t2;
    if (_398_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _398_t1 = 132;
    goto BB6;
BB7:
    _398_t1 = 0;
    goto BB6;
BB6:
    _398_$retval = _398_t1;
    return _398_$retval;
}

int main(void) {
  printf("%ld",_398_main());
  return 0;
}
