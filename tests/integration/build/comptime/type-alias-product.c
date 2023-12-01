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
int64_t _65_main(void);

/* Function definitions */
int64_t _65_main(void) {
    int64_t _65_t1;
    int64_t _65_t2;
    struct0 _66_x;
    int64_t _65_$retval;
    _65_t1 = 200;
    _65_t2 = 40;
    _66_x = (struct0) {_65_t1, _65_t2};
    _65_$retval = $add_int64_t(_66_x._0, _66_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _65_$retval;
}

int main(void) {
  printf("%ld",_65_main());
  return 0;
}
