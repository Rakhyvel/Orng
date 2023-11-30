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
int64_t _994_main(void);

/* Function definitions */
int64_t _994_main(void) {
    int64_t _994_t0;
    struct0 _995_x;
    int64_t _994_t3;
    int64_t _994_$retval;
    _994_t0 = 4;
    _995_x = (struct0) {.tag=1, ._1=_994_t0};
    _995_x = (struct0) {.tag=0};
    _994_t3 = 113;
    _995_x = (struct0) {.tag=1, ._1=_994_t3};
    _994_$retval = _995_x._1;
    return _994_$retval;
}

int main(void) {
  printf("%ld",_994_main());
  return 0;
}
