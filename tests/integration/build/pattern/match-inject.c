/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
        uint32_t _2;
    };
};

/* Function forward definitions */
int64_t _1228_main(void);


/* Function definitions */
int64_t _1228_main(void){
    int64_t _1228_t2;
    struct struct0 _1229_x;
    int64_t _1228_$retval;
    _1228_t2 = 171;
    _1229_x = (struct struct0) {.tag=0, ._0=_1228_t2};
    _1228_$retval = _1229_x._0;
    return _1228_$retval;
}


int main(void) {
  printf("%ld",_1228_main());
  return 0;
}
