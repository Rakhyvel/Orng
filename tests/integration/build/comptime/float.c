/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _65_f(float _65_x,double _65_y,float _65_z,double _65_a);
int64_t _62_main(void);

/* Function definitions */
int64_t _65_f(float _65_x,double _65_y,float _65_z,double _65_a){
    float _65_t3;
    float _65_t4;
    uint8_t _65_t6;
    int64_t _65_$retval;
    double _65_t7;
    double _65_t8;
    uint8_t _65_t10;
    float _65_t12;
    uint8_t _65_t14;
    double _65_t15;
    uint8_t _65_t17;
    _65_t3 = _65_x + _65_z;
    _65_t4 = 3.5e+00;
    _65_t6 = _65_t3 == _65_t4;
    if (_65_t6) {
        goto BB3;
    } else {
        goto BB14;
    }
BB3:
    _65_t7 = _65_y + _65_a;
    _65_t8 = 4.14e+00;
    _65_t10 = _65_t7 == _65_t8;
    if (_65_t10) {
        goto BB9;
    } else {
        goto BB14;
    }
BB14:
    _65_t12 = 2.5e+00;
    _65_t14 = _65_x == _65_t12;
    if (_65_t14) {
        goto BB17;
    } else {
        goto BB13;
    }
BB9:
    _65_$retval = 259;
    return _65_$retval;
BB17:
    _65_t15 = 3.14e+00;
    _65_t17 = _65_y == _65_t15;
    if (_65_t17) {
        goto BB9;
    } else {
        goto BB13;
    }
BB13:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _62_main(void){
    int64_t _62_$retval;
    _62_$retval = 259;
    return _62_$retval;
}

int main(void) {
  printf("%ld",_62_main());
  return 0;
}
