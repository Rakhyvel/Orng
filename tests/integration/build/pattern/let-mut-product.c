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
int64_t _1085_main(void);

/* Function definitions */
int64_t _1085_main(void){
    int64_t _1085_t1;
    int64_t _1085_t2;
    struct0 _1085_t0;
    int64_t _1086_x;
    int64_t _1086_y;
    int64_t _1085_t3;
    int64_t _1085_$retval;
    _1085_t1 = 3;
    _1085_t2 = 40;
    _1085_t0 = (struct0) {_1085_t1, _1085_t2};
    _1086_x = _1085_t0._0;
    _1086_y = _1085_t0._1;
    _1085_t3 = 100;
    _1086_y = $add_int64_t(_1086_y, _1085_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1085_$retval = $add_int64_t(_1086_x, _1086_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1085_$retval;
}

int main(void) {
  printf("%ld",_1085_main());
  return 0;
}
