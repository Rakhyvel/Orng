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
int64_t _1417_main(void);

/* Function definitions */
int64_t _1417_main(void) {
    int64_t _1417_t0;
    struct0 _1418_x;
    int64_t _1417_$retval;
    _1417_t0 = 101;
    _1418_x = (struct0) {.tag=0, ._0=_1417_t0};
    _1417_$retval = _1418_x._0;
    return _1417_$retval;
}

int main(void) {
  printf("%ld",_1417_main());
  return 0;
}
