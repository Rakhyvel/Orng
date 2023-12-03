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
int64_t _288_main(void);

/* Function definitions */
int64_t _288_main(void) {
    int64_t _288_t2;
    struct0 _289_x;
    struct0* _289_y;
    int64_t _288_t5;
    int64_t _288_$retval;
    _288_t2 = 0;
    _289_x = (struct0) {_288_t2, };
    _289_y = &_289_x;
    _288_t5 = 140;
    _288_$retval = $add_int64_t(_288_t5, (*_289_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _288_$retval;
}

int main(void) {
  printf("%ld",_288_main());
  return 0;
}
