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
int64_t _48_main(void);

/* Function definitions */
int64_t _48_main(void) {
    int64_t _48_t0;
    struct0 _49_x;
    uint8_t _48_t4;
    int64_t _48_t2;
    int64_t _48_$retval;
    _48_t0 = 211;
    _49_x = (struct0) {.tag=1, ._1=_48_t0};
    _48_t4 = 1;
    if (_48_t4) {
        goto BB2;
    } else {
        goto BB5;
    }
BB2:
    _48_t2 = _49_x._1;
    goto BB4;
BB5:
    _48_t2 = -1;
    goto BB4;
BB4:
    _48_$retval = _48_t2;
    return _48_$retval;
}

int main(void) {
  printf("%ld",_48_main());
  return 0;
}
