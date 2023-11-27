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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1059_main(void);

/* Function definitions */
int64_t _1059_main(void) {
    int64_t _1059_t0;
    struct0 _1060_x;
    int64_t _1059_$retval;
    _1059_t0 = 211;
    _1060_x = (struct0) {.tag=1, ._1=_1059_t0};
    _1059_$retval = _1060_x._1;
    return _1059_$retval;
}

int main(void) {
  printf("%ld",_1059_main());
  return 0;
}
