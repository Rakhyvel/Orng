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
int64_t _1433_main(void);

/* Function definitions */
int64_t _1433_main(void) {
    int64_t _1433_t0;
    struct0 _1434_x;
    int64_t _1433_$retval;
    _1433_t0 = 211;
    _1434_x = (struct0) {.tag=1, ._1=_1433_t0};
    _1433_$retval = _1434_x._1;
    return _1433_$retval;
}

int main(void) {
  printf("%ld",_1433_main());
  return 0;
}
