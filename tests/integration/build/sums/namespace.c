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
int64_t _1008_main(void);

/* Function definitions */
int64_t _1008_main(void) {
    int64_t _1008_t0;
    struct0 _1009_x;
    int64_t _1008_$retval;
    _1008_t0 = 104;
    _1009_x = (struct0) {.tag=0, ._0=_1008_t0};
    _1008_$retval = _1009_x._0;
    return _1008_$retval;
}

int main(void) {
  printf("%ld",_1008_main());
  return 0;
}
