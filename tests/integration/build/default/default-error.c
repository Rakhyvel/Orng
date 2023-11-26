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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _8_main(void);

/* Function definitions */
int64_t _8_main(void) {
    int64_t _8_t0;
    struct0 _9_x;
    int64_t _8_$retval;
    _8_t0 = 139;
    _9_x = (struct0) {.tag=0, ._0=_8_t0};
    _8_$retval = _9_x._0;
    return _8_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}
