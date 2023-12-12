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
int64_t _299_main(void);

/* Function definitions */
int64_t _299_main(void) {
    int64_t _299_t1;
    double _299_t2;
    struct0 _300_x;
    int64_t _299_t5;
    uint8_t _299_t7;
    int64_t _299_t3;
    int64_t _299_$retval;
    double _299_t8;
    uint8_t _299_t10;
    _299_t1 = 0;
    _299_t2 = 0.0e+00;
    _300_x = (struct0) {_299_t1, _299_t2};
    _299_t5 = 0;
    _299_t7 = _300_x._0 == _299_t5;
    if (_299_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _299_t8 = 0.0e+00;
    _299_t10 = _300_x._1 == _299_t8;
    if (_299_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _299_t3 = 0;
    goto BB10;
BB7:
    _299_t3 = 135;
    goto BB10;
BB10:
    _299_$retval = _299_t3;
    return _299_$retval;
}

int main(void) {
  printf("%ld",_299_main());
  return 0;
}
