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
int64_t _391_main(void);

/* Function definitions */
int64_t _391_main(void) {
    int64_t _391_t0;
    struct0 _392_x;
    int64_t _391_$retval;
    _391_t0 = 139;
    _392_x = (struct0) {.tag=0, ._0=_391_t0};
    _391_$retval = _392_x._0;
    return _391_$retval;
}

int main(void) {
  printf("%ld",_391_main());
  return 0;
}
