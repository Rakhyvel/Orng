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
int64_t _393_main(void);

/* Function definitions */
int64_t _393_main(void) {
    int64_t _393_t0;
    struct0 _394_x;
    int64_t _393_$retval;
    _393_t0 = 139;
    _394_x = (struct0) {.tag=0, ._0=_393_t0};
    _393_$retval = _394_x._0;
    return _393_$retval;
}

int main(void) {
  printf("%ld",_393_main());
  return 0;
}
