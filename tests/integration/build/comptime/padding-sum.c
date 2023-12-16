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
int64_t _117_main(void);

/* Function definitions */
int64_t _117_main(void){
    int8_t _117_t0;
    struct0 _118_a;
    int64_t _117_$retval;
    _117_t0 = 0;
    _118_a = (struct0) {.tag=0, ._0=_117_t0};
    (void)_118_a;
    _117_$retval = 258;
    return _117_$retval;
}

int main(void) {
  printf("%ld",_117_main());
  return 0;
}
