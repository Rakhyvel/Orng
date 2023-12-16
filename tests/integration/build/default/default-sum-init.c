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
int64_t _469_main(void);

/* Function definitions */
int64_t _469_main(void) {
    int64_t _469_t0;
    struct0 _470_x;
    int64_t _469_$retval;
    _469_t0 = 134;
    _470_x = (struct0) {.tag=0, ._0=_469_t0};
    _469_$retval = _470_x._0;
    return _469_$retval;
}

int main(void) {
  printf("%ld",_469_main());
  return 0;
}
