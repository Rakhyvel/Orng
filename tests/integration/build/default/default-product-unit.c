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
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0* _2_y;
    int64_t _1_$retval;
    _2_x = (struct0) {0};
    _2_y = &_2_x;
    _1_$retval = $add_int64_t(140, _2_y->_1, "tests/integration/default/default-product-unit.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
