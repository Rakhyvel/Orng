/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1677_main(void);

/* Function definitions */
int64_t _1677_main(void) {
    int64_t _1678_x;
    int64_t* _1678_y;
    int64_t _1677_t5;
    uint8_t _1677_t6;
    int64_t _1677_t2;
    int64_t _1677_t7;
    uint8_t _1677_t8;
    int64_t _1677_t9;
    uint8_t _1677_t10;
    int64_t _1677_$retval;
    _1678_x = 3;
    _1678_y = &_1678_x;
    _1677_t5 = 5;
    _1677_t6 = *_1678_y != _1677_t5;
    if (_1677_t6) {
        goto BB3;
    } else {
        goto BB12;
    }
BB3:
    _1677_t9 = 3;
    _1677_t10 = *_1678_y >= _1677_t9;
    if (_1677_t10) {
        goto BB5;
    } else {
        goto BB9;
    }
BB12:
    _1677_t7 = 4;
    _1677_t8 = _1677_t7 > *_1678_y;
    if (_1677_t8) {
        goto BB3;
    } else {
        goto BB9;
    }
BB5:
    _1677_t2 = 33;
    goto BB8;
BB9:
    _1677_t2 = 10;
    goto BB8;
BB8:
    _1677_$retval = _1677_t2;
    return _1677_$retval;
}

int main(void) {
  printf("%ld",_1677_main());
  return 0;
}
