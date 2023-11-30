/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _400_main(void);

/* Function definitions */
int64_t _400_main(void) {
    double _401_x;
    double _400_t2;
    uint8_t _400_t4;
    int64_t _400_t1;
    int64_t _400_$retval;
    _401_x = 0;
    _400_t2 = 0.0e+00;
    _400_t4 = _401_x == _400_t2;
    if (_400_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _400_t1 = 132;
    goto BB6;
BB7:
    _400_t1 = 0;
    goto BB6;
BB6:
    _400_$retval = _400_t1;
    return _400_$retval;
}

int main(void) {
  printf("%ld",_400_main());
  return 0;
}
