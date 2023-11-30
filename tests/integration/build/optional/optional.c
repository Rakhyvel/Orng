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
int64_t _971_main(void);

/* Function definitions */
int64_t _971_main(void) {
    int64_t _971_t0;
    struct0 _972_x;
    int64_t _971_t3;
    int64_t _971_$retval;
    _971_t0 = 4;
    _972_x = (struct0) {.tag=1, ._1=_971_t0};
    _972_x = (struct0) {.tag=0};
    _971_t3 = 113;
    _972_x = (struct0) {.tag=1, ._1=_971_t3};
    _971_$retval = _972_x._1;
    return _971_$retval;
}

int main(void) {
  printf("%ld",_971_main());
  return 0;
}
