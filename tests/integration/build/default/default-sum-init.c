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
int64_t _477_main(void);

/* Function definitions */
int64_t _477_main(void){
    int64_t _477_t0;
    struct0 _478_x;
    int64_t _477_$retval;
    _477_t0 = 134;
    _478_x = (struct0) {.tag=0, ._0=_477_t0};
    _477_$retval = _478_x._0;
    return _477_$retval;
}

int main(void) {
  printf("%ld",_477_main());
  return 0;
}
