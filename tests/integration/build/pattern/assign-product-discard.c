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
int64_t _1122_main(void);

/* Function definitions */
int64_t _1122_main(void){
    int64_t _1122_t1;
    int64_t _1122_t2;
    struct0 _1122_t0;
    int64_t _1123_x;
    int64_t _1123_y;
    int64_t _1122_t4;
    int64_t _1122_t6;
    struct1 _1122_t3;
    int64_t _1122_$retval;
    _1122_t1 = 0;
    _1122_t2 = 0;
    _1122_t0 = (struct0) {_1122_t1, _1122_t2};
    _1123_x = _1122_t0._0;
    _1123_y = _1122_t0._1;
    _1122_t4 = 5;
    _1122_t6 = 33;
    _1122_t3 = (struct1) {_1122_t4, _1122_t6};
    _1123_x = _1122_t3._0;
    _1123_y = _1122_t3._2;
    _1122_$retval = $mult_int64_t(_1123_x, _1123_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1122_$retval;
}

int main(void) {
  printf("%ld",_1122_main());
  return 0;
}
