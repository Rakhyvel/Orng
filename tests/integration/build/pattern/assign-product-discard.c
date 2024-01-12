/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    int64_t _0;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1141_main(void);

/* Function definitions */
int64_t _1141_main(void){
    int64_t _1141_t1;
    int64_t _1141_t2;
    struct struct0 _1141_t0;
    int64_t _1142_x;
    int64_t _1142_y;
    int64_t _1141_t4;
    int64_t _1141_t6;
    struct struct1 _1141_t3;
    int64_t _1141_$retval;
    _1141_t1 = 0;
    _1141_t2 = 0;
    _1141_t0 = (struct struct0) {_1141_t1, _1141_t2};
    _1142_x = _1141_t0._0;
    _1142_y = _1141_t0._1;
    _1141_t4 = 5;
    _1141_t6 = 33;
    _1141_t3 = (struct struct1) {_1141_t4, _1141_t6};
    _1142_x = _1141_t3._0;
    _1142_y = _1141_t3._2;
    _1141_$retval = $mult_int64_t(_1142_x, _1142_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1141_$retval;
}

int main(void) {
  printf("%ld",_1141_main());
  return 0;
}
