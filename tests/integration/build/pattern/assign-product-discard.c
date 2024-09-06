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
int64_t _1206_main(void);


/* Function definitions */
int64_t _1206_main(void){
    int64_t _1206_t1;
    int64_t _1206_t2;
    struct struct0 _1206_t0;
    int64_t _1207_x;
    int64_t _1207_y;
    int64_t _1206_t5;
    int64_t _1206_t7;
    struct struct1 _1206_t4;
    int64_t _1206_$retval;
    _1206_t1 = 0;
    _1206_t2 = 0;
    _1206_t0 = (struct struct0) {_1206_t1, _1206_t2};
    _1207_x = _1206_t0._0;
    _1207_y = _1206_t0._1;
    _1206_t5 = 5;
    _1206_t7 = 33;
    _1206_t4 = (struct struct1) {_1206_t5, _1206_t7};
    _1207_x = _1206_t4._0;
    _1207_y = _1206_t4._2;
    _1206_$retval = $mult_int64_t(_1207_x, _1207_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1206_$retval;
}


int main(void) {
  printf("%ld",_1206_main());
  return 0;
}
