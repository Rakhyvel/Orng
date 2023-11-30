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
int64_t _117_main(void);

/* Function definitions */
int64_t _117_main(void) {
    int64_t _117_t1;
    int64_t _117_t2;
    struct0 _118_x;
    int64_t _117_$retval;
    _117_t1 = 200;
    _117_t2 = 40;
    _118_x = (struct0) {_117_t1, _117_t2};
    _117_$retval = $add_int64_t(_118_x._0, _118_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _117_$retval;
}

int main(void) {
  printf("%ld",_117_main());
  return 0;
}
