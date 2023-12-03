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
int64_t _1053_main(void);

/* Function definitions */
int64_t _1053_main(void) {
    int64_t _1053_t0;
    struct0 _1054_x;
    int64_t _1053_$retval;
    _1053_t0 = 102;
    _1054_x = (struct0) {.tag=0, ._0=_1053_t0};
    _1053_$retval = _1054_x._0;
    return _1053_$retval;
}

int main(void) {
  printf("%ld",_1053_main());
  return 0;
}
