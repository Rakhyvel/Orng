/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _377_main(void);

/* Function definitions */
int64_t _377_main(void) {
    double _378_x;
    double _377_t2;
    uint8_t _377_t4;
    int64_t _377_t1;
    int64_t _377_$retval;
    _378_x = 0;
    _377_t2 = 0.0e+00;
    _377_t4 = _378_x == _377_t2;
    if (_377_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _377_t1 = 132;
    goto BB6;
BB7:
    _377_t1 = 0;
    goto BB6;
BB6:
    _377_$retval = _377_t1;
    return _377_$retval;
}

int main(void) {
  printf("%ld",_377_main());
  return 0;
}
