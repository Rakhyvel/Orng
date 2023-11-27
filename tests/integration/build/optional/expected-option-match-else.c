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
int64_t _715_main(void);

/* Function definitions */
int64_t _715_main(void) {
    int64_t _715_t10;
    struct0 _716_x;
    int64_t _715_$retval;
    _715_t10 = 128;
    _716_x = (struct0) {.tag=1, ._1=_715_t10};
    _715_$retval = _716_x._1;
    return _715_$retval;
}

int main(void) {
  printf("%ld",_715_main());
  return 0;
}
