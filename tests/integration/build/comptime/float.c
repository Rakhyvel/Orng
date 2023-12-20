/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _147_f(float _147_x,double _147_y,float _147_z,double _147_a);
int64_t _144_main(void);

/* Function definitions */
int64_t _147_f(float _147_x,double _147_y,float _147_z,double _147_a){
    float _147_t3;
    float _147_t4;
    uint8_t _147_t6;
    int64_t _147_$retval;
    double _147_t7;
    double _147_t8;
    uint8_t _147_t10;
    float _147_t12;
    uint8_t _147_t14;
    double _147_t15;
    uint8_t _147_t17;
    _147_t3 = _147_x + _147_z;
    _147_t4 = 3.5e+00;
    _147_t6 = _147_t3 == _147_t4;
    if (_147_t6) {
        goto BB3;
    } else {
        goto BB14;
    }
BB3:
    _147_t7 = _147_y + _147_a;
    _147_t8 = 4.14e+00;
    _147_t10 = _147_t7 == _147_t8;
    if (_147_t10) {
        goto BB9;
    } else {
        goto BB14;
    }
BB14:
    _147_t12 = 2.5e+00;
    _147_t14 = _147_x == _147_t12;
    if (_147_t14) {
        goto BB17;
    } else {
        goto BB13;
    }
BB9:
    _147_$retval = 259;
    return _147_$retval;
BB17:
    _147_t15 = 3.14e+00;
    _147_t17 = _147_y == _147_t15;
    if (_147_t17) {
        goto BB9;
    } else {
        goto BB13;
    }
BB13:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _144_main(void){
    int64_t _144_$retval;
    _144_$retval = 259;
    return _144_$retval;
}

int main(void) {
  printf("%ld",_144_main());
  return 0;
}
