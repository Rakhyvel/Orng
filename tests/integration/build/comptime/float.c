/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _207_f(float _207_x,double _207_y,float _207_z,double _207_a);
int64_t _204_main(void);

/* Function definitions */
int64_t _207_f(float _207_x,double _207_y,float _207_z,double _207_a){
    float _207_t3;
    float _207_t4;
    uint8_t _207_t6;
    int64_t _207_$retval;
    double _207_t7;
    double _207_t8;
    uint8_t _207_t10;
    float _207_t12;
    uint8_t _207_t14;
    double _207_t15;
    uint8_t _207_t17;
    _207_t3 = _207_x + _207_z;
    _207_t4 = 3.5e+00;
    _207_t6 = _207_t3 == _207_t4;
    if (_207_t6) {
        goto BB3;
    } else {
        goto BB14;
    }
BB3:
    _207_t7 = _207_y + _207_a;
    _207_t8 = 4.14e+00;
    _207_t10 = _207_t7 == _207_t8;
    if (_207_t10) {
        goto BB9;
    } else {
        goto BB14;
    }
BB14:
    _207_t12 = 2.5e+00;
    _207_t14 = _207_x == _207_t12;
    if (_207_t14) {
        goto BB17;
    } else {
        goto BB13;
    }
BB9:
    _207_$retval = 259;
    return _207_$retval;
BB17:
    _207_t15 = 3.14e+00;
    _207_t17 = _207_y == _207_t15;
    if (_207_t17) {
        goto BB9;
    } else {
        goto BB13;
    }
BB13:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _204_main(void){
    int64_t _204_$retval;
    _204_$retval = 259;
    return _204_$retval;
}

int main(void) {
  printf("%ld",_204_main());
  return 0;
}
