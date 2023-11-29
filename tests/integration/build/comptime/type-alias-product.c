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
int64_t _76_main(void);

/* Function definitions */
int64_t _76_main(void) {
    int64_t _76_t1;
    int64_t _76_t2;
    struct0 _77_x;
    int64_t _76_$retval;
    _76_t1 = 200;
    _76_t2 = 40;
    _77_x = (struct0) {_76_t1, _76_t2};
    _76_$retval = $add_int64_t(_77_x._0, _77_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _76_$retval;
}

int main(void) {
  printf("%ld",_76_main());
  return 0;
}
