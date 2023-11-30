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
int64_t _409_main(void);

/* Function definitions */
int64_t _409_main(void) {
    int64_t _409_t1;
    double _409_t2;
    struct0 _410_x;
    int64_t _409_t5;
    uint8_t _409_t7;
    int64_t _409_t3;
    int64_t _409_$retval;
    double _409_t8;
    uint8_t _409_t10;
    _409_t1 = 0;
    _409_t2 = 0;
    _410_x = (struct0) {_409_t1, _409_t2};
    _409_t5 = 0;
    _409_t7 = _410_x._0 == _409_t5;
    if (_409_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _409_t8 = 0.0e+00;
    _409_t10 = _410_x._1 == _409_t8;
    if (_409_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _409_t3 = 0;
    goto BB10;
BB7:
    _409_t3 = 135;
    goto BB10;
BB10:
    _409_$retval = _409_t3;
    return _409_$retval;
}

int main(void) {
  printf("%ld",_409_main());
  return 0;
}
