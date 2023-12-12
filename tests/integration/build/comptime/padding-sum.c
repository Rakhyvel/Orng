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
int64_t _145_main(void);

/* Function definitions */
int64_t _145_main(void) {
    int8_t _145_t0;
    struct0 _146_a;
    int64_t _145_$retval;
    _145_t0 = 0;
    _146_a = (struct0) {.tag=0, ._0=_145_t0};
    (void)_146_a;
    _145_$retval = 258;
    return _145_$retval;
}

int main(void) {
  printf("%ld",_145_main());
  return 0;
}
