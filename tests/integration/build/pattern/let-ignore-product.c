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
    int64_t _2;
};

/* Function forward definitions */
int64_t _1161_main(void);

/* Function definitions */
int64_t _1161_main(void){
    int64_t _1161_t1;
    int64_t _1161_t2;
    int64_t _1161_t3;
    struct struct0 _1161_t0;
    int64_t _1162_a;
    int64_t _1162_c;
    int64_t _1161_$retval;
    _1161_t1 = 100;
    _1161_t2 = 300;
    _1161_t3 = 56;
    _1161_t0 = (struct struct0) {_1161_t1, _1161_t2, _1161_t3};
    _1162_a = _1161_t0._0;
    _1162_c = _1161_t0._2;
    _1161_$retval = $add_int64_t(_1162_a, _1162_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _1161_$retval;
}

int main(void) {
  printf("%ld",_1161_main());
  return 0;
}
