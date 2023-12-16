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
int64_t _306_main(void);

/* Function definitions */
int64_t _306_main(void){
    int64_t _306_t1;
    int64_t _306_t2;
    struct0 _307_x;
    int64_t _306_$retval;
    _306_t1 = 200;
    _306_t2 = 40;
    _307_x = (struct0) {_306_t1, _306_t2};
    _306_$retval = $add_int64_t(_307_x._0, _307_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _306_$retval;
}

int main(void) {
  printf("%ld",_306_main());
  return 0;
}
