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
int64_t _951_main(void);

/* Function definitions */
int64_t _951_main(void) {
    int64_t _951_t2;
    struct0 _952_x;
    int64_t _951_$retval;
    _951_t2 = 125;
    _952_x = (struct0) {.tag=1, ._1=_951_t2};
    _951_$retval = _952_x._1;
    return _951_$retval;
}

int main(void) {
  printf("%ld",_951_main());
  return 0;
}
