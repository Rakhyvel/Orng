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
int64_t _451_main(void);

/* Function definitions */
int64_t _451_main(void){
    int64_t _451_t1;
    int64_t _451_t2;
    struct0 _452_x;
    int64_t _451_$retval;
    _451_t1 = 200;
    _451_t2 = 40;
    _452_x = (struct0) {_451_t1, _451_t2};
    _451_$retval = $add_int64_t(_452_x._0, _452_x._1, "tests/integration/comptime/type-alias-product.orng:6:10:\n    x.a + x.b\n        ^");
    return _451_$retval;
}

int main(void) {
  printf("%ld",_451_main());
  return 0;
}