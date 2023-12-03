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
int64_t _262_main(void);

/* Function definitions */
int64_t _262_main(void) {
    int64_t _262_t0;
    struct0 _263_x;
    int64_t _262_$retval;
    _262_t0 = 139;
    _263_x = (struct0) {.tag=0, ._0=_262_t0};
    _262_$retval = _263_x._0;
    return _262_$retval;
}

int main(void) {
  printf("%ld",_262_main());
  return 0;
}
