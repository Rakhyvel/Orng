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
int64_t _1195_main(void);

/* Function definitions */
int64_t _1195_main(void){
    int64_t _1195_t1;
    struct struct0 _1196_x;
    int64_t _1195_$retval;
    _1195_t1 = 172;
    _1196_x = (struct struct0) {.tag=0, ._0=_1195_t1};
    _1195_$retval = _1196_x._0;
    return _1195_$retval;
}

int main(void) {
  printf("%ld",_1195_main());
  return 0;
}
