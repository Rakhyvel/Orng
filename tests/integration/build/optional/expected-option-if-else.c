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
int64_t _962_main(void);

/* Function definitions */
int64_t _962_main(void) {
    int64_t _962_t2;
    struct0 _963_x;
    int64_t _962_$retval;
    _962_t2 = 125;
    _963_x = (struct0) {.tag=1, ._1=_962_t2};
    _962_$retval = _963_x._1;
    return _962_$retval;
}

int main(void) {
  printf("%ld",_962_main());
  return 0;
}
