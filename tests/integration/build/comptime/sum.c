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
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _37_main(void);

/* Function definitions */
int64_t _37_main(void) {
    int64_t _37_$retval;
    _37_$retval = 237;
    return _37_$retval;
}

int main(void) {
  printf("%ld",_37_main());
  return 0;
}
