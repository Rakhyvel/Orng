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
int64_t _227_main(void);

/* Function definitions */
int64_t _227_main(void) {
    int64_t _227_t1;
    double _227_t2;
    struct0 _228_x;
    int64_t _227_t5;
    uint8_t _227_t7;
    uint8_t _227_t6;
    double _227_t8;
    uint8_t _227_t10;
    uint8_t _227_t9;
    uint8_t _227_t4;
    int64_t _227_t3;
    int64_t _227_$retval;
    _227_t1 = 0;
    _227_t2 = 0;
    _228_x = (struct0) {_227_t1, _227_t2};
    _227_t5 = 0;
    _227_t7 = _228_x._0 == _227_t5;
    if (_227_t7) {
        goto BB1;
    } else {
        goto BB15;
    }
BB1:
    _227_t6 = 1;
    goto BB2;
BB15:
    _227_t6 = 0;
    goto BB2;
BB2:
    if (_227_t6) {
        goto BB3;
    } else {
        goto BB14;
    }
BB3:
    _227_t8 = 0.0e+00;
    _227_t10 = _228_x._1 == _227_t8;
    if (_227_t10) {
        goto BB4;
    } else {
        goto BB13;
    }
BB14:
    _227_t4 = 0;
    goto BB6;
BB4:
    _227_t9 = 1;
    goto BB5;
BB13:
    _227_t9 = 0;
    goto BB5;
BB6:
    if (_227_t4) {
        goto BB7;
    } else {
        goto BB11;
    }
BB5:
    _227_t4 = _227_t9;
    goto BB6;
BB7:
    _227_t3 = 135;
    goto BB10;
BB11:
    _227_t3 = 0;
    goto BB10;
BB10:
    _227_$retval = _227_t3;
    return _227_$retval;
}

int main(void) {
  printf("%ld",_227_main());
  return 0;
}
