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
int64_t _411_main(void);

/* Function definitions */
int64_t _411_main(void) {
    int64_t _411_t0;
    struct0 _412_x;
    int64_t _411_$retval;
    _411_t0 = 139;
    _412_x = (struct0) {.tag=0, ._0=_411_t0};
    _411_$retval = _412_x._0;
    return _411_$retval;
}

int main(void) {
  printf("%ld",_411_main());
  return 0;
}
