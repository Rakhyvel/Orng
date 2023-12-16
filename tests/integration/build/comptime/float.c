/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _207_f(float _207_x,double _207_y,float _207_z);
int64_t _204_main(void);

/* Function definitions */
int64_t _207_f(float _207_x,double _207_y,float _207_z) {
    float _207_t2;
    float _207_t3;
    uint8_t _207_t5;
    int64_t _207_$retval;
    (void)_207_y;
    _207_t2 = _207_x + _207_z;
    _207_t3 = 3.5e+00;
    _207_t5 = _207_t2 == _207_t3;
    if (_207_t5) {
        goto BB5;
    } else {
        goto BB9;
    }
BB5:
    _207_$retval = 259;
    return _207_$retval;
BB9:
    $lines[$line_idx++] = "tests/integration/comptime/float.orng:10:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int64_t _204_main(void) {
    int64_t _204_$retval;
    _204_$retval = 259;
    return _204_$retval;
}

int main(void) {
  printf("%ld",_204_main());
  return 0;
}
