/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

/* Function forward definitions */
int64_t _1057_main(void);


/* Function definitions */
int64_t _1057_main(void){
    int64_t _1057_t1;
    int64_t _1057_t2;
    int64_t _1057_t3;
    int64_t _1057_t4;
    struct struct0 _1058_x;
    int64_t _1057_t5;
    int64_t _1057_t6;
    int64_t _1057_t7;
    int64_t _1057_t8;
    int64_t _1057_t9;
    int64_t _1057_t10;
    int64_t _1057_t11;
    int64_t _1057_t12;
    int64_t _1057_t13;
    int64_t _1057_t14;
    int64_t _1057_$retval;
    _1057_t1 = 100;
    _1057_t2 = 100;
    _1057_t3 = 3;
    _1057_t4 = 4;
    _1058_x = (struct struct0) {_1057_t1, _1057_t2, _1057_t3, _1057_t4};
    _1057_t5 = 0;
    _1057_t6 = 4;
    _1057_t7 = 1;
    _1057_t8 = 4;
    $bounds_check(_1057_t5, _1057_t6, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_1057_t7, _1057_t8, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1057_t9 = $add_int64_t(*((int64_t*)&_1058_x + _1057_t5), *((int64_t*)&_1058_x + _1057_t7), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1057_t10 = 2;
    _1057_t11 = 4;
    $bounds_check(_1057_t10, _1057_t11, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1057_t12 = $add_int64_t(_1057_t9, *((int64_t*)&_1058_x + _1057_t10), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1057_t13 = 3;
    _1057_t14 = 4;
    $bounds_check(_1057_t13, _1057_t14, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _1057_$retval = $add_int64_t(_1057_t12, *((int64_t*)&_1058_x + _1057_t13), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _1057_$retval;
}


int main(void) {
  printf("%ld",_1057_main());
  return 0;
}
