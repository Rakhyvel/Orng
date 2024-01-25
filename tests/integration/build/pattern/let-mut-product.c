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
int64_t _1194_main(void);


/* Function definitions */
int64_t _1194_main(void){
    int64_t _1194_t1;
    int64_t _1194_t2;
    struct struct0 _1194_t0;
    int64_t _1195_x;
    int64_t _1195_y;
    int64_t _1194_t3;
    int64_t _1194_$retval;
    _1194_t1 = 3;
    _1194_t2 = 40;
    _1194_t0 = (struct struct0) {_1194_t1, _1194_t2};
    _1195_x = _1194_t0._0;
    _1195_y = _1194_t0._1;
    _1194_t3 = 100;
    _1195_y = $add_int64_t(_1195_y, _1194_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1194_$retval = $add_int64_t(_1195_x, _1195_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1194_$retval;
}


int main(void) {
  printf("%ld",_1194_main());
  return 0;
}
