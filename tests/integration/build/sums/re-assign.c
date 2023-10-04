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
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    int64_t _1_$retval;
    _2_x = (struct0) {.tag=0, ._0=4};
    _2_x._0 = 103;
    _1_$retval = _2_x._0;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
