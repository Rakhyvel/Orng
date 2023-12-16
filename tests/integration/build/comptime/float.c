/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _221_f(float _221_x,double _221_y,float _221_z,double _221_a);
int64_t _218_main(void);

/* Function definitions */
int64_t _221_f(float _221_x,double _221_y,float _221_z,double _221_a){
    float _221_t3;
    float _221_t4;
    uint8_t _221_t6;
    int64_t _221_$retval;
    double _221_t7;
    double _221_t8;
    uint8_t _221_t10;
    float _221_t12;
    uint8_t _221_t14;
    double _221_t15;
    uint8_t _221_t17;
    _221_t3 = _221_x + _221_z;
    _221_t4 = 3.5e+00;
    _221_t6 = _221_t3 == _221_t4;
    if (_221_t6) {
        goto BB3;
    } else {
        goto BB14;
    }
BB3:
    _221_t7 = _221_y + _221_a;
    _221_t8 = 4.14e+00;
    _221_t10 = _221_t7 == _221_t8;
    if (_221_t10) {
        goto BB9;
    } else {
        goto BB14;
    }
BB14:
    _221_t12 = 2.5e+00;
    _221_t14 = _221_x == _221_t12;
    if (_221_t14) {
        goto BB17;
    } else {
        goto BB13;
    }
BB9:
    _221_$retval = 259;
    return _221_$retval;
BB17:
    _221_t15 = 3.14e+00;
    _221_t17 = _221_y == _221_t15;
    if (_221_t17) {
        goto BB9;
    } else {
        goto BB13;
    }
BB13:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _218_main(void){
    int64_t _218_$retval;
    _218_$retval = 259;
    return _218_$retval;
}

int main(void) {
  printf("%ld",_218_main());
  return 0;
}
