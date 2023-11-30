/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1654_main(void);

/* Function definitions */
int64_t _1654_main(void) {
    int64_t _1655_x;
    int64_t* _1655_y;
    int64_t _1654_t5;
    uint8_t _1654_t6;
    int64_t _1654_t2;
    int64_t _1654_t7;
    uint8_t _1654_t8;
    int64_t _1654_t9;
    uint8_t _1654_t10;
    int64_t _1654_$retval;
    _1655_x = 3;
    _1655_y = &_1655_x;
    _1654_t5 = 5;
    _1654_t6 = *_1655_y != _1654_t5;
    if (_1654_t6) {
        goto BB3;
    } else {
        goto BB12;
    }
BB3:
    _1654_t9 = 3;
    _1654_t10 = *_1655_y >= _1654_t9;
    if (_1654_t10) {
        goto BB5;
    } else {
        goto BB9;
    }
BB12:
    _1654_t7 = 4;
    _1654_t8 = _1654_t7 > *_1655_y;
    if (_1654_t8) {
        goto BB3;
    } else {
        goto BB9;
    }
BB5:
    _1654_t2 = 33;
    goto BB8;
BB9:
    _1654_t2 = 10;
    goto BB8;
BB8:
    _1654_$retval = _1654_t2;
    return _1654_$retval;
}

int main(void) {
  printf("%ld",_1654_main());
  return 0;
}
