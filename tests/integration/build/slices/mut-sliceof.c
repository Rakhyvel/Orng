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
    int64_t _2;
    int64_t _3;
    int64_t _4;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

/* Function forward definitions */
int64_t _1345_main(void);

/* Function definitions */
int64_t _1345_main(void){
    int64_t _1345_t1;
    int64_t _1345_t2;
    int64_t _1345_t3;
    int64_t _1345_t4;
    int64_t _1345_t5;
    struct struct0 _1346_x;
    int64_t _1345_t7;
    int64_t _1345_t8;
    int64_t* _1345_t9;
    int64_t _1345_t10;
    struct struct1 _1346_y;
    int64_t _1345_t12;
    int64_t _1345_t13;
    int64_t _1345_$retval;
    _1345_t1 = 1;
    _1345_t2 = 2;
    _1345_t3 = 3;
    _1345_t4 = 4;
    _1345_t5 = 5;
    _1346_x = (struct struct0) {_1345_t1, _1345_t2, _1345_t3, _1345_t4, _1345_t5};
    _1345_t7 = 0;
    _1345_t8 = 5;
    $bounds_check(_1345_t7, _1345_t8, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1345_t9 = ((int64_t*)&_1346_x + _1345_t7);
    _1345_t10 = 5;
    _1346_y = (struct struct1) {_1345_t9, _1345_t10};
    _1345_t12 = 2;
    $bounds_check(_1345_t12, _1346_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1346_y._0 + _1345_t12) = 81;
    _1345_t13 = 2;
    $bounds_check(_1345_t13, _1346_y._1, "tests/integration/slices/mut-sliceof.orng:2:3:\nfn main() -> Int {\n ^");
    _1345_$retval = *((int64_t*)_1346_y._0 + _1345_t13);
    return _1345_$retval;
}

int main(void) {
  printf("%ld",_1345_main());
  return 0;
}
