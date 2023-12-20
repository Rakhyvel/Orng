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
int64_t _1136_main(void);

/* Function definitions */
int64_t _1136_main(void){
    int64_t _1136_t1;
    int64_t _1136_t2;
    struct0 _1136_t0;
    int64_t _1137_x;
    int64_t _1137_y;
    int64_t _1136_t3;
    int64_t _1136_$retval;
    _1136_t1 = 3;
    _1136_t2 = 40;
    _1136_t0 = (struct0) {_1136_t1, _1136_t2};
    _1137_x = _1136_t0._0;
    _1137_y = _1136_t0._1;
    _1136_t3 = 100;
    _1137_y = $add_int64_t(_1137_y, _1136_t3, "tests/integration/pattern/let-mut-product.orng:4:9:\n    y += 100\n       ^");
    _1136_$retval = $add_int64_t(_1137_x, _1137_y, "tests/integration/pattern/let-mut-product.orng:5:8:\n    x + y\n      ^");
    return _1136_$retval;
}

int main(void) {
  printf("%ld",_1136_main());
  return 0;
}
