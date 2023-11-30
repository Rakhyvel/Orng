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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1438_main(void);

/* Function definitions */
int64_t _1438_main(void) {
    int64_t _1438_t0;
    struct0 _1439_x;
    int64_t _1438_$retval;
    _1438_t0 = 211;
    _1439_x = (struct0) {.tag=1, ._1=_1438_t0};
    _1438_$retval = _1439_x._1;
    return _1438_$retval;
}

int main(void) {
  printf("%ld",_1438_main());
  return 0;
}
