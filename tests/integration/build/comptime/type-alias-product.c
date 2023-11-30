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
int64_t _126_main(void);

/* Function definitions */
int64_t _126_main(void) {
    int64_t _126_t1;
    int64_t _126_t2;
    struct0 _127_x;
    int64_t _126_$retval;
    _126_t1 = 200;
    _126_t2 = 40;
    _127_x = (struct0) {_126_t1, _126_t2};
    _126_$retval = $add_int64_t(_127_x._0, _127_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _126_$retval;
}

int main(void) {
  printf("%ld",_126_main());
  return 0;
}
