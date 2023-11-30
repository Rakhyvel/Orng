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
int64_t _425_main(void);

/* Function definitions */
int64_t _425_main(void) {
    int64_t _425_t2;
    struct0 _426_x;
    struct0* _426_y;
    int64_t _425_t5;
    int64_t _425_$retval;
    _425_t2 = 0;
    _426_x = (struct0) {_425_t2, };
    _426_y = &_426_x;
    _425_t5 = 140;
    _425_$retval = $add_int64_t(_425_t5, (*_426_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _425_$retval;
}

int main(void) {
  printf("%ld",_425_main());
  return 0;
}
