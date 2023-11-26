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
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _41_main(void);

/* Function definitions */
int64_t _41_main(void) {
    int64_t _41_t0;
    struct0 _42_x;
    int64_t _41_t3;
    uint8_t _41_t5;
    uint8_t _41_t4;
    int64_t _41_t2;
    int64_t _41_$retval;
    _41_t0 = 0;
    _42_x = (struct0) {.tag=0, ._0=_41_t0};
    _41_t3 = 0;
    _41_t5 = _42_x._0 == _41_t3;
    if (_41_t5) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _41_t4 = 1;
    goto BB2;
BB9:
    _41_t4 = 0;
    goto BB2;
BB2:
    if (_41_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _41_t2 = 133;
    goto BB6;
BB7:
    _41_t2 = 0;
    goto BB6;
BB6:
    _41_$retval = _41_t2;
    return _41_$retval;
}

int main(void) {
  printf("%ld",_41_main());
  return 0;
}
