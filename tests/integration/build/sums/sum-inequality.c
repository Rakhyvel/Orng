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
int64_t _1145_main(void);

/* Function definitions */
int64_t _1145_main(void) {
    int64_t _1145_t0;
    struct0 _1146_x;
    int64_t _1145_$retval;
    _1145_t0 = 211;
    _1146_x = (struct0) {.tag=1, ._1=_1145_t0};
    _1145_$retval = _1146_x._1;
    return _1145_$retval;
}

int main(void) {
  printf("%ld",_1145_main());
  return 0;
}
