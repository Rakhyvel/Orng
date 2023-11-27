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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _3_main(void);

/* Function definitions */
int64_t _3_main(void) {
    int64_t _3_t0;
    struct0 _4_f;
    int64_t _3_$retval;
    _3_t0 = 244;
    _4_f = (struct0) {.tag=0, ._0=_3_t0};
    _3_$retval = _4_f._0;
    return _3_$retval;
}

int main(void) {
  printf("%ld",_3_main());
  return 0;
}
