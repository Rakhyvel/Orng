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
int64_t _813_main(void);

/* Function definitions */
int64_t _813_main(void) {
    int64_t _813_t2;
    int64_t _813_t3;
    int64_t _813_t4;
    struct0 _814_x;
    int64_t _813_t5;
    int64_t _813_t6;
    uint8_t _813_t7;
    int64_t _813_t0;
    int64_t _813_t10;
    uint8_t _813_t11;
    int64_t _813_$retval;
    int64_t _813_t8;
    uint8_t _813_t9;
    _813_t2 = 1;
    _813_t3 = 2;
    _813_t4 = 3;
    _814_x = (struct0) {_813_t2, _813_t3, _813_t4};
    _813_t5 = 2;
    _813_t6 = 1;
    _813_t7 = *((int64_t*)&_814_x + _813_t5) == _813_t6;
    if (_813_t7) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _813_t0 = 2;
    goto BB5;
BB6:
    _813_t8 = 2;
    _813_t9 = *((int64_t*)&_814_x + _813_t5) == _813_t8;
    if (_813_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _813_$retval = _813_t0;
    return _813_$retval;
BB8:
    _813_t0 = 22;
    goto BB5;
BB9:
    _813_t10 = 3;
    _813_t11 = *((int64_t*)&_814_x + _813_t5) == _813_t10;
    if (_813_t11) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _813_t0 = 222;
    goto BB5;
BB13:
    _813_t0 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_813_main());
  return 0;
}
