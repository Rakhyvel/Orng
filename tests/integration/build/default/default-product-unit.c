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
int64_t _452_main(void);

/* Function definitions */
int64_t _452_main(void) {
    int64_t _452_t2;
    struct0 _453_x;
    struct0* _453_y;
    int64_t _452_t5;
    int64_t _452_$retval;
    _452_t2 = 0;
    _453_x = (struct0) {_452_t2, };
    _453_y = &_453_x;
    _452_t5 = 140;
    _452_$retval = $add_int64_t(_452_t5, (*_453_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _452_$retval;
}

int main(void) {
  printf("%ld",_452_main());
  return 0;
}
