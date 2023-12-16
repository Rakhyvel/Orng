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
int64_t _503_main(void);

/* Function definitions */
int64_t _503_main(void) {
    int64_t _503_t0;
    struct0 _504_x;
    int64_t _503_$retval;
    _503_t0 = 117;
    _504_x = (struct0) {.tag=1, ._1=_503_t0};
    _503_$retval = _504_x._1;
    return _503_$retval;
}

int main(void) {
  printf("%ld",_503_main());
  return 0;
}
