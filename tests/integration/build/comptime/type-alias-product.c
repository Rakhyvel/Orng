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
int64_t _156_main(void);

/* Function definitions */
int64_t _156_main(void) {
    int64_t _156_t1;
    int64_t _156_t2;
    struct0 _157_x;
    int64_t _156_$retval;
    _156_t1 = 200;
    _156_t2 = 40;
    _157_x = (struct0) {_156_t1, _156_t2};
    _156_$retval = $add_int64_t(_157_x._0, _157_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _156_$retval;
}

int main(void) {
  printf("%ld",_156_main());
  return 0;
}
