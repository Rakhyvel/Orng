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
    };
};

/* Function forward definitions */
int64_t _345_main(void);


/* Function definitions */
int64_t _345_main(void){
    int64_t _345_t1;
    struct struct0 _345_t2;
    int64_t _345_$retval;
    _345_t1 = 265;
    _345_t2 = (struct struct0) {.tag=0, ._0=_345_t1};
    _345_$retval = _345_t2._0;
    return _345_$retval;
}


int main(void) {
  printf("%ld",_345_main());
  return 0;
}
