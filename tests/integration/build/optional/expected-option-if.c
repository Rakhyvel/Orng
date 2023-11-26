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
int64_t _8_main(void);

/* Function definitions */
int64_t _8_main(void) {
    uint8_t _8_t1;
    int64_t _8_t2;
    struct0 _8_t0;
    struct0 _9_y;
    uint64_t _8_t4;
    int64_t _8_t3;
    int64_t _8_$retval;
    _8_t1 = 0;
    if (_8_t1) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    _8_t2 = 45;
    _8_t0 = (struct0) {.tag=1, ._1=_8_t2};
    goto BB3;
BB8:
    _8_t0 = (struct0) {.tag=0};
    goto BB3;
BB3:
    _9_y = _8_t0;
    _8_t4 = _8_t0.tag;
    if (_8_t4) {
        goto BB4;
    } else {
        goto BB7;
    }
BB4:
    _8_t3 = _9_y._1;
    goto BB6;
BB7:
    _8_t3 = 124;
    goto BB6;
BB6:
    _8_$retval = _8_t3;
    return _8_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}
