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
int64_t _1147_main(void);

/* Function definitions */
int64_t _1147_main(void) {
    int64_t _1147_t0;
    struct0 _1148_x;
    int64_t _1147_$retval;
    _1147_t0 = 104;
    _1148_x = (struct0) {.tag=0, ._0=_1147_t0};
    _1147_$retval = _1148_x._0;
    return _1147_$retval;
}

int main(void) {
  printf("%ld",_1147_main());
  return 0;
}
