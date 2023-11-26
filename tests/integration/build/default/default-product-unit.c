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
int64_t _29_main(void);

/* Function definitions */
int64_t _29_main(void) {
    int64_t _29_t2;
    struct0 _30_x;
    struct0* _30_y;
    int64_t _29_t5;
    int64_t _29_$retval;
    _29_t2 = 0;
    _30_x = (struct0) {_29_t2};
    _30_y = &_30_x;
    _29_t5 = 140;
    _29_$retval = $add_int64_t(_29_t5, (*_30_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _29_$retval;
}

int main(void) {
  printf("%ld",_29_main());
  return 0;
}
