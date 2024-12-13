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
int64_t _585_main(void);


/* Function definitions */
int64_t _585_main(void){
    int64_t _585_t2;
    struct struct0 _586_x;
    struct struct0* _586_y;
    int64_t _585_t7;
    int64_t _585_$retval;
    _585_t2 = 0;
    _586_x = (struct struct0) {_585_t2, };
    _586_y = &_586_x;
    _585_t7 = 140;
    _585_$retval = $add_int64_t(_585_t7, (*_586_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _585_$retval;
}


int main(void) {
  printf("%ld",_585_main());
  return 0;
}
