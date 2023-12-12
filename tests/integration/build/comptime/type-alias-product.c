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
int64_t _92_main(void);

/* Function definitions */
int64_t _92_main(void) {
    int64_t _92_t1;
    int64_t _92_t2;
    struct0 _93_x;
    int64_t _92_$retval;
    _92_t1 = 200;
    _92_t2 = 40;
    _93_x = (struct0) {_92_t1, _92_t2};
    _92_$retval = $add_int64_t(_93_x._0, _93_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _92_$retval;
}

int main(void) {
  printf("%ld",_92_main());
  return 0;
}
