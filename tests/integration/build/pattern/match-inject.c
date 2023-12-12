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
int64_t _919_main(void);

/* Function definitions */
int64_t _919_main(void) {
    int64_t _919_t1;
    struct0 _920_x;
    int64_t _919_$retval;
    _919_t1 = 171;
    _920_x = (struct0) {.tag=0, ._0=_919_t1};
    _919_$retval = _920_x._0;
    return _919_$retval;
}

int main(void) {
  printf("%ld",_919_main());
  return 0;
}
