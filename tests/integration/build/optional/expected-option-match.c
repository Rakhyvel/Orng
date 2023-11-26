/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _690_main(void);

/* Function definitions */
int64_t _690_main(void) {
    uint8_t _690_t1;
    uint8_t _690_t3;
    struct0 _690_t0;
    int64_t _690_t7;
    int64_t _690_t6;
    struct0 _691_x;
    uint64_t _690_t9;
    int64_t _690_t8;
    uint8_t _690_t4;
    uint8_t _690_t5;
    int64_t _690_$retval;
    _690_t1 = 1;
    _690_t3 = 0;
    if (_690_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _690_t6 = 1;
    _690_t0 = (struct0) {.tag=1, ._1=_690_t6};
    goto BB4;
BB9:
    _690_t4 = 0;
    _690_t5 = _690_t1 == _690_t4;
    if (_690_t5) {
        goto BB11;
    } else {
        goto BB12;
    }
BB4:
    _691_x = _690_t0;
    _690_t9 = _690_t0.tag;
    if (_690_t9) {
        goto BB5;
    } else {
        goto BB8;
    }
BB11:
    _690_t7 = 2;
    _690_t0 = (struct0) {.tag=1, ._1=_690_t7};
    goto BB4;
BB12:
    _690_t0 = (struct0) {.tag=0};
    goto BB4;
BB5:
    _690_t8 = _691_x._1;
    goto BB7;
BB8:
    _690_t8 = 129;
    goto BB7;
BB7:
    _690_$retval = _690_t8;
    return _690_$retval;
}

int main(void) {
  printf("%ld",_690_main());
  return 0;
}
