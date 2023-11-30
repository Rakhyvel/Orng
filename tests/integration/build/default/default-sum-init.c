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
int64_t _418_main(void);

/* Function definitions */
int64_t _418_main(void) {
    int64_t _418_t0;
    struct0 _419_x;
    int64_t _418_$retval;
    _418_t0 = 134;
    _419_x = (struct0) {.tag=0, ._0=_418_t0};
    _418_$retval = _419_x._0;
    return _418_$retval;
}

int main(void) {
  printf("%ld",_418_main());
  return 0;
}
