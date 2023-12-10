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
int64_t _1101_main(void);

/* Function definitions */
int64_t _1101_main(void) {
    int64_t _1101_t0;
    struct0 _1102_x;
    int64_t _1101_$retval;
    _1101_t0 = 4;
    _1102_x = (struct0) {.tag=0, ._0=_1101_t0};
    _1102_x._0 = 103;
    _1101_$retval = _1102_x._0;
    return _1101_$retval;
}

int main(void) {
  printf("%ld",_1101_main());
  return 0;
}
