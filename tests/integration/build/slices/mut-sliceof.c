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
    int64_t _3;
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    int64_t* _1_t10;
    struct1 _2_y;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 2, 3, 4, 5};
    _1_t10 = (int64_t*)&_2_x;
    _2_y = (struct1) {_1_t10, 5};
    *((int64_t*)_2_y._0 + 2) = 81;
    $bounds_check(2, _2_y._1, "tests/integration/slices/mut-sliceof.orng:6:7:\n    y[2]\n     ^");
    _1_$retval = *((int64_t*)_2_y._0 + 2);
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
