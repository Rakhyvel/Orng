/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
        uint32_t _2;
    };
};

/* Function forward definitions */
int64_t _1200_main(void);

/* Function definitions */
int64_t _1200_main(void){
    int64_t _1200_t1;
    struct struct0 _1201_x;
    int64_t _1200_$retval;
    _1200_t1 = 171;
    _1201_x = (struct struct0) {.tag=0, ._0=_1200_t1};
    _1200_$retval = _1201_x._0;
    return _1200_$retval;
}

int main(void) {
  printf("%ld",_1200_main());
  return 0;
}
