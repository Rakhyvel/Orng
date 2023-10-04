/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct0;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct0 _1_t3;
    int64_t _1_$retval;
    _2_x = (struct0) {2, 324};
    _1_t3 = (struct0) {(*((int64_t*)&_2_x + 1)), (*(int64_t*)&_2_x)};
    *(int64_t*)&_2_x = _1_t3._0;
    *((int64_t*)&_2_x + 1) = _1_t3._1;
    _1_$retval = $div_int64_t(*(int64_t*)&_2_x, *((int64_t*)&_2_x + 1), "tests/integration/whitebox/assign-index-product2.orng:2:3:\nfn main() -> Int {\n ^");
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
