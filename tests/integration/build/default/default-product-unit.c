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
int64_t _564_main(void);


/* Function definitions */
int64_t _564_main(void){
    int64_t _564_t2;
    struct struct0 _565_x;
    struct struct0* _565_y;
    int64_t _564_t5;
    int64_t _564_$retval;
    _564_t2 = 0;
    _565_x = (struct struct0) {_564_t2, };
    _565_y = &_565_x;
    _564_t5 = 140;
    _564_$retval = $add_int64_t(_564_t5, (*_565_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _564_$retval;
}


int main(void) {
  printf("%ld",_564_main());
  return 0;
}
