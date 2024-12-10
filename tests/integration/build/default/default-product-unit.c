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
int64_t _583_main(void);


/* Function definitions */
int64_t _583_main(void){
    int64_t _583_t2;
    struct struct0 _584_x;
    struct struct0* _584_y;
    int64_t _583_t7;
    int64_t _583_$retval;
    _583_t2 = 0;
    _584_x = (struct struct0) {_583_t2, };
    _584_y = &_584_x;
    _583_t7 = 140;
    _583_$retval = $add_int64_t(_583_t7, (*_584_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _583_$retval;
}


int main(void) {
  printf("%ld",_583_main());
  return 0;
}
