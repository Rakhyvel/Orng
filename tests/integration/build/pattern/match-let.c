/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _1151_main(void);

/* Function definitions */
int64_t _1151_main(void) {
    int64_t _1151_t2;
    int64_t _1151_t3;
    int64_t _1151_t4;
    struct0 _1152_x;
    int64_t _1151_t5;
    int64_t _1151_t6;
    uint8_t _1151_t7;
    int64_t _1151_t0;
    int64_t _1151_t10;
    uint8_t _1151_t11;
    int64_t _1151_$retval;
    int64_t _1151_t8;
    uint8_t _1151_t9;
    _1151_t2 = 1;
    _1151_t3 = 2;
    _1151_t4 = 3;
    _1152_x = (struct0) {_1151_t2, _1151_t3, _1151_t4};
    _1151_t5 = 2;
    _1151_t6 = 1;
    _1151_t7 = *((int64_t*)&_1152_x + _1151_t5) == _1151_t6;
    if (_1151_t7) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1151_t0 = 2;
    goto BB5;
BB6:
    _1151_t8 = 2;
    _1151_t9 = *((int64_t*)&_1152_x + _1151_t5) == _1151_t8;
    if (_1151_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _1151_$retval = _1151_t0;
    return _1151_$retval;
BB8:
    _1151_t0 = 22;
    goto BB5;
BB9:
    _1151_t10 = 3;
    _1151_t11 = *((int64_t*)&_1152_x + _1151_t5) == _1151_t10;
    if (_1151_t11) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _1151_t0 = 222;
    goto BB5;
BB13:
    _1151_t0 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_1151_main());
  return 0;
}
