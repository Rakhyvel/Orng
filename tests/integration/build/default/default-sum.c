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
int64_t _447_main(void);

/* Function definitions */
int64_t _447_main(void) {
    int64_t _447_t0;
    struct0 _448_x;
    int64_t _447_t3;
    uint8_t _447_t5;
    int64_t _447_t2;
    int64_t _447_$retval;
    _447_t0 = 0;
    _448_x = (struct0) {.tag=0, ._0=_447_t0};
    _447_t3 = 0;
    _447_t5 = _448_x._0 == _447_t3;
    if (_447_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _447_t2 = 133;
    goto BB6;
BB7:
    _447_t2 = 0;
    goto BB6;
BB6:
    _447_$retval = _447_t2;
    return _447_$retval;
}

int main(void) {
  printf("%ld",_447_main());
  return 0;
}
