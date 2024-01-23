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
int64_t _1185_main(void);


/* Function definitions */
int64_t _1185_main(void){
    int64_t _1185_t1;
    int64_t _1185_t2;
    struct struct0 _1185_t0;
    int64_t _1186_x;
    int64_t _1186_y;
    int64_t _1185_t3;
    int64_t _1185_t4;
    int64_t _1185_$retval;
    _1185_t1 = 5;
    _1185_t2 = 30;
    _1185_t0 = (struct struct0) {_1185_t1, _1185_t2};
    _1186_x = _1185_t0._0;
    _1186_y = _1185_t0._1;
    _1185_t3 = $mult_int64_t(_1186_x, _1186_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1185_t4 = 1;
    _1185_$retval = $add_int64_t(_1185_t3, _1185_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1185_$retval;
}


int main(void) {
  printf("%ld",_1185_main());
  return 0;
}
