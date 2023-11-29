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
        uint32_t _0;
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _359_main(void);

/* Function definitions */
int64_t _359_main(void) {
    int64_t _359_t0;
    struct0 _360_x;
    int64_t _359_$retval;
    _359_t0 = 117;
    _360_x = (struct0) {.tag=1, ._1=_359_t0};
    _359_$retval = _360_x._1;
    return _359_$retval;
}

int main(void) {
  printf("%ld",_359_main());
  return 0;
}
