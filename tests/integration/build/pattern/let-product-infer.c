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
int64_t _1156_main(void);

/* Function definitions */
int64_t _1156_main(void){
    int64_t _1156_t1;
    int64_t _1156_t2;
    struct struct0 _1156_t0;
    int64_t _1157_a;
    int64_t _1157_b;
    int64_t _1156_$retval;
    _1156_t1 = 100;
    _1156_t2 = 58;
    _1156_t0 = (struct struct0) {_1156_t1, _1156_t2};
    _1157_a = _1156_t0._0;
    _1157_b = _1156_t0._1;
    _1156_$retval = $add_int64_t(_1157_a, _1157_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1156_$retval;
}

int main(void) {
  printf("%ld",_1156_main());
  return 0;
}
