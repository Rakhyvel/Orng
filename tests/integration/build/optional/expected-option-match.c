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
int64_t _19_main(void);

/* Function definitions */
int64_t _19_main(void) {
    uint8_t _19_t1;
    uint8_t _19_t3;
    struct0 _19_t0;
    int64_t _19_t7;
    int64_t _19_t6;
    struct0 _20_x;
    uint64_t _19_t9;
    int64_t _19_t8;
    uint8_t _19_t4;
    uint8_t _19_t5;
    int64_t _19_$retval;
    _19_t1 = 1;
    _19_t3 = 0;
    if (_19_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _19_t6 = 1;
    _19_t0 = (struct0) {.tag=1, ._1=_19_t6};
    goto BB4;
BB9:
    _19_t4 = 0;
    _19_t5 = _19_t1 == _19_t4;
    if (_19_t5) {
        goto BB11;
    } else {
        goto BB12;
    }
BB4:
    _20_x = _19_t0;
    _19_t9 = _19_t0.tag;
    if (_19_t9) {
        goto BB5;
    } else {
        goto BB8;
    }
BB11:
    _19_t7 = 2;
    _19_t0 = (struct0) {.tag=1, ._1=_19_t7};
    goto BB4;
BB12:
    _19_t0 = (struct0) {.tag=0};
    goto BB4;
BB5:
    _19_t8 = _20_x._1;
    goto BB7;
BB8:
    _19_t8 = 129;
    goto BB7;
BB7:
    _19_$retval = _19_t8;
    return _19_$retval;
}

int main(void) {
  printf("%ld",_19_main());
  return 0;
}
