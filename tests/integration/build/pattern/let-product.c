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
int64_t _1180_main(void);

/* Function definitions */
int64_t _1180_main(void){
    int64_t _1180_t1;
    int64_t _1180_t2;
    struct struct0 _1180_t0;
    int64_t _1181_x;
    int64_t _1181_y;
    int64_t _1180_t3;
    int64_t _1180_t4;
    int64_t _1180_$retval;
    _1180_t1 = 5;
    _1180_t2 = 30;
    _1180_t0 = (struct struct0) {_1180_t1, _1180_t2};
    _1181_x = _1180_t0._0;
    _1181_y = _1180_t0._1;
    _1180_t3 = $mult_int64_t(_1181_x, _1181_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1180_t4 = 1;
    _1180_$retval = $add_int64_t(_1180_t3, _1180_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1180_$retval;
}

int main(void) {
  printf("%ld",_1180_main());
  return 0;
}
