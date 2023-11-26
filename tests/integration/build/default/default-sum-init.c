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
int64_t _38_main(void);

/* Function definitions */
int64_t _38_main(void) {
    int64_t _38_t0;
    struct0 _39_x;
    int64_t _38_$retval;
    _38_t0 = 134;
    _39_x = (struct0) {.tag=0, ._0=_38_t0};
    _38_$retval = _39_x._0;
    return _38_$retval;
}

int main(void) {
  printf("%ld",_38_main());
  return 0;
}
