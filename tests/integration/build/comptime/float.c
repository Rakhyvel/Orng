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
    float _147_t1;
    float _147_t2;
    uint8_t _147_t4;
    float _147_t10;
    uint8_t _147_t12;
    double _147_t5;
    double _147_t6;
    uint8_t _147_t8;
    double _147_t13;
    uint8_t _147_t15;
    int64_t _147_$retval;
    _147_t1 = _147_x+_147_z;
    _147_t2 = 3.5e+00;
    _147_t4 = _147_t1==_147_t2;
    if (_147_t4) {
        goto BB125;
    } else {
        goto BB129;
    }
BB125:
    _147_t5 = _147_y+_147_a;
    _147_t6 = 4.14e+00;
    _147_t8 = _147_t5==_147_t6;
    if (_147_t8) {
        goto BB136;
    } else {
        goto BB129;
    }
BB129:
    _147_t10 = 2.5e+00;
    _147_t12 = _147_x==_147_t10;
    if (_147_t12) {
        goto BB132;
    } else {
        goto BB140;
    }
BB136:
    _147_$retval = 259;
    return _147_$retval;
BB132:
    _147_t13 = 3.14e+00;
    _147_t15 = _147_y==_147_t13;
    if (_147_t15) {
        goto BB136;
    } else {
        goto BB140;
    }
BB140:
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
