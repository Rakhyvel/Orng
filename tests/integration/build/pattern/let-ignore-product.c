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
    int64_t _2;
} struct0;

/* Function forward definitions */
int64_t _836_main(void);

/* Function definitions */
int64_t _836_main(void) {
    int64_t _836_t1;
    int64_t _836_t2;
    int64_t _836_t3;
    struct0 _836_t0;
    int64_t _837_a;
    int64_t _837_c;
    int64_t _836_$retval;
    _836_t1 = 100;
    _836_t2 = 300;
    _836_t3 = 56;
    _836_t0 = (struct0) {_836_t1, _836_t2, _836_t3};
    _837_a = _836_t0._0;
    _837_c = _836_t0._2;
    _836_$retval = $add_int64_t(_837_a, _837_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _836_$retval;
}

int main(void) {
  printf("%ld",_836_main());
  return 0;
}
