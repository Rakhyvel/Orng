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
int64_t _2_main(void);

/* Function definitions */
int64_t _2_main(void) {
    int64_t _2_t2;
    struct0 _3_x;
    int64_t _2_$retval;
    _2_t2 = 125;
    _3_x = (struct0) {.tag=1, ._1=_2_t2};
    _2_$retval = _3_x._1;
    return _2_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
