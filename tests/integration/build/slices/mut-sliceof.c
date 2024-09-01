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
    int64_t _2;
    int64_t _3;
    int64_t _4;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1399_main(void);


/* Function definitions */
int64_t _1399_main(void){
    int64_t _1399_t1;
    int64_t _1399_t2;
    int64_t _1399_t3;
    int64_t _1399_t4;
    int64_t _1399_t5;
    struct struct0 _1400_x;
    int64_t _1399_t8;
    int64_t _1399_t9;
    int64_t* _1399_t10;
    int64_t _1399_t11;
    struct struct1 _1400_y;
    int64_t _1399_t14;
    int64_t _1399_t15;
    int64_t _1399_$retval;
    _1399_t1 = 1;
    _1399_t2 = 2;
    _1399_t3 = 3;
    _1399_t4 = 4;
    _1399_t5 = 5;
    _1400_x = (struct struct0) {_1399_t1, _1399_t2, _1399_t3, _1399_t4, _1399_t5};
    _1399_t8 = 0;
    _1399_t9 = 5;
    $bounds_check(_1399_t8, _1399_t9, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1399_t10 = ((int64_t*)&_1400_x + _1399_t8);
    _1399_t11 = 5;
    _1400_y = (struct struct1) {_1399_t10, _1399_t11};
    _1399_t14 = 2;
    $bounds_check(_1399_t14, _1400_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1400_y._0 + _1399_t14) = 81;
    _1399_t15 = 2;
    $bounds_check(_1399_t15, _1400_y._1, "tests/integration/slices/mut-sliceof.orng:2:3:\nfn main() -> Int {\n ^");
    _1399_$retval = *((int64_t*)_1400_y._0 + _1399_t15);
    return _1399_$retval;
}


int main(void) {
  printf("%ld",_1399_main());
  return 0;
}
