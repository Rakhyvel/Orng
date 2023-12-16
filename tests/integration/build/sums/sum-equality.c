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
int64_t _1437_main(void);

/* Function definitions */
int64_t _1437_main(void){
    int64_t _1437_t0;
    struct0 _1438_x;
    int64_t _1437_$retval;
    _1437_t0 = 210;
    _1438_x = (struct0) {.tag=1, ._1=_1437_t0};
    _1437_$retval = _1438_x._1;
    return _1437_$retval;
}

int main(void) {
  printf("%ld",_1437_main());
  return 0;
}
