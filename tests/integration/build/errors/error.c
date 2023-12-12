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
int64_t _328_main(void);

/* Function definitions */
int64_t _328_main(void) {
    int64_t _328_t0;
    struct0 _329_x;
    int64_t _328_$retval;
    _328_t0 = 117;
    _329_x = (struct0) {.tag=1, ._1=_328_t0};
    _328_$retval = _329_x._1;
    return _328_$retval;
}

int main(void) {
  printf("%ld",_328_main());
  return 0;
}
