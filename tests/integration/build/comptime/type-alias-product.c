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
int64_t _195_main(void);

/* Function definitions */
int64_t _195_main(void){
    int64_t _195_t1;
    int64_t _195_t2;
    struct0 _196_x;
    int64_t _195_$retval;
    _195_t1 = 200;
    _195_t2 = 40;
    _196_x = (struct0) {_195_t1, _195_t2};
    _195_$retval = $add_int64_t(_196_x._0, _196_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _195_$retval;
}

int main(void) {
  printf("%ld",_195_main());
  return 0;
}
