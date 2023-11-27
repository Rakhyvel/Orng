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
int64_t _3_main(void);

/* Function definitions */
int64_t _3_main(void) {
    int64_t _3_t1;
    int64_t _3_t2;
    struct0 _4_x;
    int64_t _3_$retval;
    _3_t1 = 200;
    _3_t2 = 40;
    _4_x = (struct0) {_3_t1, _3_t2};
    _3_$retval = $add_int64_t(_4_x._0, _4_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _3_$retval;
}

int main(void) {
  printf("%ld",_3_main());
  return 0;
}
