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
int64_t _992_main(void);

/* Function definitions */
int64_t _992_main(void) {
    int64_t _992_t0;
    struct0 _993_x;
    int64_t _992_t3;
    int64_t _992_$retval;
    _992_t0 = 4;
    _993_x = (struct0) {.tag=1, ._1=_992_t0};
    _993_x = (struct0) {.tag=0};
    _992_t3 = 113;
    _993_x = (struct0) {.tag=1, ._1=_992_t3};
    _992_$retval = _993_x._1;
    return _992_$retval;
}

int main(void) {
  printf("%ld",_992_main());
  return 0;
}
