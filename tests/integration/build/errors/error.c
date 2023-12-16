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
int64_t _582_main(void);

/* Function definitions */
int64_t _582_main(void){
    int64_t _582_t0;
    struct0 _583_x;
    int64_t _582_$retval;
    _582_t0 = 117;
    _583_x = (struct0) {.tag=1, ._1=_582_t0};
    _582_$retval = _583_x._1;
    return _582_$retval;
}

int main(void) {
  printf("%ld",_582_main());
  return 0;
}
