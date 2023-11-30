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
int64_t _402_main(void);

/* Function definitions */
int64_t _402_main(void) {
    int64_t _402_t2;
    struct0 _403_x;
    struct0* _403_y;
    int64_t _402_t5;
    int64_t _402_$retval;
    _402_t2 = 0;
    _403_x = (struct0) {_402_t2, };
    _403_y = &_403_x;
    _402_t5 = 140;
    _402_$retval = $add_int64_t(_402_t5, (*_403_y)._1, "tests/integration/default/default-product-unit.orng:5:10:\n    140 + y.b\n        ^");
    return _402_$retval;
}

int main(void) {
  printf("%ld",_402_main());
  return 0;
}
