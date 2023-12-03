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
int64_t _148_main(void);

/* Function definitions */
int64_t _148_main(void) {
    int64_t _148_t1;
    int64_t _148_t2;
    struct0 _149_x;
    int64_t _148_$retval;
    _148_t1 = 200;
    _148_t2 = 40;
    _149_x = (struct0) {_148_t1, _148_t2};
    _148_$retval = $add_int64_t(_149_x._0, _149_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _148_$retval;
}

int main(void) {
  printf("%ld",_148_main());
  return 0;
}
