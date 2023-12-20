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
        int8_t _0;
    };
} struct0;

/* Function forward definitions */
int64_t _273_main(void);

/* Function definitions */
int64_t _273_main(void){
    int8_t _273_t0;
    struct0 _274_a;
    int64_t _273_$retval;
    _273_t0 = 0;
    _274_a = (struct0) {.tag=0, ._0=_273_t0};
    (void)_274_a;
    _273_$retval = 258;
    return _273_$retval;
}

int main(void) {
  printf("%ld",_273_main());
  return 0;
}
