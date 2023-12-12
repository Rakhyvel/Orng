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
int64_t _305_main(void);

/* Function definitions */
int64_t _305_main(void) {
    int64_t _305_t0;
    struct0 _306_x;
    int64_t _305_$retval;
    _305_t0 = 134;
    _306_x = (struct0) {.tag=0, ._0=_305_t0};
    _305_$retval = _306_x._0;
    return _305_$retval;
}

int main(void) {
  printf("%ld",_305_main());
  return 0;
}
