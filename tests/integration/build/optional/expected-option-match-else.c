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
int64_t _746_main(void);

/* Function definitions */
int64_t _746_main(void) {
    int64_t _746_t10;
    struct0 _747_x;
    int64_t _746_$retval;
    _746_t10 = 128;
    _747_x = (struct0) {.tag=1, ._1=_746_t10};
    _746_$retval = _747_x._1;
    return _746_$retval;
}

int main(void) {
  printf("%ld",_746_main());
  return 0;
}
