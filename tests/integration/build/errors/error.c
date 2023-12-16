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
int64_t _522_main(void);

/* Function definitions */
int64_t _522_main(void){
    int64_t _522_t0;
    struct0 _523_x;
    int64_t _522_$retval;
    _522_t0 = 117;
    _523_x = (struct0) {.tag=1, ._1=_522_t0};
    _522_$retval = _523_x._1;
    return _522_$retval;
}

int main(void) {
  printf("%ld",_522_main());
  return 0;
}
