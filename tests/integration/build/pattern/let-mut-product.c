/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1152_main(void);

/* Function definitions */
int64_t _1152_main(void){
    int64_t _1152_t1;
    int64_t _1152_t2;
    struct struct0 _1152_t0;
    int64_t _1153_x;
    int64_t _1153_y;
    int64_t _1152_t3;
    int64_t _1152_$retval;
    _1152_t1 = 3;
    _1152_t2 = 40;
    _1152_t0 = (struct struct0) {_1152_t1, _1152_t2};
    _1153_x = _1152_t0._0;
    _1153_y = _1152_t0._1;
    _1152_t3 = 100;
    _1153_y = $add_int64_t(_1153_y, _1152_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1152_$retval = $add_int64_t(_1153_x, _1153_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1152_$retval;
}

int main(void) {
  printf("%ld",_1152_main());
  return 0;
}
