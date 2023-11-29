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
int64_t _40_main(void);

/* Function definitions */
int64_t _40_main(void) {
    int64_t _40_t0;
    struct0 _41_x;
    int64_t _40_t3;
    int64_t _40_$retval;
    _40_t0 = 4;
    _41_x = (struct0) {.tag=1, ._1=_40_t0};
    _41_x = (struct0) {.tag=0};
    _40_t3 = 113;
    _41_x = (struct0) {.tag=1, ._1=_40_t3};
    _40_$retval = _41_x._1;
    return _40_$retval;
}

int main(void) {
  printf("%ld",_40_main());
  return 0;
}
