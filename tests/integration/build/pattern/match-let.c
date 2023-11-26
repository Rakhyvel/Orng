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
int64_t _98_main(void);

/* Function definitions */
int64_t _98_main(void) {
    int64_t _98_t2;
    int64_t _98_t3;
    int64_t _98_t4;
    struct0 _99_x;
    int64_t _98_t5;
    int64_t _98_t6;
    uint8_t _98_t7;
    int64_t _98_t0;
    int64_t _98_t10;
    uint8_t _98_t11;
    int64_t _98_$retval;
    int64_t _98_t8;
    uint8_t _98_t9;
    _98_t2 = 1;
    _98_t3 = 2;
    _98_t4 = 3;
    _99_x = (struct0) {_98_t2, _98_t3, _98_t4};
    _98_t5 = 2;
    _98_t6 = 1;
    _98_t7 = *((int64_t*)&_99_x + _98_t5) == _98_t6;
    if (_98_t7) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _98_t0 = 2;
    goto BB5;
BB6:
    _98_t8 = 2;
    _98_t9 = *((int64_t*)&_99_x + _98_t5) == _98_t8;
    if (_98_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _98_$retval = _98_t0;
    return _98_$retval;
BB8:
    _98_t0 = 22;
    goto BB5;
BB9:
    _98_t10 = 3;
    _98_t11 = *((int64_t*)&_99_x + _98_t5) == _98_t10;
    if (_98_t11) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _98_t0 = 222;
    goto BB5;
BB13:
    _98_t0 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_98_main());
  return 0;
}
