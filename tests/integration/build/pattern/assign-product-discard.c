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
int64_t _797_main(void);

/* Function definitions */
int64_t _797_main(void) {
    int64_t _797_t1;
    int64_t _797_t2;
    struct0 _797_t0;
    int64_t _798_x;
    int64_t _798_y;
    int64_t _797_t4;
    int64_t _797_t6;
    struct1 _797_t3;
    int64_t _797_$retval;
    _797_t1 = 0;
    _797_t2 = 0;
    _797_t0 = (struct0) {_797_t1, _797_t2};
    _798_x = _797_t0._0;
    _798_y = _797_t0._1;
    _797_t4 = 5;
    _797_t6 = 33;
    _797_t3 = (struct1) {_797_t4, _797_t6};
    _798_x = _797_t3._0;
    _798_y = _797_t3._2;
    _797_$retval = $mult_int64_t(_798_x, _798_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _797_$retval;
}

int main(void) {
  printf("%ld",_797_main());
  return 0;
}
