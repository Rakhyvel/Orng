/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    double _1;
};

/* Function forward definitions */
int64_t _540_main(void);


/* Function definitions */
int64_t _540_main(void){
    int64_t _540_t1;
    double _540_t2;
    struct struct0 _541_x;
    int64_t _540_t4;
    uint8_t _540_t6;
    int64_t _540_t3;
    double _540_t7;
    uint8_t _540_t9;
    int64_t _540_$retval;
    _540_t1 = 0;
    _540_t2 = 0.0e+00;
    _541_x = (struct struct0) {_540_t1, _540_t2};
    _540_t4 = 0;
    _540_t6 = _541_x._0==_540_t4;
    if (_540_t6) {
        goto BB633;
    } else {
        goto BB640;
    }
BB633:
    _540_t7 = 0.0e+00;
    _540_t9 = _541_x._1==_540_t7;
    if (_540_t9) {
        goto BB636;
    } else {
        goto BB640;
    }
BB640:
    _540_t3 = 0;
    goto BB639;
BB636:
    _540_t3 = 135;
    goto BB639;
BB639:
    _540_$retval = _540_t3;
    return _540_$retval;
}


int main(void) {
  printf("%ld",_540_main());
  return 0;
}
