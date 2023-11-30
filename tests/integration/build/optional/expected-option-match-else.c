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
int64_t _964_main(void);

/* Function definitions */
int64_t _964_main(void) {
    int64_t _964_t10;
    struct0 _965_x;
    int64_t _964_$retval;
    _964_t10 = 128;
    _965_x = (struct0) {.tag=1, ._1=_964_t10};
    _964_$retval = _965_x._1;
    return _964_$retval;
}

int main(void) {
  printf("%ld",_964_main());
  return 0;
}
