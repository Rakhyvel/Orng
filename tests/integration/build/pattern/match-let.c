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
int64_t _933_main(void);

/* Function definitions */
int64_t _933_main(void) {
    int64_t _933_t2;
    int64_t _933_t3;
    int64_t _933_t4;
    struct0 _934_x;
    int64_t _933_t5;
    int64_t _933_t6;
    uint8_t _933_t7;
    int64_t _933_t0;
    int64_t _933_t10;
    uint8_t _933_t11;
    int64_t _933_$retval;
    int64_t _933_t8;
    uint8_t _933_t9;
    _933_t2 = 1;
    _933_t3 = 2;
    _933_t4 = 3;
    _934_x = (struct0) {_933_t2, _933_t3, _933_t4};
    _933_t5 = 2;
    _933_t6 = 1;
    _933_t7 = *((int64_t*)&_934_x + _933_t5) == _933_t6;
    if (_933_t7) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _933_t0 = 2;
    goto BB5;
BB6:
    _933_t8 = 2;
    _933_t9 = *((int64_t*)&_934_x + _933_t5) == _933_t8;
    if (_933_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB5:
    _933_$retval = _933_t0;
    return _933_$retval;
BB8:
    _933_t0 = 22;
    goto BB5;
BB9:
    _933_t10 = 3;
    _933_t11 = *((int64_t*)&_934_x + _933_t5) == _933_t10;
    if (_933_t11) {
        goto BB11;
    } else {
        goto BB13;
    }
BB11:
    _933_t0 = 222;
    goto BB5;
BB13:
    _933_t0 = 0;
    goto BB5;
}

int main(void) {
  printf("%ld",_933_main());
  return 0;
}
