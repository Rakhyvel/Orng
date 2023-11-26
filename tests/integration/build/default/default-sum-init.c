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
int64_t _233_main(void);

/* Function definitions */
int64_t _233_main(void) {
    int64_t _233_t0;
    struct0 _234_x;
    int64_t _233_$retval;
    _233_t0 = 134;
    _234_x = (struct0) {.tag=0, ._0=_233_t0};
    _233_$retval = _234_x._0;
    return _233_$retval;
}

int main(void) {
  printf("%ld",_233_main());
  return 0;
}
