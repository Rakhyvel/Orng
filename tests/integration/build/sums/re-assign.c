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
int64_t _1442_main(void);

/* Function definitions */
int64_t _1442_main(void) {
    int64_t _1442_t0;
    struct0 _1443_x;
    int64_t _1442_$retval;
    _1442_t0 = 4;
    _1443_x = (struct0) {.tag=0, ._0=_1442_t0};
    _1443_x._0 = 103;
    _1442_$retval = _1443_x._0;
    return _1442_$retval;
}

int main(void) {
  printf("%ld",_1442_main());
  return 0;
}
