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
int64_t _975_main(void);

/* Function definitions */
int64_t _975_main(void) {
    int64_t _975_t10;
    struct0 _976_x;
    int64_t _975_$retval;
    _975_t10 = 128;
    _976_x = (struct0) {.tag=1, ._1=_975_t10};
    _975_$retval = _976_x._1;
    return _975_$retval;
}

int main(void) {
  printf("%ld",_975_main());
  return 0;
}
