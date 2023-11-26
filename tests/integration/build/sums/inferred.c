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
int64_t _1005_main(void);

/* Function definitions */
int64_t _1005_main(void) {
    int64_t _1005_t0;
    struct0 _1006_x;
    int64_t _1005_$retval;
    _1005_t0 = 101;
    _1006_x = (struct0) {.tag=0, ._0=_1005_t0};
    _1005_$retval = _1006_x._0;
    return _1005_$retval;
}

int main(void) {
  printf("%ld",_1005_main());
  return 0;
}
