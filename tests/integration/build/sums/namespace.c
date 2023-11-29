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
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _36_main(void);

/* Function definitions */
int64_t _36_main(void) {
    int64_t _36_t0;
    struct0 _37_x;
    int64_t _36_$retval;
    _36_t0 = 104;
    _37_x = (struct0) {.tag=0, ._0=_36_t0};
    _36_$retval = _37_x._0;
    return _36_$retval;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
