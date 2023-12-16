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
int64_t _1183_main(void);

/* Function definitions */
int64_t _1183_main(void){
    int64_t _1183_t1;
    int64_t _1183_t2;
    struct0 _1183_t0;
    int64_t _1184_x;
    int64_t _1184_y;
    int64_t _1183_t3;
    int64_t _1183_t4;
    int64_t _1183_$retval;
    _1183_t1 = 5;
    _1183_t2 = 30;
    _1183_t0 = (struct0) {_1183_t1, _1183_t2};
    _1184_x = _1183_t0._0;
    _1184_y = _1183_t0._1;
    _1183_t3 = $mult_int64_t(_1184_x, _1184_y, "tests/integration/pattern/let-product.orng:4:8:\n    x * y + 1\n      ^");
    _1183_t4 = 1;
    _1183_$retval = $add_int64_t(_1183_t3, _1183_t4, "tests/integration/pattern/let-product.orng:4:12:\n    x * y + 1\n          ^");
    return _1183_$retval;
}

int main(void) {
  printf("%ld",_1183_main());
  return 0;
}
