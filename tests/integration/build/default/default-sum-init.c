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
int64_t _297_main(void);

/* Function definitions */
int64_t _297_main(void) {
    int64_t _297_t0;
    struct0 _298_x;
    int64_t _297_$retval;
    _297_t0 = 134;
    _298_x = (struct0) {.tag=0, ._0=_297_t0};
    _297_$retval = _298_x._0;
    return _297_$retval;
}

int main(void) {
  printf("%ld",_297_main());
  return 0;
}
