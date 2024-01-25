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
    int64_t _0;
    double _1;
};

/* Function forward definitions */
int64_t _559_main(void);


/* Function definitions */
int64_t _559_main(void){
    int64_t _559_t1;
    double _559_t2;
    struct struct0 _560_x;
    int64_t _559_$retval;
    _559_t1 = 137;
    _559_t2 = 0.0e+00;
    _560_x = (struct struct0) {_559_t1, _559_t2};
    _559_$retval = _560_x._0;
    return _559_$retval;
}


int main(void) {
  printf("%ld",_559_main());
  return 0;
}
