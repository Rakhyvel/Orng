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
int64_t _1423_main(void);


/* Function definitions */
int64_t _1423_main(void){
    int64_t _1423_t1;
    int64_t _1423_t2;
    int64_t _1423_t3;
    int64_t _1423_t4;
    int64_t _1423_t5;
    struct struct0 _1424_x;
    int64_t _1423_t8;
    int64_t _1423_t9;
    int64_t* _1423_t10;
    int64_t _1423_t11;
    struct struct1 _1424_y;
    int64_t _1423_t14;
    int64_t _1423_t15;
    int64_t _1423_$retval;
    _1423_t1 = 1;
    _1423_t2 = 2;
    _1423_t3 = 3;
    _1423_t4 = 4;
    _1423_t5 = 5;
    _1424_x = (struct struct0) {_1423_t1, _1423_t2, _1423_t3, _1423_t4, _1423_t5};
    _1423_t8 = 0;
    _1423_t9 = 5;
    $bounds_check(_1423_t8, _1423_t9, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1423_t10 = ((int64_t*)&_1424_x + _1423_t8);
    _1423_t11 = 5;
    _1424_y = (struct struct1) {_1423_t10, _1423_t11};
    _1423_t14 = 2;
    $bounds_check(_1423_t14, _1424_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1424_y._0 + _1423_t14) = 81;
    _1423_t15 = 2;
    $bounds_check(_1423_t15, _1424_y._1, "tests/integration/slices/mut-sliceof.orng:2:8:\nfn main() -> Int {\n      ^");
    _1423_$retval = *((int64_t*)_1424_y._0 + _1423_t15);
    return _1423_$retval;
}


int main(void) {
  printf("%ld",_1423_main());
  return 0;
}
