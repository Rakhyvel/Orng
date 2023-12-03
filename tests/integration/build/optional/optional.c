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
int64_t _777_main(void);

/* Function definitions */
int64_t _777_main(void) {
    int64_t _777_t0;
    struct0 _778_x;
    int64_t _777_t4;
    int64_t _777_$retval;
    _777_t0 = 4;
    _778_x = (struct0) {.tag=1, ._1=_777_t0};
    _778_x = (struct0) {.tag=0};
    _777_t4 = 113;
    _778_x = (struct0) {.tag=1, ._1=_777_t4};
    _777_$retval = _778_x._1;
    return _777_$retval;
}

int main(void) {
  printf("%ld",_777_main());
  return 0;
}
