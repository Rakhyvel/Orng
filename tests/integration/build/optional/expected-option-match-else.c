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
int64_t _778_main(void);

/* Function definitions */
int64_t _778_main(void) {
    int64_t _778_t10;
    struct0 _779_x;
    int64_t _778_$retval;
    _778_t10 = 128;
    _779_x = (struct0) {.tag=1, ._1=_778_t10};
    _778_$retval = _779_x._1;
    return _778_$retval;
}

int main(void) {
  printf("%ld",_778_main());
  return 0;
}
