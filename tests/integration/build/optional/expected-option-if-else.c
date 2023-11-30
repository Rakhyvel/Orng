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
int64_t _928_main(void);

/* Function definitions */
int64_t _928_main(void) {
    int64_t _928_t2;
    struct0 _929_x;
    int64_t _928_$retval;
    _928_t2 = 125;
    _929_x = (struct0) {.tag=1, ._1=_928_t2};
    _928_$retval = _929_x._1;
    return _928_$retval;
}

int main(void) {
  printf("%ld",_928_main());
  return 0;
}
