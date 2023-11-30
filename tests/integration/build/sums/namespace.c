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
int64_t _1407_main(void);

/* Function definitions */
int64_t _1407_main(void) {
    int64_t _1407_t0;
    struct0 _1408_x;
    int64_t _1407_$retval;
    _1407_t0 = 104;
    _1408_x = (struct0) {.tag=0, ._0=_1407_t0};
    _1407_$retval = _1408_x._0;
    return _1407_$retval;
}

int main(void) {
  printf("%ld",_1407_main());
  return 0;
}
