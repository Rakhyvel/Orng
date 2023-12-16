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
int64_t _430_main(void);

/* Function definitions */
int64_t _430_main(void){
    int64_t _430_t0;
    struct0 _431_x;
    int64_t _430_$retval;
    _430_t0 = 139;
    _431_x = (struct0) {.tag=0, ._0=_430_t0};
    _430_$retval = _431_x._0;
    return _430_$retval;
}

int main(void) {
  printf("%ld",_430_main());
  return 0;
}
