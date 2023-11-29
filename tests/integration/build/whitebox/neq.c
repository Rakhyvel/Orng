/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1675_main(void);

/* Function definitions */
int64_t _1675_main(void) {
    int64_t _1676_x;
    int64_t* _1676_y;
    int64_t _1675_t5;
    uint8_t _1675_t6;
    int64_t _1675_t2;
    int64_t _1675_t7;
    uint8_t _1675_t8;
    int64_t _1675_t9;
    uint8_t _1675_t10;
    int64_t _1675_$retval;
    _1676_x = 3;
    _1676_y = &_1676_x;
    _1675_t5 = 5;
    _1675_t6 = *_1676_y != _1675_t5;
    if (_1675_t6) {
        goto BB3;
    } else {
        goto BB12;
    }
BB3:
    _1675_t9 = 3;
    _1675_t10 = *_1676_y >= _1675_t9;
    if (_1675_t10) {
        goto BB5;
    } else {
        goto BB9;
    }
BB12:
    _1675_t7 = 4;
    _1675_t8 = _1675_t7 > *_1676_y;
    if (_1675_t8) {
        goto BB3;
    } else {
        goto BB9;
    }
BB5:
    _1675_t2 = 33;
    goto BB8;
BB9:
    _1675_t2 = 10;
    goto BB8;
BB8:
    _1675_$retval = _1675_t2;
    return _1675_$retval;
}

int main(void) {
  printf("%ld",_1675_main());
  return 0;
}
