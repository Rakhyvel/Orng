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
int64_t _568_main(void);


/* Function definitions */
int64_t _568_main(void){
    int64_t _568_t2;
    struct struct0 _569_x;
    struct struct0* _569_y;
    int64_t _568_t7;
    int64_t _568_$retval;
    _568_t2 = 0;
    _569_x = (struct struct0) {_568_t2, };
    _569_y = &_569_x;
    _568_t7 = 140;
    _568_$retval = $add_int64_t(_568_t7, (*_569_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _568_$retval;
}


int main(void) {
  printf("%ld",_568_main());
  return 0;
}
