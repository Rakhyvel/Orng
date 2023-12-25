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
int64_t _365_main(void);

/* Function definitions */
int64_t _365_main(void){
    int64_t _365_t1;
    int64_t _365_t2;
    struct0 _366_x;
    int64_t _365_$retval;
    _365_t1 = 200;
    _365_t2 = 40;
    _366_x = (struct0) {_365_t1, _365_t2};
    _365_$retval = $add_int64_t(_366_x._0, _366_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _365_$retval;
}

int main(void) {
  printf("%ld",_365_main());
  return 0;
}
