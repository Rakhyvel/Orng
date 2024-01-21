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
int64_t _1167_main(void);

/* Function definitions */
int64_t _1167_main(void){
    int64_t _1167_t1;
    int64_t _1167_t2;
    struct struct0 _1167_t0;
    int64_t _1168_x;
    int64_t _1168_y;
    int64_t _1167_t3;
    int64_t _1167_$retval;
    _1167_t1 = 3;
    _1167_t2 = 40;
    _1167_t0 = (struct struct0) {_1167_t1, _1167_t2};
    _1168_x = _1167_t0._0;
    _1168_y = _1167_t0._1;
    _1167_t3 = 100;
    _1168_y = $add_int64_t(_1168_y, _1167_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1167_$retval = $add_int64_t(_1168_x, _1168_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1167_$retval;
}

int main(void) {
  printf("%ld",_1167_main());
  return 0;
}
