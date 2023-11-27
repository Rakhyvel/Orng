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
int64_t _742_main(void);

/* Function definitions */
int64_t _742_main(void) {
    int64_t _742_t0;
    struct0 _743_x;
    int64_t _742_t3;
    int64_t _742_$retval;
    _742_t0 = 4;
    _743_x = (struct0) {.tag=1, ._1=_742_t0};
    _743_x = (struct0) {.tag=0};
    _742_t3 = 113;
    _743_x = (struct0) {.tag=1, ._1=_742_t3};
    _742_$retval = _743_x._1;
    return _742_$retval;
}

int main(void) {
  printf("%ld",_742_main());
  return 0;
}
