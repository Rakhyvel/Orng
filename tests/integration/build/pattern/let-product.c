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
int64_t _1234_main(void);


/* Function definitions */
int64_t _1234_main(void){
    int64_t _1234_t1;
    int64_t _1234_t2;
    struct struct0 _1234_t0;
    int64_t _1235_x;
    int64_t _1235_y;
    int64_t _1234_t4;
    int64_t _1234_t5;
    int64_t _1234_$retval;
    _1234_t1 = 5;
    _1234_t2 = 30;
    _1234_t0 = (struct struct0) {_1234_t1, _1234_t2};
    _1235_x = _1234_t0._0;
    _1235_y = _1234_t0._1;
    _1234_t4 = $mult_int64_t(_1235_x, _1235_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1234_t5 = 1;
    _1234_$retval = $add_int64_t(_1234_t4, _1234_t5, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1234_$retval;
}


int main(void) {
  printf("%ld",_1234_main());
  return 0;
}
