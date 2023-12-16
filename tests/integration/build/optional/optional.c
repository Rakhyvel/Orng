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
int64_t _1009_main(void);

/* Function definitions */
int64_t _1009_main(void) {
    int64_t _1009_t0;
    struct0 _1010_x;
    int64_t _1009_t4;
    int64_t _1009_$retval;
    _1009_t0 = 4;
    _1010_x = (struct0) {.tag=1, ._1=_1009_t0};
    _1010_x = (struct0) {.tag=0};
    _1009_t4 = 113;
    _1010_x = (struct0) {.tag=1, ._1=_1009_t4};
    _1009_$retval = _1010_x._1;
    return _1009_$retval;
}

int main(void) {
  printf("%ld",_1009_main());
  return 0;
}
