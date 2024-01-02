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
int64_t _1159_main(void);

/* Function definitions */
int64_t _1159_main(void){
    int64_t _1159_t1;
    int64_t _1159_t2;
    struct struct0 _1159_t0;
    int64_t _1160_a;
    int64_t _1160_b;
    int64_t _1159_$retval;
    _1159_t1 = 100;
    _1159_t2 = 58;
    _1159_t0 = (struct struct0) {_1159_t1, _1159_t2};
    _1160_a = _1159_t0._0;
    _1160_b = _1159_t0._1;
    _1159_$retval = $add_int64_t(_1160_a, _1160_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1159_$retval;
}

int main(void) {
  printf("%ld",_1159_main());
  return 0;
}
