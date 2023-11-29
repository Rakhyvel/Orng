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
int64_t _267_main(void);

/* Function definitions */
int64_t _267_main(void) {
    int64_t _267_t1;
    int64_t _267_t2;
    struct0 _268_x;
    int64_t _267_$retval;
    _267_t1 = 200;
    _267_t2 = 40;
    _268_x = (struct0) {_267_t1, _267_t2};
    _267_$retval = $add_int64_t(_268_x._0, _268_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _267_$retval;
}

int main(void) {
  printf("%ld",_267_main());
  return 0;
}
