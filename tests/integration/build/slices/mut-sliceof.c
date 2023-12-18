/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
    int64_t _4;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1534_main(void);

/* Function definitions */
int64_t _1534_main(void){
    int64_t _1534_t1;
    int64_t _1534_t2;
    int64_t _1534_t3;
    int64_t _1534_t4;
    int64_t _1534_t5;
    struct0 _1535_x;
    int64_t _1534_t7;
    int64_t _1534_t8;
    int64_t* _1534_t9;
    int64_t _1534_t10;
    struct1 _1535_y;
    int64_t _1534_t12;
    int64_t _1534_t13;
    int64_t _1534_$retval;
    _1534_t1 = 1;
    _1534_t2 = 2;
    _1534_t3 = 3;
    _1534_t4 = 4;
    _1534_t5 = 5;
    _1535_x = (struct0) {_1534_t1, _1534_t2, _1534_t3, _1534_t4, _1534_t5};
    _1534_t7 = 0;
    _1534_t8 = 5;
    $bounds_check(_1534_t7, _1534_t8, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1534_t9 = ((int64_t*)&_1535_x + _1534_t7);
    _1534_t10 = 5;
    _1535_y = (struct1) {_1534_t9, _1534_t10};
    _1534_t12 = 2;
    $bounds_check(_1534_t12, _1535_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1535_y._0 + _1534_t12) = 81;
    _1534_t13 = 2;
    $bounds_check(_1534_t13, _1535_y._1, "tests/integration/slices/mut-sliceof.orng:2:3:\nfn main() -> Int {\n ^");
    _1534_$retval = *((int64_t*)_1535_y._0 + _1534_t13);
    return _1534_$retval;
}

int main(void) {
  printf("%ld",_1534_main());
  return 0;
}
