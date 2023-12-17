/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1268_main(void);

/* Function definitions */
int64_t _1268_main(void){
    int64_t _1268_t1;
    int64_t _1268_t2;
    struct0 _1268_t0;
    int64_t _1269_x;
    int64_t _1269_y;
    int64_t _1268_t3;
    int64_t _1268_t4;
    int64_t _1268_$retval;
    _1268_t1 = 5;
    _1268_t2 = 30;
    _1268_t0 = (struct0) {_1268_t1, _1268_t2};
    _1269_x = _1268_t0._0;
    _1269_y = _1268_t0._1;
    _1268_t3 = $mult_int64_t(_1269_x, _1269_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1268_t4 = 1;
    _1268_$retval = $add_int64_t(_1268_t3, _1268_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1268_$retval;
}

int main(void) {
  printf("%ld",_1268_main());
  return 0;
}
