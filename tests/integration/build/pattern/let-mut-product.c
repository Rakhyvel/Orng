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
int64_t _1147_main(void);

/* Function definitions */
int64_t _1147_main(void){
    int64_t _1147_t1;
    int64_t _1147_t2;
    struct struct0 _1147_t0;
    int64_t _1148_x;
    int64_t _1148_y;
    int64_t _1147_t3;
    int64_t _1147_$retval;
    _1147_t1 = 3;
    _1147_t2 = 40;
    _1147_t0 = (struct struct0) {_1147_t1, _1147_t2};
    _1148_x = _1147_t0._0;
    _1148_y = _1147_t0._1;
    _1147_t3 = 100;
    _1148_y = $add_int64_t(_1148_y, _1147_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1147_$retval = $add_int64_t(_1148_x, _1148_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1147_$retval;
}

int main(void) {
  printf("%ld",_1147_main());
  return 0;
}
