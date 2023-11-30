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
int64_t _370_main(void);

/* Function definitions */
int64_t _370_main(void) {
    int64_t _370_t0;
    struct0 _371_x;
    int64_t _370_$retval;
    _370_t0 = 139;
    _371_x = (struct0) {.tag=0, ._0=_370_t0};
    _370_$retval = _371_x._0;
    return _370_$retval;
}

int main(void) {
  printf("%ld",_370_main());
  return 0;
}
