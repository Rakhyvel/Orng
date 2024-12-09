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
int64_t _350_main(void);


/* Function definitions */
int64_t _350_main(void){
    int64_t _350_t1;
    struct struct0 _350_t2;
    int64_t _350_$retval;
    _350_t1 = 265;
    _350_t2 = (struct struct0) {.tag=0, ._0=_350_t1};
    _350_$retval = _350_t2._0;
    return _350_$retval;
}


int main(void) {
  printf("%ld",_350_main());
  return 0;
}
