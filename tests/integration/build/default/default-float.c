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
    double _308_x;
    double _307_t2;
    uint8_t _307_t4;
    int64_t _307_t1;
    int64_t _307_$retval;
    _308_x = 0;
    _307_t2 = 0.0e+00;
    _307_t4 = _308_x == _307_t2;
    if (_307_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _307_t1 = 132;
    goto BB6;
BB7:
    _307_t1 = 0;
    goto BB6;
BB6:
    _307_$retval = _307_t1;
    return _307_$retval;
}

int main(void) {
  printf("%ld",_307_main());
  return 0;
}
