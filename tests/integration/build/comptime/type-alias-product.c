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
int64_t _311_main(void);


/* Function definitions */
int64_t _311_main(void){
    int64_t _311_t1;
    int64_t _311_t2;
    struct struct0 _312_x;
    int64_t _311_$retval;
    _311_t1 = 200;
    _311_t2 = 40;
    _312_x = (struct struct0) {_311_t1, _311_t2};
    _311_$retval = $add_int64_t(_312_x._0, _312_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _311_$retval;
}


int main(void) {
  printf("%ld",_311_main());
  return 0;
}
