/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    double _1;
} struct0;

/* Function forward definitions */
int64_t _432_main(void);

/* Function definitions */
int64_t _432_main(void) {
    int64_t _432_t1;
    double _432_t2;
    struct0 _433_x;
    int64_t _432_t5;
    uint8_t _432_t7;
    int64_t _432_t3;
    int64_t _432_$retval;
    double _432_t8;
    uint8_t _432_t10;
    _432_t1 = 0;
    _432_t2 = 0;
    _433_x = (struct0) {_432_t1, _432_t2};
    _432_t5 = 0;
    _432_t7 = _433_x._0 == _432_t5;
    if (_432_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _432_t8 = 0.0e+00;
    _432_t10 = _433_x._1 == _432_t8;
    if (_432_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _432_t3 = 0;
    goto BB10;
BB7:
    _432_t3 = 135;
    goto BB10;
BB10:
    _432_$retval = _432_t3;
    return _432_$retval;
}

int main(void) {
  printf("%ld",_432_main());
  return 0;
}
