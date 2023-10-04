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
    int64_t _2;
} struct0;

typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct1 _1_t4;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 1, 2};
    _1_t4 = (struct1) {(*((int64_t*)&_2_x + 1)), (*(int64_t*)&_2_x)};
    *(int64_t*)&_2_x = _1_t4._0;
    *((int64_t*)&_2_x + 1) = _1_t4._1;
    if (*(int64_t*)&_2_x > *((int64_t*)&_2_x + 1)) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _1_$retval = 162;
    return _1_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/pattern/assign-index-product.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
