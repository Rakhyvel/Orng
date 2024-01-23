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
int64_t _537_main(void);


/* Function definitions */
int64_t _537_main(void){
    int64_t _537_t2;
    struct struct0 _538_x;
    struct struct0* _538_y;
    int64_t _537_t5;
    int64_t _537_$retval;
    _537_t2 = 0;
    _538_x = (struct struct0) {_537_t2, };
    _538_y = &_538_x;
    _537_t5 = 140;
    _537_$retval = $add_int64_t(_537_t5, (*_538_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _537_$retval;
}


int main(void) {
  printf("%ld",_537_main());
  return 0;
}
