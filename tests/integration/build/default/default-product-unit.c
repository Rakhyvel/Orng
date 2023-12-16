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
int64_t _471_main(void);

/* Function definitions */
int64_t _471_main(void){
    int64_t _471_t2;
    struct0 _472_x;
    struct0* _472_y;
    int64_t _471_t5;
    int64_t _471_$retval;
    _471_t2 = 0;
    _472_x = (struct0) {_471_t2, };
    _472_y = &_472_x;
    _471_t5 = 140;
    _471_$retval = $add_int64_t(_471_t5, (*_472_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _471_$retval;
}

int main(void) {
  printf("%ld",_471_main());
  return 0;
}
