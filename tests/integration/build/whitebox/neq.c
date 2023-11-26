/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1154_main(void);

/* Function definitions */
int64_t _1154_main(void) {
    int64_t _1155_x;
    int64_t* _1155_y;
    int64_t _1154_t5;
    uint8_t _1154_t6;
    uint8_t _1154_t4;
    int64_t _1154_t9;
    uint8_t _1154_t10;
    uint8_t _1154_t3;
    int64_t _1154_t2;
    int64_t _1154_t7;
    uint8_t _1154_t8;
    int64_t _1154_$retval;
    _1155_x = 3;
    _1155_y = &_1155_x;
    _1154_t5 = 5;
    _1154_t6 = *_1155_y != _1154_t5;
    if (_1154_t6) {
        goto BB1;
    } else {
        goto BB12;
    }
BB1:
    _1154_t4 = 1;
    goto BB2;
BB12:
    _1154_t7 = 4;
    _1154_t8 = _1154_t7 > *_1155_y;
    _1154_t4 = _1154_t8;
    goto BB2;
BB2:
    if (_1154_t4) {
        goto BB3;
    } else {
        goto BB11;
    }
BB3:
    _1154_t9 = 3;
    _1154_t10 = *_1155_y >= _1154_t9;
    _1154_t3 = _1154_t10;
    goto BB4;
BB11:
    _1154_t3 = 0;
    goto BB4;
BB4:
    if (_1154_t3) {
        goto BB5;
    } else {
        goto BB9;
    }
BB5:
    _1154_t2 = 33;
    goto BB8;
BB9:
    _1154_t2 = 10;
    goto BB8;
BB8:
    _1154_$retval = _1154_t2;
    return _1154_$retval;
}

int main(void) {
  printf("%ld",_1154_main());
  return 0;
}
