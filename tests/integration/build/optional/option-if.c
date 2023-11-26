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
int64_t _30_main(void);

/* Function definitions */
int64_t _30_main(void) {
    uint8_t _30_t1;
    int64_t _30_t2;
    struct0 _30_t0;
    struct0 _31_y;
    uint64_t _30_t4;
    int64_t _30_t3;
    int64_t _30_$retval;
    _30_t1 = 0;
    if (_30_t1) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _30_t2 = 45;
    _30_t0 = (struct0) {.tag=1, ._1=_30_t2};
    goto BB3;
BB8:
    _30_t0 = (struct0) {.tag=0};
    goto BB3;
BB3:
    _31_y = _30_t0;
    _30_t4 = _30_t0.tag;
    if (_30_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _30_t3 = _31_y._1;
    goto BB6;
BB7:
    _30_t3 = 115;
    goto BB6;
BB6:
    _30_$retval = _30_t3;
    return _30_$retval;
}

int main(void) {
  printf("%ld",_30_main());
  return 0;
}
