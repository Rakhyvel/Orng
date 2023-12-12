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
int64_t _809_main(void);

/* Function definitions */
int64_t _809_main(void) {
    int64_t _809_t0;
    struct0 _810_x;
    int64_t _809_t4;
    int64_t _809_$retval;
    _809_t0 = 4;
    _810_x = (struct0) {.tag=1, ._1=_809_t0};
    _810_x = (struct0) {.tag=0};
    _809_t4 = 113;
    _810_x = (struct0) {.tag=1, ._1=_809_t4};
    _809_$retval = _810_x._1;
    return _809_$retval;
}

int main(void) {
  printf("%ld",_809_main());
  return 0;
}
