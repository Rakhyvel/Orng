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
int64_t _259_main(void);

/* Function definitions */
int64_t _259_main(void){
    int8_t _259_t0;
    struct0 _260_a;
    int64_t _259_$retval;
    _259_t0 = 0;
    _260_a = (struct0) {.tag=0, ._0=_259_t0};
    (void)_260_a;
    _259_$retval = 258;
    return _259_$retval;
}

int main(void) {
  printf("%ld",_259_main());
  return 0;
}
