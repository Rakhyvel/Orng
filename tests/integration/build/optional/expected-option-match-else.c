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
int64_t _797_main(void);

/* Function definitions */
int64_t _797_main(void) {
    int64_t _797_t10;
    struct0 _798_x;
    int64_t _797_$retval;
    _797_t10 = 128;
    _798_x = (struct0) {.tag=1, ._1=_797_t10};
    _797_$retval = _798_x._1;
    return _797_$retval;
}

int main(void) {
  printf("%ld",_797_main());
  return 0;
}
