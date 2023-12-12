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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _289_main(void);

/* Function definitions */
int64_t _289_main(void) {
    int64_t _289_t0;
    struct0 _290_x;
    int64_t _289_$retval;
    _289_t0 = 139;
    _290_x = (struct0) {.tag=0, ._0=_289_t0};
    _289_$retval = _290_x._0;
    return _289_$retval;
}

int main(void) {
  printf("%ld",_289_main());
  return 0;
}
