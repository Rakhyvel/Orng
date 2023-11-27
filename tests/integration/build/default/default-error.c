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
int64_t _234_main(void);

/* Function definitions */
int64_t _234_main(void) {
    int64_t _234_t0;
    struct0 _235_x;
    int64_t _234_$retval;
    _234_t0 = 139;
    _235_x = (struct0) {.tag=0, ._0=_234_t0};
    _234_$retval = _235_x._0;
    return _234_$retval;
}

int main(void) {
  printf("%ld",_234_main());
  return 0;
}
