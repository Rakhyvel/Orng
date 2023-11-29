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
int64_t _326_main(void);

/* Function definitions */
int64_t _326_main(void) {
    int64_t _326_t2;
    struct0 _327_x;
    struct0* _327_y;
    int64_t _326_t5;
    int64_t _326_$retval;
    _326_t2 = 0;
    _327_x = (struct0) {_326_t2, };
    _327_y = &_327_x;
    _326_t5 = 140;
    _326_$retval = $add_int64_t(_326_t5, (*_327_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _326_$retval;
}

int main(void) {
  printf("%ld",_326_main());
  return 0;
}
