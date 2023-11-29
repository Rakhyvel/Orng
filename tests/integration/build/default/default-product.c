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
int64_t _430_main(void);

/* Function definitions */
int64_t _430_main(void) {
    int64_t _430_t1;
    double _430_t2;
    struct0 _431_x;
    int64_t _430_t5;
    uint8_t _430_t7;
    int64_t _430_t3;
    int64_t _430_$retval;
    double _430_t8;
    uint8_t _430_t10;
    _430_t1 = 0;
    _430_t2 = 0;
    _431_x = (struct0) {_430_t1, _430_t2};
    _430_t5 = 0;
    _430_t7 = _431_x._0 == _430_t5;
    if (_430_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _430_t8 = 0.0e+00;
    _430_t10 = _431_x._1 == _430_t8;
    if (_430_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _430_t3 = 0;
    goto BB10;
BB7:
    _430_t3 = 135;
    goto BB10;
BB10:
    _430_$retval = _430_t3;
    return _430_$retval;
}

int main(void) {
  printf("%ld",_430_main());
  return 0;
}
