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
int64_t _315_main(void);

/* Function definitions */
int64_t _315_main(void) {
    int64_t _315_t2;
    struct0 _316_x;
    struct0* _316_y;
    int64_t _315_t5;
    int64_t _315_$retval;
    _315_t2 = 0;
    _316_x = (struct0) {_315_t2, };
    _316_y = &_316_x;
    _315_t5 = 140;
    _315_$retval = $add_int64_t(_315_t5, (*_316_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _315_$retval;
}

int main(void) {
  printf("%ld",_315_main());
  return 0;
}
