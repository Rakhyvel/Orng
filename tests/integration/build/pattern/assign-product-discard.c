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
int64_t _1146_main(void);


/* Function definitions */
int64_t _1146_main(void){
    int64_t _1146_t1;
    int64_t _1146_t2;
    struct struct0 _1146_t0;
    int64_t _1147_x;
    int64_t _1147_y;
    int64_t _1146_t4;
    int64_t _1146_t6;
    struct struct1 _1146_t3;
    int64_t _1146_$retval;
    _1146_t1 = 0;
    _1146_t2 = 0;
    _1146_t0 = (struct struct0) {_1146_t1, _1146_t2};
    _1147_x = _1146_t0._0;
    _1147_y = _1146_t0._1;
    _1146_t4 = 5;
    _1146_t6 = 33;
    _1146_t3 = (struct struct1) {_1146_t4, _1146_t6};
    _1147_x = _1146_t3._0;
    _1147_y = _1146_t3._2;
    _1146_$retval = $mult_int64_t(_1147_x, _1147_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1146_$retval;
}


int main(void) {
  printf("%ld",_1146_main());
  return 0;
}
