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
int64_t _224_main(void);

/* Function definitions */
int64_t _224_main(void) {
    int64_t _224_t2;
    struct0 _225_x;
    struct0* _225_y;
    int64_t _224_t5;
    int64_t _224_$retval;
    _224_t2 = 0;
    _225_x = (struct0) {_224_t2, };
    _225_y = &_225_x;
    _224_t5 = 140;
    _224_$retval = $add_int64_t(_224_t5, (*_225_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _224_$retval;
}

int main(void) {
  printf("%ld",_224_main());
  return 0;
}
