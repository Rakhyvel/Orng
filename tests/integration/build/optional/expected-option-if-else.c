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
int64_t _759_main(void);

/* Function definitions */
int64_t _759_main(void) {
    int64_t _759_t2;
    struct0 _760_x;
    int64_t _759_$retval;
    _759_t2 = 125;
    _760_x = (struct0) {.tag=1, ._1=_759_t2};
    _759_$retval = _760_x._1;
    return _759_$retval;
}

int main(void) {
  printf("%ld",_759_main());
  return 0;
}
