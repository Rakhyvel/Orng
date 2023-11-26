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
int64_t _203_main(void);

/* Function definitions */
int64_t _203_main(void) {
    int64_t _203_t0;
    struct0 _204_x;
    int64_t _203_$retval;
    _203_t0 = 139;
    _204_x = (struct0) {.tag=0, ._0=_203_t0};
    _203_$retval = _204_x._0;
    return _203_$retval;
}

int main(void) {
  printf("%ld",_203_main());
  return 0;
}
