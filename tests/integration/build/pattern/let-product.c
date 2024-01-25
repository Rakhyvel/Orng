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
int64_t _1212_main(void);


/* Function definitions */
int64_t _1212_main(void){
    int64_t _1212_t1;
    int64_t _1212_t2;
    struct struct0 _1212_t0;
    int64_t _1213_x;
    int64_t _1213_y;
    int64_t _1212_t3;
    int64_t _1212_t4;
    int64_t _1212_$retval;
    _1212_t1 = 5;
    _1212_t2 = 30;
    _1212_t0 = (struct struct0) {_1212_t1, _1212_t2};
    _1213_x = _1212_t0._0;
    _1213_y = _1212_t0._1;
    _1212_t3 = $mult_int64_t(_1213_x, _1213_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1212_t4 = 1;
    _1212_$retval = $add_int64_t(_1212_t3, _1212_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1212_$retval;
}


int main(void) {
  printf("%ld",_1212_main());
  return 0;
}
