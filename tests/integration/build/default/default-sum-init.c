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
int64_t _324_main(void);

/* Function definitions */
int64_t _324_main(void) {
    int64_t _324_t0;
    struct0 _325_x;
    int64_t _324_$retval;
    _324_t0 = 134;
    _325_x = (struct0) {.tag=0, ._0=_324_t0};
    _324_$retval = _325_x._0;
    return _324_$retval;
}

int main(void) {
  printf("%ld",_324_main());
  return 0;
}
