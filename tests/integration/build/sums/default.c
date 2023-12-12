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
int64_t _1085_main(void);

/* Function definitions */
int64_t _1085_main(void) {
    int64_t _1085_t0;
    struct0 _1086_x;
    int64_t _1085_$retval;
    _1085_t0 = 102;
    _1086_x = (struct0) {.tag=0, ._0=_1085_t0};
    _1085_$retval = _1086_x._0;
    return _1085_$retval;
}

int main(void) {
  printf("%ld",_1085_main());
  return 0;
}
