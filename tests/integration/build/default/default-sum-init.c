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
        int64_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _488_main(void);

/* Function definitions */
int64_t _488_main(void){
    int64_t _488_t0;
    struct0 _489_x;
    int64_t _488_$retval;
    _488_t0 = 134;
    _489_x = (struct0) {.tag=0, ._0=_488_t0};
    _488_$retval = _489_x._0;
    return _488_$retval;
}

int main(void) {
  printf("%ld",_488_main());
  return 0;
}
