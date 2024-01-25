/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _154_f(float _154_x, double _154_y, float _154_z, double _154_a);
int64_t _150_main(void);


/* Function definitions */
int64_t _154_f(float _154_x, double _154_y, float _154_z, double _154_a){
    float _154_t1;
    float _154_t2;
    uint8_t _154_t4;
    float _154_t10;
    uint8_t _154_t12;
    double _154_t5;
    double _154_t6;
    uint8_t _154_t8;
    double _154_t13;
    uint8_t _154_t15;
    int64_t _154_$retval;
    _154_t1 = _154_x+_154_z;
    _154_t2 = 3.5e+00;
    _154_t4 = _154_t1==_154_t2;
    if (_154_t4) {
        goto BB129;
    } else {
        goto BB133;
    }
BB129:
    _154_t5 = _154_y+_154_a;
    _154_t6 = 4.14e+00;
    _154_t8 = _154_t5==_154_t6;
    if (_154_t8) {
        goto BB140;
    } else {
        goto BB133;
    }
BB133:
    _154_t10 = 2.5e+00;
    _154_t12 = _154_x==_154_t10;
    if (_154_t12) {
        goto BB136;
    } else {
        goto BB144;
    }
BB140:
    _154_$retval = 259;
    return _154_$retval;
BB136:
    _154_t13 = 3.14e+00;
    _154_t15 = _154_y==_154_t13;
    if (_154_t15) {
        goto BB140;
    } else {
        goto BB144;
    }
BB144:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _150_main(void){
    int64_t _150_$retval;
    _150_$retval = 259;
    return _150_$retval;
}


int main(void) {
  printf("%ld",_150_main());
  return 0;
}
