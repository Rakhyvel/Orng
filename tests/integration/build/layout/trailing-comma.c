/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

/* Function forward definitions */
int64_t _1012_main(void);

/* Function definitions */
int64_t _1012_main(void){
    int64_t _1012_t1;
    int64_t _1012_t2;
    int64_t _1012_t3;
    int64_t _1012_t4;
    struct struct0 _1013_x;
    int64_t _1012_t5;
    int64_t _1012_t6;
    int64_t _1012_t7;
    int64_t _1012_t8;
    int64_t _1012_t9;
    int64_t _1012_t10;
    int64_t _1012_t11;
    int64_t _1012_t12;
    int64_t _1012_t13;
    int64_t _1012_t14;
    int64_t _1012_$retval;
    _1012_t1 = 100;
    _1012_t2 = 100;
    _1012_t3 = 3;
    _1012_t4 = 4;
    _1013_x = (struct struct0) {_1012_t1, _1012_t2, _1012_t3, _1012_t4};
    _1012_t5 = 0;
    _1012_t6 = 4;
    _1012_t7 = 1;
    _1012_t8 = 4;
    $bounds_check(_1012_t5, _1012_t6, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_1012_t7, _1012_t8, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1012_t9 = $add_int64_t(*((int64_t*)&_1013_x + _1012_t5), *((int64_t*)&_1013_x + _1012_t7), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1012_t10 = 2;
    _1012_t11 = 4;
    $bounds_check(_1012_t10, _1012_t11, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1012_t12 = $add_int64_t(_1012_t9, *((int64_t*)&_1013_x + _1012_t10), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1012_t13 = 3;
    _1012_t14 = 4;
    $bounds_check(_1012_t13, _1012_t14, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _1012_$retval = $add_int64_t(_1012_t12, *((int64_t*)&_1013_x + _1012_t13), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _1012_$retval;
}

int main(void) {
  printf("%ld",_1012_main());
  return 0;
}
