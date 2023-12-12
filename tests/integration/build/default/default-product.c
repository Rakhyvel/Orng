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
int64_t _318_main(void);

/* Function definitions */
int64_t _318_main(void) {
    int64_t _318_t1;
    double _318_t2;
    struct0 _319_x;
    int64_t _318_t5;
    uint8_t _318_t7;
    int64_t _318_t3;
    int64_t _318_$retval;
    double _318_t8;
    uint8_t _318_t10;
    _318_t1 = 0;
    _318_t2 = 0.0e+00;
    _319_x = (struct0) {_318_t1, _318_t2};
    _318_t5 = 0;
    _318_t7 = _319_x._0 == _318_t5;
    if (_318_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _318_t8 = 0.0e+00;
    _318_t10 = _319_x._1 == _318_t8;
    if (_318_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _318_t3 = 0;
    goto BB10;
BB7:
    _318_t3 = 135;
    goto BB10;
BB10:
    _318_$retval = _318_t3;
    return _318_$retval;
}

int main(void) {
  printf("%ld",_318_main());
  return 0;
}
