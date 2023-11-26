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
        uint32_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _245_main(void);

/* Function definitions */
int64_t _245_main(void) {
    uint32_t _245_t0;
    struct0 _246_x;
    uint64_t _245_t3;
    int64_t _245_t2;
    int64_t _245_$retval;
    _245_t0 = 100;
    _246_x = (struct0) {.tag=1, ._1=_245_t0};
    _245_t3 = 1;
    if (_245_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _245_t2 = 118;
    goto BB3;
BB4:
    _245_t2 = _246_x._0;
    goto BB3;
BB3:
    _245_$retval = _245_t2;
    return _245_$retval;
}

int main(void) {
  printf("%ld",_245_main());
  return 0;
}
