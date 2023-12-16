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
int64_t _1512_main(void);

/* Function definitions */
int64_t _1512_main(void){
    int64_t _1512_t0;
    struct0 _1513_x;
    int64_t _1512_$retval;
    _1512_t0 = 211;
    _1513_x = (struct0) {.tag=1, ._1=_1512_t0};
    _1512_$retval = _1513_x._1;
    return _1512_$retval;
}

int main(void) {
  printf("%ld",_1512_main());
  return 0;
}
