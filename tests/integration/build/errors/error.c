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
int64_t _472_main(void);

/* Function definitions */
int64_t _472_main(void) {
    int64_t _472_t0;
    struct0 _473_x;
    int64_t _472_$retval;
    _472_t0 = 117;
    _473_x = (struct0) {.tag=1, ._1=_472_t0};
    _472_$retval = _473_x._1;
    return _472_$retval;
}

int main(void) {
  printf("%ld",_472_main());
  return 0;
}
