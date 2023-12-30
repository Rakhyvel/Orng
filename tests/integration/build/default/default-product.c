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
    int64_t _540_t4;
    uint8_t _540_t6;
    int64_t _540_t3;
    double _540_t7;
    uint8_t _540_t9;
    int64_t _540_$retval;
    _540_t1 = 0;
    _540_t2 = 0.0e+00;
    _541_x = (struct0) {_540_t1, _540_t2};
    _540_t4 = 0;
    _540_t6 = _541_x._0==_540_t4;
    if (_540_t6) {
        goto BB643;
    } else {
        goto BB650;
    }
BB643:
    _540_t7 = 0.0e+00;
    _540_t9 = _541_x._1==_540_t7;
    if (_540_t9) {
        goto BB646;
    } else {
        goto BB650;
    }
BB650:
    _540_t3 = 0;
    goto BB649;
BB646:
    _540_t3 = 135;
    goto BB649;
BB649:
    _540_$retval = _540_t3;
    return _540_$retval;
}

int main(void) {
  printf("%ld",_540_main());
  return 0;
}
