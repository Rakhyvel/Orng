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
int64_t _625_main(void);

/* Function definitions */
int64_t _625_main(void){
    int64_t _625_t1;
    double _625_t2;
    struct0 _626_x;
    int64_t _625_t5;
    uint8_t _625_t7;
    int64_t _625_t3;
    int64_t _625_$retval;
    double _625_t8;
    uint8_t _625_t10;
    _625_t1 = 0;
    _625_t2 = 0.0e+00;
    _626_x = (struct0) {_625_t1, _625_t2};
    _625_t5 = 0;
    _625_t7 = _626_x._0 == _625_t5;
    if (_625_t7) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _625_t8 = 0.0e+00;
    _625_t10 = _626_x._1 == _625_t8;
    if (_625_t10) {
        goto BB7;
    } else {
        goto BB11;
    }
BB11:
    _625_t3 = 0;
    goto BB10;
BB7:
    _625_t3 = 135;
    goto BB10;
BB10:
    _625_$retval = _625_t3;
    return _625_$retval;
}

int main(void) {
  printf("%ld",_625_main());
  return 0;
}
