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
int64_t _1077_main(void);

/* Function definitions */
int64_t _1077_main(void) {
    int64_t _1077_t0;
    struct0 _1078_x;
    int64_t _1077_$retval;
    _1077_t0 = 102;
    _1078_x = (struct0) {.tag=0, ._0=_1077_t0};
    _1077_$retval = _1078_x._0;
    return _1077_$retval;
}

int main(void) {
  printf("%ld",_1077_main());
  return 0;
}
