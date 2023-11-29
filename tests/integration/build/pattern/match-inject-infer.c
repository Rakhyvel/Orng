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
int64_t _909_main(void);

/* Function definitions */
int64_t _909_main(void) {
    int64_t _909_t1;
    struct0 _910_x;
    int64_t _909_$retval;
    _909_t1 = 172;
    _910_x = (struct0) {.tag=0, ._0=_909_t1};
    _909_$retval = _910_x._0;
    return _909_$retval;
}

int main(void) {
  printf("%ld",_909_main());
  return 0;
}
