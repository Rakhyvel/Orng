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
int64_t _1165_main(void);

/* Function definitions */
int64_t _1165_main(void){
    int64_t _1165_t1;
    int64_t _1165_t2;
    struct struct0 _1165_t0;
    int64_t _1166_x;
    int64_t _1166_y;
    int64_t _1165_t3;
    int64_t _1165_t4;
    int64_t _1165_$retval;
    _1165_t1 = 5;
    _1165_t2 = 30;
    _1165_t0 = (struct struct0) {_1165_t1, _1165_t2};
    _1166_x = _1165_t0._0;
    _1166_y = _1165_t0._1;
    _1165_t3 = $mult_int64_t(_1166_x, _1166_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1165_t4 = 1;
    _1165_$retval = $add_int64_t(_1165_t3, _1165_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1165_$retval;
}

int main(void) {
  printf("%ld",_1165_main());
  return 0;
}
