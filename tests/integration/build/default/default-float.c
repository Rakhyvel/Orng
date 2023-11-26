/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _11_main(void);

/* Function definitions */
int64_t _11_main(void) {
    double _12_x;
    double _11_t2;
    uint8_t _11_t4;
    uint8_t _11_t3;
    int64_t _11_t1;
    int64_t _11_$retval;
    _12_x = 0;
    _11_t2 = 0.0e+00;
    _11_t4 = _12_x == _11_t2;
    if (_11_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _11_t3 = 1;
    goto BB2;
BB9:
    _11_t3 = 0;
    goto BB2;
BB2:
    if (_11_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _11_t1 = 132;
    goto BB6;
BB7:
    _11_t1 = 0;
    goto BB6;
BB6:
    _11_$retval = _11_t1;
    return _11_$retval;
}

int main(void) {
  printf("%ld",_11_main());
  return 0;
}
