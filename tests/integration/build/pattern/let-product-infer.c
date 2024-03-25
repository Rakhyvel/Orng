/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1184_main(void);


/* Function definitions */
int64_t _1184_main(void){
    int64_t _1184_t1;
    int64_t _1184_t2;
    struct struct0 _1184_t0;
    int64_t _1185_a;
    int64_t _1185_b;
    int64_t _1184_$retval;
    _1184_t1 = 100;
    _1184_t2 = 58;
    _1184_t0 = (struct struct0) {_1184_t1, _1184_t2};
    _1185_a = _1184_t0._0;
    _1185_b = _1184_t0._1;
    _1184_$retval = $add_int64_t(_1185_a, _1185_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1184_$retval;
}


int main(void) {
  printf("%ld",_1184_main());
  return 0;
}
