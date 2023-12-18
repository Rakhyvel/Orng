/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _623_main(void);

/* Function definitions */
int64_t _623_main(void){
    int64_t _623_t2;
    struct0 _624_x;
    struct0* _624_y;
    int64_t _623_t5;
    int64_t _623_$retval;
    _623_t2 = 0;
    _624_x = (struct0) {_623_t2, };
    _624_y = &_624_x;
    _623_t5 = 140;
    _623_$retval = $add_int64_t(_623_t5, (*_624_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _623_$retval;
}

int main(void) {
  printf("%ld",_623_main());
  return 0;
}
