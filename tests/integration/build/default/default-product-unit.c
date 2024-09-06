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
    int64_t _1;
};

/* Function forward definitions */
int64_t _571_main(void);


/* Function definitions */
int64_t _571_main(void){
    int64_t _571_t2;
    struct struct0 _572_x;
    struct struct0* _572_y;
    int64_t _571_t7;
    int64_t _571_$retval;
    _571_t2 = 0;
    _572_x = (struct struct0) {_571_t2, };
    _572_y = &_572_x;
    _571_t7 = 140;
    _571_$retval = $add_int64_t(_571_t7, (*_572_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _571_$retval;
}


int main(void) {
  printf("%ld",_571_main());
  return 0;
}
