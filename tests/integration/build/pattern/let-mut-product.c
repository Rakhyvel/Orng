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
int64_t _1249_main(void);


/* Function definitions */
int64_t _1249_main(void){
    int64_t _1249_t1;
    int64_t _1249_t2;
    struct struct0 _1249_t0;
    int64_t _1250_x;
    int64_t _1250_y;
    int64_t _1249_t4;
    int64_t _1249_$retval;
    _1249_t1 = 3;
    _1249_t2 = 40;
    _1249_t0 = (struct struct0) {_1249_t1, _1249_t2};
    _1250_x = _1249_t0._0;
    _1250_y = _1249_t0._1;
    _1249_t4 = 100;
    _1250_y = $add_int64_t(_1250_y, _1249_t4, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1249_$retval = $add_int64_t(_1250_x, _1250_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1249_$retval;
}


int main(void) {
  printf("%ld",_1249_main());
  return 0;
}
