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
int64_t _1287_main(void);


/* Function definitions */
int64_t _1287_main(void){
    int64_t _1287_t1;
    int64_t _1287_t2;
    struct struct0 _1287_t0;
    int64_t _1288_x;
    int64_t _1288_y;
    int64_t _1287_t4;
    int64_t _1287_t5;
    int64_t _1287_$retval;
    _1287_t1 = 5;
    _1287_t2 = 30;
    _1287_t0 = (struct struct0) {_1287_t1, _1287_t2};
    _1288_x = _1287_t0._0;
    _1288_y = _1287_t0._1;
    _1287_t4 = $mult_int64_t(_1288_x, _1288_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1287_t5 = 1;
    _1287_$retval = $add_int64_t(_1287_t4, _1287_t5, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1287_$retval;
}


int main(void) {
  printf("%ld",_1287_main());
  return 0;
}
