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
int64_t _441_main(void);

/* Function definitions */
int64_t _441_main(void) {
    int64_t _441_t0;
    struct0 _442_x;
    int64_t _441_$retval;
    _441_t0 = 134;
    _442_x = (struct0) {.tag=0, ._0=_441_t0};
    _441_$retval = _442_x._0;
    return _441_$retval;
}

int main(void) {
  printf("%ld",_441_main());
  return 0;
}
