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
int64_t _1218_main(void);

/* Function definitions */
int64_t _1218_main(void){
    int64_t _1218_t1;
    struct struct0 _1219_x;
    int64_t _1218_$retval;
    _1218_t1 = 171;
    _1219_x = (struct struct0) {.tag=0, ._0=_1218_t1};
    _1218_$retval = _1219_x._0;
    return _1218_$retval;
}

int main(void) {
  printf("%ld",_1218_main());
  return 0;
}
