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
int64_t _1172_main(void);


/* Function definitions */
int64_t _1172_main(void){
    int64_t _1172_t1;
    int64_t _1172_t2;
    struct struct0 _1172_t0;
    int64_t _1173_x;
    int64_t _1173_y;
    int64_t _1172_t4;
    int64_t _1172_$retval;
    _1172_t1 = 3;
    _1172_t2 = 40;
    _1172_t0 = (struct struct0) {_1172_t1, _1172_t2};
    _1173_x = _1172_t0._0;
    _1173_y = _1172_t0._1;
    _1172_t4 = 100;
    _1173_y = $add_int64_t(_1173_y, _1172_t4, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1172_$retval = $add_int64_t(_1173_x, _1173_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1172_$retval;
}


int main(void) {
  printf("%ld",_1172_main());
  return 0;
}
