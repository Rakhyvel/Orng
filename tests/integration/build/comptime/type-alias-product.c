/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _413_main(void);


/* Function definitions */
int64_t _413_main(void){
    int64_t _413_t1;
    int64_t _413_t2;
    struct struct0 _414_x;
    int64_t _413_$retval;
    _413_t1 = 200;
    _413_t2 = 40;
    _414_x = (struct struct0) {_413_t1, _413_t2};
    _413_$retval = $add_int64_t(_414_x._0, _414_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _413_$retval;
}


int main(void) {
  printf("%ld",_413_main());
  return 0;
}
