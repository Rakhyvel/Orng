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
int64_t _1156_main(void);


/* Function definitions */
int64_t _1156_main(void){
    int64_t _1156_t1;
    int64_t _1156_t2;
    struct struct0 _1156_t0;
    int64_t _1157_x;
    int64_t _1157_y;
    int64_t _1156_t5;
    int64_t _1156_t7;
    struct struct1 _1156_t4;
    int64_t _1156_$retval;
    _1156_t1 = 0;
    _1156_t2 = 0;
    _1156_t0 = (struct struct0) {_1156_t1, _1156_t2};
    _1157_x = _1156_t0._0;
    _1157_y = _1156_t0._1;
    _1156_t5 = 5;
    _1156_t7 = 33;
    _1156_t4 = (struct struct1) {_1156_t5, _1156_t7};
    _1157_x = _1156_t4._0;
    _1157_y = _1156_t4._2;
    _1156_$retval = $mult_int64_t(_1157_x, _1157_y, "tests/integration/pattern/assign-product-discard.orng:5:8:\n    x * y\n      ^");
    return _1156_$retval;
}


int main(void) {
  printf("%ld",_1156_main());
  return 0;
}
