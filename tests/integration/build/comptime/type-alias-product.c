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
int64_t _295_main(void);

/* Function definitions */
int64_t _295_main(void) {
    int64_t _295_t1;
    int64_t _295_t2;
    struct0 _296_x;
    int64_t _295_$retval;
    _295_t1 = 200;
    _295_t2 = 40;
    _296_x = (struct0) {_295_t1, _295_t2};
    _295_$retval = $add_int64_t(_296_x._0, _296_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _295_$retval;
}

int main(void) {
  printf("%ld",_295_main());
  return 0;
}
