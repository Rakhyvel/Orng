/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
};

struct struct1 {
    int64_t _0;
    int64_t _2;
};

/* Function forward definitions */
int64_t _1173_main(void);


/* Function definitions */
int64_t _1173_main(void){
    int64_t _1173_t1;
    int64_t _1173_t2;
    struct struct0 _1173_t0;
    int64_t _1174_x;
    int64_t _1174_y;
    int64_t _1173_t4;
    int64_t _1173_t6;
    struct struct1 _1173_t3;
    int64_t _1173_$retval;
    _1173_t1 = 0;
    _1173_t2 = 0;
    _1173_t0 = (struct struct0) {_1173_t1, _1173_t2};
    _1174_x = _1173_t0._0;
    _1174_y = _1173_t0._1;
    _1173_t4 = 5;
    _1173_t6 = 33;
    _1173_t3 = (struct struct1) {_1173_t4, _1173_t6};
    _1174_x = _1173_t3._0;
    _1174_y = _1173_t3._2;
    _1173_$retval = $mult_int64_t(_1174_x, _1174_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1173_$retval;
}


int main(void) {
  printf("%ld",_1173_main());
  return 0;
}
