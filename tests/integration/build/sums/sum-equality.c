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
int64_t _1104_main(void);

/* Function definitions */
int64_t _1104_main(void) {
    int64_t _1104_t0;
    struct0 _1105_x;
    int64_t _1104_$retval;
    _1104_t0 = 210;
    _1105_x = (struct0) {.tag=1, ._1=_1104_t0};
    _1104_$retval = _1105_x._1;
    return _1104_$retval;
}

int main(void) {
  printf("%ld",_1104_main());
  return 0;
}
