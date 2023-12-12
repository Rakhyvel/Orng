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
int64_t _296_main(void);

/* Function definitions */
int64_t _296_main(void) {
    int64_t _296_t2;
    struct0 _297_x;
    struct0* _297_y;
    int64_t _296_t5;
    int64_t _296_$retval;
    _296_t2 = 0;
    _297_x = (struct0) {_296_t2, };
    _297_y = &_297_x;
    _296_t5 = 140;
    _296_$retval = $add_int64_t(_296_t5, (*_297_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _296_$retval;
}

int main(void) {
  printf("%ld",_296_main());
  return 0;
}
