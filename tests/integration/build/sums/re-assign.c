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
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _44_main(void);

/* Function definitions */
int64_t _44_main(void) {
    int64_t _44_t0;
    struct0 _45_x;
    int64_t _44_$retval;
    _44_t0 = 4;
    _45_x = (struct0) {.tag=0, ._0=_44_t0};
    _45_x._0 = 103;
    _44_$retval = _45_x._0;
    return _44_$retval;
}

int main(void) {
  printf("%ld",_44_main());
  return 0;
}
