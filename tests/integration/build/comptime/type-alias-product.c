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
int64_t _82_main(void);

/* Function definitions */
int64_t _82_main(void) {
    int64_t _82_t1;
    int64_t _82_t2;
    struct0 _83_x;
    int64_t _82_$retval;
    _82_t1 = 200;
    _82_t2 = 40;
    _83_x = (struct0) {_82_t1, _82_t2};
    _82_$retval = $add_int64_t(_83_x._0, _83_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _82_$retval;
}

int main(void) {
  printf("%ld",_82_main());
  return 0;
}
