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
int64_t _329_main(void);

/* Function definitions */
int64_t _329_main(void) {
    int64_t _329_t1;
    double _329_t2;
    struct0 _330_x;
    int64_t _329_t5;
    uint8_t _329_t7;
    int64_t _329_t3;
    int64_t _329_$retval;
    double _329_t8;
    uint8_t _329_t10;
    _329_t1 = 0;
    _329_t2 = 0;
    _330_x = (struct0) {_329_t1, _329_t2};
    _329_t5 = 0;
    _329_t7 = _330_x._0 == _329_t5;
    if (_329_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _329_t8 = 0.0e+00;
    _329_t10 = _330_x._1 == _329_t8;
    if (_329_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _329_t3 = 0;
    goto BB10;
BB7:
    _329_t3 = 135;
    goto BB10;
BB10:
    _329_$retval = _329_t3;
    return _329_$retval;
}

int main(void) {
  printf("%ld",_329_main());
  return 0;
}
