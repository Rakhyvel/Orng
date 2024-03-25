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
int64_t _1032_main(void);


/* Function definitions */
int64_t _1032_main(void){
    int64_t _1032_t1;
    int64_t _1032_t2;
    int64_t _1032_t3;
    int64_t _1032_t4;
    struct struct0 _1033_x;
    int64_t _1032_t6;
    int64_t _1032_t7;
    int64_t _1032_t8;
    int64_t _1032_t9;
    int64_t _1032_t10;
    int64_t _1032_t11;
    int64_t _1032_t12;
    int64_t _1032_t13;
    int64_t _1032_t14;
    int64_t _1032_t15;
    int64_t _1032_$retval;
    _1032_t1 = 100;
    _1032_t2 = 100;
    _1032_t3 = 3;
    _1032_t4 = 4;
    _1033_x = (struct struct0) {_1032_t1, _1032_t2, _1032_t3, _1032_t4};
    _1032_t6 = 0;
    _1032_t7 = 4;
    _1032_t8 = 1;
    _1032_t9 = 4;
    $bounds_check(_1032_t6, _1032_t7, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_1032_t8, _1032_t9, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1032_t10 = $add_int64_t(*((int64_t*)&_1033_x + _1032_t6), *((int64_t*)&_1033_x + _1032_t8), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1032_t11 = 2;
    _1032_t12 = 4;
    $bounds_check(_1032_t11, _1032_t12, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1032_t13 = $add_int64_t(_1032_t10, *((int64_t*)&_1033_x + _1032_t11), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1032_t14 = 3;
    _1032_t15 = 4;
    $bounds_check(_1032_t14, _1032_t15, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _1032_$retval = $add_int64_t(_1032_t13, *((int64_t*)&_1033_x + _1032_t14), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _1032_$retval;
}


int main(void) {
  printf("%ld",_1032_main());
  return 0;
}
