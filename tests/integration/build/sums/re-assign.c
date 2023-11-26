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
int64_t _1011_main(void);

/* Function definitions */
int64_t _1011_main(void) {
    int64_t _1011_t0;
    struct0 _1012_x;
    int64_t _1011_$retval;
    _1011_t0 = 4;
    _1012_x = (struct0) {.tag=0, ._0=_1011_t0};
    _1012_x._0 = 103;
    _1011_$retval = _1012_x._0;
    return _1011_$retval;
}

int main(void) {
  printf("%ld",_1011_main());
  return 0;
}
