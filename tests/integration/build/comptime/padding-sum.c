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
int64_t _358_main(void);

/* Function definitions */
int64_t _358_main(void){
    int8_t _358_t0;
    struct0 _359_a;
    int64_t _358_$retval;
    _358_t0 = 0;
    _359_a = (struct0) {.tag=0, ._0=_358_t0};
    (void)_359_a;
    _358_$retval = 258;
    return _358_$retval;
}

int main(void) {
  printf("%ld",_358_main());
  return 0;
}
