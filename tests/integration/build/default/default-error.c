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
int64_t _270_main(void);

/* Function definitions */
int64_t _270_main(void) {
    int64_t _270_t0;
    struct0 _271_x;
    int64_t _270_$retval;
    _270_t0 = 139;
    _271_x = (struct0) {.tag=0, ._0=_270_t0};
    _270_$retval = _271_x._0;
    return _270_$retval;
}

int main(void) {
  printf("%ld",_270_main());
  return 0;
}
