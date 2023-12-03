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
int64_t _291_main(void);

/* Function definitions */
int64_t _291_main(void) {
    int64_t _291_t1;
    double _291_t2;
    struct0 _292_x;
    int64_t _291_t5;
    uint8_t _291_t7;
    int64_t _291_t3;
    int64_t _291_$retval;
    double _291_t8;
    uint8_t _291_t10;
    _291_t1 = 0;
    _291_t2 = 0.0e+00;
    _292_x = (struct0) {_291_t1, _291_t2};
    _291_t5 = 0;
    _291_t7 = _292_x._0 == _291_t5;
    if (_291_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _291_t8 = 0.0e+00;
    _291_t10 = _292_x._1 == _291_t8;
    if (_291_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _291_t3 = 0;
    goto BB10;
BB7:
    _291_t3 = 135;
    goto BB10;
BB10:
    _291_$retval = _291_t3;
    return _291_$retval;
}

int main(void) {
  printf("%ld",_291_main());
  return 0;
}
