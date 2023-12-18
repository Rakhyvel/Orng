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
int64_t _1354_main(void);

/* Function definitions */
int64_t _1354_main(void){
    int64_t _1354_t1;
    int64_t _1354_t2;
    struct0 _1354_t0;
    int64_t _1355_a;
    int64_t _1355_b;
    int64_t _1354_$retval;
    _1354_t1 = 100;
    _1354_t2 = 58;
    _1354_t0 = (struct0) {_1354_t1, _1354_t2};
    _1355_a = _1354_t0._0;
    _1355_b = _1354_t0._1;
    _1354_$retval = $add_int64_t(_1355_a, _1355_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1354_$retval;
}

int main(void) {
  printf("%ld",_1354_main());
  return 0;
}
