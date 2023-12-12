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
int64_t _62_main(void);

/* Function definitions */
int64_t _62_main(void) {
    int8_t _62_t0;
    struct0 _63_a;
    int64_t _62_$retval;
    _62_t0 = 0;
    _63_a = (struct0) {.tag=0, ._0=_62_t0};
    (void)_63_a;
    _62_$retval = 258;
    return _62_$retval;
}

int main(void) {
  printf("%ld",_62_main());
  return 0;
}
