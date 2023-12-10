/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1247_main(void);

/* Function definitions */
int64_t _1247_main(void) {
    int64_t _1248_x;
    int64_t* _1248_y;
    int64_t _1247_t5;
    uint8_t _1247_t6;
    int64_t _1247_t2;
    int64_t _1247_t7;
    uint8_t _1247_t8;
    int64_t _1247_t9;
    uint8_t _1247_t10;
    int64_t _1247_$retval;
    _1248_x = 3;
    _1248_y = &_1248_x;
    _1247_t5 = 5;
    _1247_t6 = *_1248_y != _1247_t5;
    if (_1247_t6) {
        goto BB3;
    } else {
        goto BB12;
    }
BB3:
    _1247_t9 = 3;
    _1247_t10 = *_1248_y >= _1247_t9;
    if (_1247_t10) {
        goto BB5;
    } else {
        goto BB9;
    }
BB12:
    _1247_t7 = 4;
    _1247_t8 = _1247_t7 > *_1248_y;
    if (_1247_t8) {
        goto BB3;
    } else {
        goto BB9;
    }
BB5:
    _1247_t2 = 33;
    goto BB8;
BB9:
    _1247_t2 = 10;
    goto BB8;
BB8:
    _1247_$retval = _1247_t2;
    return _1247_$retval;
}

int main(void) {
  printf("%ld",_1247_main());
  return 0;
}
