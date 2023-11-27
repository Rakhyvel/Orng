/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _237_main(void);

/* Function definitions */
int64_t _237_main(void) {
    double _238_x;
    double _237_t2;
    uint8_t _237_t4;
    int64_t _237_t1;
    int64_t _237_$retval;
    _238_x = 0;
    _237_t2 = 0.0e+00;
    _237_t4 = _238_x == _237_t2;
    if (_237_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _237_t1 = 132;
    goto BB6;
BB7:
    _237_t1 = 0;
    goto BB6;
BB6:
    _237_$retval = _237_t1;
    return _237_$retval;
}

int main(void) {
  printf("%ld",_237_main());
  return 0;
}
