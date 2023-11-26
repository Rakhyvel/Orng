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
int64_t _1014_main(void);

/* Function definitions */
int64_t _1014_main(void) {
    int64_t _1014_t0;
    struct0 _1015_x;
    uint8_t _1014_t5;
    uint8_t _1014_t4;
    int64_t _1014_t2;
    int64_t _1014_$retval;
    _1014_t0 = 210;
    _1015_x = (struct0) {.tag=1, ._1=_1014_t0};
    _1014_t5 = 0;
    if (_1014_t5) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1014_t4 = 1;
    goto BB2;
BB9:
    _1014_t4 = 0;
    goto BB2;
BB2:
    if (_1014_t4) {
        goto BB3;
    } else {
        goto BB8;
    }
BB3:
    _1014_t2 = -1;
    goto BB6;
BB8:
    _1014_t2 = _1015_x._1;
    goto BB6;
BB6:
    _1014_$retval = _1014_t2;
    return _1014_$retval;
}

int main(void) {
  printf("%ld",_1014_main());
  return 0;
}
