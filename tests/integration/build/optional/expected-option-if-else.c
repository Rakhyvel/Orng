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
int64_t _1126_main(void);

/* Function definitions */
int64_t _1126_main(void){
    int64_t _1126_t0;
    struct0 _1127_x;
    int64_t _1126_$retval;
    _1126_t0 = 125;
    _1127_x = (struct0) {.tag=1, ._1=_1126_t0};
    _1126_$retval = _1127_x._1;
    return _1126_$retval;
}

int main(void) {
  printf("%ld",_1126_main());
  return 0;
}
