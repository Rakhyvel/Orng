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
int64_t _704_main(void);

/* Function definitions */
int64_t _704_main(void) {
    int64_t _704_t2;
    struct0 _705_x;
    int64_t _704_$retval;
    _704_t2 = 125;
    _705_x = (struct0) {.tag=1, ._1=_704_t2};
    _704_$retval = _705_x._1;
    return _704_$retval;
}

int main(void) {
  printf("%ld",_704_main());
  return 0;
}
