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
        uint32_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _474_main(void);

/* Function definitions */
int64_t _474_main(void) {
    int64_t _474_t0;
    struct0 _475_x;
    int64_t _474_$retval;
    _474_t0 = 117;
    _475_x = (struct0) {.tag=1, ._1=_474_t0};
    _474_$retval = _475_x._1;
    return _474_$retval;
}

int main(void) {
  printf("%ld",_474_main());
  return 0;
}
