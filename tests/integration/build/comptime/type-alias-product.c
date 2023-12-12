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
int64_t _175_main(void);

/* Function definitions */
int64_t _175_main(void) {
    int64_t _175_t1;
    int64_t _175_t2;
    struct0 _176_x;
    int64_t _175_$retval;
    _175_t1 = 200;
    _175_t2 = 40;
    _176_x = (struct0) {_175_t1, _175_t2};
    _175_$retval = $add_int64_t(_176_x._0, _176_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _175_$retval;
}

int main(void) {
  printf("%ld",_175_main());
  return 0;
}
