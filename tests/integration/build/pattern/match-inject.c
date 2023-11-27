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
        uint32_t _2;
    };
} struct0;

/* Function forward definitions */
int64_t _833_main(void);

/* Function definitions */
int64_t _833_main(void) {
    int64_t _833_t0;
    struct0 _834_x;
    int64_t _833_$retval;
    _833_t0 = 171;
    _834_x = (struct0) {.tag=0, ._0=_833_t0};
    _833_$retval = _834_x._0;
    return _833_$retval;
}

int main(void) {
  printf("%ld",_833_main());
  return 0;
}
