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
int64_t _439_main(void);

/* Function definitions */
int64_t _439_main(void) {
    int64_t _439_t0;
    struct0 _440_x;
    int64_t _439_$retval;
    _439_t0 = 134;
    _440_x = (struct0) {.tag=0, ._0=_439_t0};
    _439_$retval = _440_x._0;
    return _439_$retval;
}

int main(void) {
  printf("%ld",_439_main());
  return 0;
}
