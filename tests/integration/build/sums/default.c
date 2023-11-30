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
int64_t _1366_main(void);

/* Function definitions */
int64_t _1366_main(void) {
    int64_t _1366_t0;
    struct0 _1367_x;
    int64_t _1366_$retval;
    _1366_t0 = 102;
    _1367_x = (struct0) {.tag=0, ._0=_1366_t0};
    _1366_$retval = _1367_x._0;
    return _1366_$retval;
}

int main(void) {
  printf("%ld",_1366_main());
  return 0;
}
