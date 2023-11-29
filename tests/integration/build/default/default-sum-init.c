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
    };
} struct0;

/* Function forward definitions */
int64_t _335_main(void);

/* Function definitions */
int64_t _335_main(void) {
    int64_t _335_t0;
    struct0 _336_x;
    int64_t _335_$retval;
    _335_t0 = 134;
    _336_x = (struct0) {.tag=0, ._0=_335_t0};
    _335_$retval = _336_x._0;
    return _335_$retval;
}

int main(void) {
  printf("%ld",_335_main());
  return 0;
}
