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
int64_t _711_main(void);

/* Function definitions */
int64_t _711_main(void) {
    int64_t _711_t0;
    struct0 _712_x;
    int64_t _711_t3;
    int64_t _711_$retval;
    _711_t0 = 4;
    _712_x = (struct0) {.tag=1, ._1=_711_t0};
    _712_x = (struct0) {.tag=0};
    _711_t3 = 113;
    _712_x = (struct0) {.tag=1, ._1=_711_t3};
    _711_$retval = _712_x._1;
    return _711_$retval;
}

int main(void) {
  printf("%ld",_711_main());
  return 0;
}
