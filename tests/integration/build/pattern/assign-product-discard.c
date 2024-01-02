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
int64_t _1126_main(void);

/* Function definitions */
int64_t _1126_main(void){
    int64_t _1126_t1;
    int64_t _1126_t2;
    struct struct0 _1126_t0;
    int64_t _1127_x;
    int64_t _1127_y;
    int64_t _1126_t4;
    int64_t _1126_t6;
    struct struct1 _1126_t3;
    int64_t _1126_$retval;
    _1126_t1 = 0;
    _1126_t2 = 0;
    _1126_t0 = (struct struct0) {_1126_t1, _1126_t2};
    _1127_x = _1126_t0._0;
    _1127_y = _1126_t0._1;
    _1126_t4 = 5;
    _1126_t6 = 33;
    _1126_t3 = (struct struct1) {_1126_t4, _1126_t6};
    _1127_x = _1126_t3._0;
    _1127_y = _1126_t3._2;
    _1126_$retval = $mult_int64_t(_1127_x, _1127_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1126_$retval;
}

int main(void) {
  printf("%ld",_1126_main());
  return 0;
}
