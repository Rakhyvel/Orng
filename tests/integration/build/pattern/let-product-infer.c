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
int64_t _1348_main(void);

/* Function definitions */
int64_t _1348_main(void){
    int64_t _1348_t1;
    int64_t _1348_t2;
    struct0 _1348_t0;
    int64_t _1349_a;
    int64_t _1349_b;
    int64_t _1348_$retval;
    _1348_t1 = 100;
    _1348_t2 = 58;
    _1348_t0 = (struct0) {_1348_t1, _1348_t2};
    _1349_a = _1348_t0._0;
    _1349_b = _1348_t0._1;
    _1348_$retval = $add_int64_t(_1349_a, _1349_b, "tests/integration/pattern/let-product-infer.orng:4:8:\n    a + b\n      ^");
    return _1348_$retval;
}

int main(void) {
  printf("%ld",_1348_main());
  return 0;
}
