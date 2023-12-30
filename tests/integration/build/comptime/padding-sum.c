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
int64_t _274_main(void);

/* Function definitions */
int64_t _274_main(void){
    int8_t _274_t0;
    struct0 _275_a;
    int64_t _274_$retval;
    _274_t0 = 0;
    _275_a = (struct0) {.tag=0, ._0=_274_t0};
    (void)_275_a;
    _274_$retval = 258;
    return _274_$retval;
}

int main(void) {
  printf("%ld",_274_main());
  return 0;
}
