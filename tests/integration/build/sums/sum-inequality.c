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
int64_t _1461_main(void);

/* Function definitions */
int64_t _1461_main(void) {
    int64_t _1461_t0;
    struct0 _1462_x;
    int64_t _1461_$retval;
    _1461_t0 = 211;
    _1462_x = (struct0) {.tag=1, ._1=_1461_t0};
    _1461_$retval = _1462_x._1;
    return _1461_$retval;
}

int main(void) {
  printf("%ld",_1461_main());
  return 0;
}
