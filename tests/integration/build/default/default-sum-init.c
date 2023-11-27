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
int64_t _264_main(void);

/* Function definitions */
int64_t _264_main(void) {
    int64_t _264_t0;
    struct0 _265_x;
    int64_t _264_$retval;
    _264_t0 = 134;
    _265_x = (struct0) {.tag=0, ._0=_264_t0};
    _264_$retval = _265_x._0;
    return _264_$retval;
}

int main(void) {
  printf("%ld",_264_main());
  return 0;
}
