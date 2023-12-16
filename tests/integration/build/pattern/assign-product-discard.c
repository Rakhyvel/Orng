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

typedef struct {
    int64_t _0;
    int64_t _2;
} struct1;

/* Function forward definitions */
int64_t _1051_main(void);

/* Function definitions */
int64_t _1051_main(void){
    int64_t _1051_t1;
    int64_t _1051_t2;
    struct0 _1051_t0;
    int64_t _1052_x;
    int64_t _1052_y;
    int64_t _1051_t4;
    int64_t _1051_t6;
    struct1 _1051_t3;
    int64_t _1051_$retval;
    _1051_t1 = 0;
    _1051_t2 = 0;
    _1051_t0 = (struct0) {_1051_t1, _1051_t2};
    _1052_x = _1051_t0._0;
    _1052_y = _1051_t0._1;
    _1051_t4 = 5;
    _1051_t6 = 33;
    _1051_t3 = (struct1) {_1051_t4, _1051_t6};
    _1052_x = _1051_t3._0;
    _1052_y = _1051_t3._2;
    _1051_$retval = $mult_int64_t(_1052_x, _1052_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1051_$retval;
}

int main(void) {
  printf("%ld",_1051_main());
  return 0;
}
