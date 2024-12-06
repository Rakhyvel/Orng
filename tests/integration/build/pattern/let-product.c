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
    int64_t _1;
};

/* Function forward definitions */
int64_t _1259_main(void);


/* Function definitions */
int64_t _1259_main(void){
    int64_t _1259_t1;
    int64_t _1259_t2;
    struct struct0 _1259_t0;
    int64_t _1260_x;
    int64_t _1260_y;
    int64_t _1259_t4;
    int64_t _1259_t5;
    int64_t _1259_$retval;
    _1259_t1 = 5;
    _1259_t2 = 30;
    _1259_t0 = (struct struct0) {_1259_t1, _1259_t2};
    _1260_x = _1259_t0._0;
    _1260_y = _1259_t0._1;
    _1259_t4 = $mult_int64_t(_1260_x, _1260_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1259_t5 = 1;
    _1259_$retval = $add_int64_t(_1259_t4, _1259_t5, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1259_$retval;
}


int main(void) {
  printf("%ld",_1259_main());
  return 0;
}
