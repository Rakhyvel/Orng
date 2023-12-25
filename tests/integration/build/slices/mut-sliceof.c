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
int64_t _1303_main(void);

/* Function definitions */
int64_t _1303_main(void){
    int64_t _1303_t1;
    int64_t _1303_t2;
    int64_t _1303_t3;
    int64_t _1303_t4;
    int64_t _1303_t5;
    struct0 _1304_x;
    int64_t _1303_t7;
    int64_t _1303_t8;
    int64_t* _1303_t9;
    int64_t _1303_t10;
    struct1 _1304_y;
    int64_t _1303_t12;
    int64_t _1303_t13;
    int64_t _1303_$retval;
    _1303_t1 = 1;
    _1303_t2 = 2;
    _1303_t3 = 3;
    _1303_t4 = 4;
    _1303_t5 = 5;
    _1304_x = (struct0) {_1303_t1, _1303_t2, _1303_t3, _1303_t4, _1303_t5};
    _1303_t7 = 0;
    _1303_t8 = 5;
    $bounds_check(_1303_t7, _1303_t8, "tests/integration/slices/mut-sliceof.orng:4:29:\n    let y: [mut]Int = [mut]x\n                           ^");
    _1303_t9 = ((int64_t*)&_1304_x + _1303_t7);
    _1303_t10 = 5;
    _1304_y = (struct1) {_1303_t9, _1303_t10};
    _1303_t12 = 2;
    $bounds_check(_1303_t12, _1304_y._1, "tests/integration/slices/mut-sliceof.orng:5:14:\n    y[2] = 81\n            ^");
    *((int64_t*)_1304_y._0 + _1303_t12) = 81;
    _1303_t13 = 2;
    $bounds_check(_1303_t13, _1304_y._1, "tests/integration/slices/mut-sliceof.orng:2:3:\nfn main() -> Int {\n ^");
    _1303_$retval = *((int64_t*)_1304_y._0 + _1303_t13);
    return _1303_$retval;
}

int main(void) {
  printf("%ld",_1303_main());
  return 0;
}
