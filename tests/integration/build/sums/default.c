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
int64_t _7_main(void);

/* Function definitions */
int64_t _7_main(void) {
    int64_t _7_t0;
    struct0 _8_x;
    int64_t _7_$retval;
    _7_t0 = 102;
    _8_x = (struct0) {.tag=0, ._0=_7_t0};
    _7_$retval = _8_x._0;
    return _7_$retval;
}

int main(void) {
  printf("%ld",_7_main());
  return 0;
}
