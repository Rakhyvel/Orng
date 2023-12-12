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
        uint32_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _347_main(void);

/* Function definitions */
int64_t _347_main(void) {
    int64_t _347_t0;
    struct0 _348_x;
    int64_t _347_$retval;
    _347_t0 = 117;
    _348_x = (struct0) {.tag=1, ._1=_347_t0};
    _347_$retval = _348_x._1;
    return _347_$retval;
}

int main(void) {
  printf("%ld",_347_main());
  return 0;
}
