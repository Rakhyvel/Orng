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
int64_t _248_main(void);

/* Function definitions */
int64_t _248_main(void) {
    int8_t _248_t0;
    struct0 _249_a;
    int64_t _248_$retval;
    _248_t0 = 0;
    _249_a = (struct0) {.tag=0, ._0=_248_t0};
    (void)_249_a;
    _248_$retval = 258;
    return _248_$retval;
}

int main(void) {
  printf("%ld",_248_main());
  return 0;
}
