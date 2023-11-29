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
int64_t _423_main(void);

/* Function definitions */
int64_t _423_main(void) {
    int64_t _423_t2;
    struct0 _424_x;
    struct0* _424_y;
    int64_t _423_t5;
    int64_t _423_$retval;
    _423_t2 = 0;
    _424_x = (struct0) {_423_t2, };
    _424_y = &_424_x;
    _423_t5 = 140;
    _423_$retval = $add_int64_t(_423_t5, (*_424_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _423_$retval;
}

int main(void) {
  printf("%ld",_423_main());
  return 0;
}
