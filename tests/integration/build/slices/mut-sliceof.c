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
int64_t _1350_main(void);


/* Function definitions */
int64_t _1350_main(void){
    int64_t _1350_t1;
    int64_t _1350_t2;
    int64_t _1350_t3;
    int64_t _1350_t4;
    int64_t _1350_t5;
    struct struct0 _1351_x;
    int64_t _1350_t7;
    int64_t _1350_t8;
    int64_t* _1350_t9;
    int64_t _1350_t10;
    struct struct1 _1351_y;
    int64_t _1350_t12;
    int64_t _1350_t13;
    int64_t _1350_$retval;
    _1350_t1 = 1;
    _1350_t2 = 2;
    _1350_t3 = 3;
    _1350_t4 = 4;
    _1350_t5 = 5;
    _1351_x = (struct struct0) {_1350_t1, _1350_t2, _1350_t3, _1350_t4, _1350_t5};
    _1350_t7 = 0;
    _1350_t8 = 5;
    $bounds_check(_1350_t7, _1350_t8, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1350_t9 = ((int64_t*)&_1351_x + _1350_t7);
    _1350_t10 = 5;
    _1351_y = (struct struct1) {_1350_t9, _1350_t10};
    _1350_t12 = 2;
    $bounds_check(_1350_t12, _1351_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1351_y._0 + _1350_t12) = 81;
    _1350_t13 = 2;
    $bounds_check(_1350_t13, _1351_y._1, "tests/integration/slices/mut-sliceof.orng:2:3:\nfn main() -> Int {\n ^");
    _1350_$retval = *((int64_t*)_1351_y._0 + _1350_t13);
    return _1350_$retval;
}


int main(void) {
  printf("%ld",_1350_main());
  return 0;
}
