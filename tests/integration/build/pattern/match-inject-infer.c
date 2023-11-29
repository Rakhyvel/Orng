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
int64_t _1105_main(void);

/* Function definitions */
int64_t _1105_main(void) {
    int64_t _1105_t1;
    struct0 _1106_x;
    int64_t _1105_$retval;
    _1105_t1 = 172;
    _1106_x = (struct0) {.tag=0, ._0=_1105_t1};
    _1105_$retval = _1106_x._0;
    return _1105_$retval;
}

int main(void) {
  printf("%ld",_1105_main());
  return 0;
}
