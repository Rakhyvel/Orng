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
int64_t _563_main(void);


/* Function definitions */
int64_t _563_main(void){
    int64_t _563_t2;
    struct struct0 _564_x;
    struct struct0* _564_y;
    int64_t _563_t7;
    int64_t _563_$retval;
    _563_t2 = 0;
    _564_x = (struct struct0) {_563_t2, };
    _564_y = &_564_x;
    _563_t7 = 140;
    _563_$retval = $add_int64_t(_563_t7, (*_564_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _563_$retval;
}


int main(void) {
  printf("%ld",_563_main());
  return 0;
}
