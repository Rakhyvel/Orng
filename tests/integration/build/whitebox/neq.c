/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _57_main(void);

/* Function definitions */
int64_t _57_main(void) {
    int64_t _58_x;
    int64_t* _58_y;
    int64_t _57_t5;
    uint8_t _57_t6;
    uint8_t _57_t4;
    int64_t _57_t9;
    uint8_t _57_t10;
    uint8_t _57_t3;
    int64_t _57_t2;
    int64_t _57_t7;
    uint8_t _57_t8;
    int64_t _57_$retval;
    _58_x = 3;
    _58_y = &_58_x;
    _57_t5 = 5;
    _57_t6 = *_58_y != _57_t5;
    if (_57_t6) {
        goto BB1;
    } else {
        goto BB12;
    }
BB1:
    _57_t4 = 1;
    goto BB2;
BB12:
    _57_t7 = 4;
    _57_t8 = _57_t7 > *_58_y;
    _57_t4 = _57_t8;
    goto BB2;
BB2:
    if (_57_t4) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _57_t9 = 3;
    _57_t10 = *_58_y >= _57_t9;
    _57_t3 = _57_t10;
    goto BB4;
BB11:
    _57_t3 = 0;
    goto BB4;
BB4:
    if (_57_t3) {
        goto BB5;
    } else {
        goto BB9;
    }
BB5:
    _57_t2 = 33;
    goto BB8;
BB9:
    _57_t2 = 10;
    goto BB8;
BB8:
    _57_$retval = _57_t2;
    return _57_$retval;
}

int main(void) {
  printf("%ld",_57_main());
  return 0;
}
