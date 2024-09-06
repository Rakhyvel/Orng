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
int64_t _1248_main(void);


/* Function definitions */
int64_t _1248_main(void){
    int64_t _1248_t1;
    int64_t _1248_t2;
    struct struct0 _1248_t0;
    int64_t _1249_x;
    int64_t _1249_y;
    int64_t _1248_t4;
    int64_t _1248_t5;
    int64_t _1248_$retval;
    _1248_t1 = 5;
    _1248_t2 = 30;
    _1248_t0 = (struct struct0) {_1248_t1, _1248_t2};
    _1249_x = _1248_t0._0;
    _1249_y = _1248_t0._1;
    _1248_t4 = $mult_int64_t(_1249_x, _1249_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1248_t5 = 1;
    _1248_$retval = $add_int64_t(_1248_t4, _1248_t5, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1248_$retval;
}


int main(void) {
  printf("%ld",_1248_main());
  return 0;
}
