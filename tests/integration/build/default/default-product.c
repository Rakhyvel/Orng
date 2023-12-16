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
int64_t _480_main(void);

/* Function definitions */
int64_t _480_main(void){
    int64_t _480_t1;
    double _480_t2;
    struct0 _481_x;
    int64_t _480_t5;
    uint8_t _480_t7;
    int64_t _480_t3;
    int64_t _480_$retval;
    double _480_t8;
    uint8_t _480_t10;
    _480_t1 = 0;
    _480_t2 = 0.0e+00;
    _481_x = (struct0) {_480_t1, _480_t2};
    _480_t5 = 0;
    _480_t7 = _481_x._0 == _480_t5;
    if (_480_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _480_t8 = 0.0e+00;
    _480_t10 = _481_x._1 == _480_t8;
    if (_480_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _480_t3 = 0;
    goto BB10;
BB7:
    _480_t3 = 135;
    goto BB10;
BB10:
    _480_$retval = _480_t3;
    return _480_$retval;
}

int main(void) {
  printf("%ld",_480_main());
  return 0;
}
