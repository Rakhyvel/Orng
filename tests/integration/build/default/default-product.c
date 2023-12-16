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
int64_t _540_main(void);

/* Function definitions */
int64_t _540_main(void){
    int64_t _540_t1;
    double _540_t2;
    struct0 _541_x;
    int64_t _540_t5;
    uint8_t _540_t7;
    int64_t _540_t3;
    int64_t _540_$retval;
    double _540_t8;
    uint8_t _540_t10;
    _540_t1 = 0;
    _540_t2 = 0.0e+00;
    _541_x = (struct0) {_540_t1, _540_t2};
    _540_t5 = 0;
    _540_t7 = _541_x._0 == _540_t5;
    if (_540_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _540_t8 = 0.0e+00;
    _540_t10 = _541_x._1 == _540_t8;
    if (_540_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _540_t3 = 0;
    goto BB10;
BB7:
    _540_t3 = 135;
    goto BB10;
BB10:
    _540_$retval = _540_t3;
    return _540_$retval;
}

int main(void) {
  printf("%ld",_540_main());
  return 0;
}
