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
int64_t _263_main(void);


/* Function definitions */
int64_t _263_main(void){
    int64_t _263_t1;
    struct struct0 _263_t2;
    int64_t _263_$retval;
    _263_t1 = 265;
    _263_t2 = (struct struct0) {.tag=0, ._0=_263_t1};
    _263_$retval = _263_t2._0;
    return _263_$retval;
}


int main(void) {
  printf("%ld",_263_main());
  return 0;
}
