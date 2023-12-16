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
int64_t _511_main(void);

/* Function definitions */
int64_t _511_main(void){
    int64_t _511_t0;
    struct0 _512_x;
    int64_t _511_$retval;
    _511_t0 = 117;
    _512_x = (struct0) {.tag=1, ._1=_511_t0};
    _511_$retval = _512_x._1;
    return _511_$retval;
}

int main(void) {
  printf("%ld",_511_main());
  return 0;
}
