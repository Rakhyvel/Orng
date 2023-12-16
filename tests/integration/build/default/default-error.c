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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _490_main(void);

/* Function definitions */
int64_t _490_main(void){
    int64_t _490_t0;
    struct0 _491_x;
    int64_t _490_$retval;
    _490_t0 = 139;
    _491_x = (struct0) {.tag=0, ._0=_490_t0};
    _490_$retval = _491_x._0;
    return _490_$retval;
}

int main(void) {
  printf("%ld",_490_main());
  return 0;
}
