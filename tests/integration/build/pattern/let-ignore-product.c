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
int64_t _746_main(void);

/* Function definitions */
int64_t _746_main(void) {
    int64_t _746_t1;
    int64_t _746_t2;
    int64_t _746_t3;
    struct0 _746_t0;
    int64_t _747_a;
    int64_t _747_c;
    int64_t _746_$retval;
    _746_t1 = 100;
    _746_t2 = 300;
    _746_t3 = 56;
    _746_t0 = (struct0) {_746_t1, _746_t2, _746_t3};
    _747_a = _746_t0._0;
    _747_c = _746_t0._2;
    _746_$retval = $add_int64_t(_747_a, _747_c, "tests/integration/pattern/let-ignore-product.orng:4:8:\n    a + c\n      ^");
    return _746_$retval;
}

int main(void) {
  printf("%ld",_746_main());
  return 0;
}
