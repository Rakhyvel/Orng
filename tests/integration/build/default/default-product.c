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
int64_t _258_main(void);

/* Function definitions */
int64_t _258_main(void) {
    int64_t _258_t1;
    double _258_t2;
    struct0 _259_x;
    int64_t _258_t5;
    uint8_t _258_t7;
    int64_t _258_t3;
    int64_t _258_$retval;
    double _258_t8;
    uint8_t _258_t10;
    _258_t1 = 0;
    _258_t2 = 0;
    _259_x = (struct0) {_258_t1, _258_t2};
    _258_t5 = 0;
    _258_t7 = _259_x._0 == _258_t5;
    if (_258_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _258_t8 = 0.0e+00;
    _258_t10 = _259_x._1 == _258_t8;
    if (_258_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _258_t3 = 0;
    goto BB10;
BB7:
    _258_t3 = 135;
    goto BB10;
BB10:
    _258_$retval = _258_t3;
    return _258_$retval;
}

int main(void) {
  printf("%ld",_258_main());
  return 0;
}
