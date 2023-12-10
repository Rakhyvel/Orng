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
int64_t _770_main(void);

/* Function definitions */
int64_t _770_main(void) {
    int64_t _770_t10;
    struct0 _771_x;
    int64_t _770_$retval;
    _770_t10 = 128;
    _771_x = (struct0) {.tag=1, ._1=_770_t10};
    _770_$retval = _771_x._1;
    return _770_$retval;
}

int main(void) {
  printf("%ld",_770_main());
  return 0;
}
