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
int64_t _679_main(void);

/* Function definitions */
int64_t _679_main(void) {
    uint8_t _679_t1;
    int64_t _679_t2;
    struct0 _679_t0;
    struct0 _680_y;
    uint64_t _679_t4;
    int64_t _679_t3;
    int64_t _679_$retval;
    _679_t1 = 0;
    if (_679_t1) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _679_t2 = 45;
    _679_t0 = (struct0) {.tag=1, ._1=_679_t2};
    goto BB3;
BB8:
    _679_t0 = (struct0) {.tag=0};
    goto BB3;
BB3:
    _680_y = _679_t0;
    _679_t4 = _679_t0.tag;
    if (_679_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _679_t3 = _680_y._1;
    goto BB6;
BB7:
    _679_t3 = 124;
    goto BB6;
BB6:
    _679_$retval = _679_t3;
    return _679_$retval;
}

int main(void) {
  printf("%ld",_679_main());
  return 0;
}
