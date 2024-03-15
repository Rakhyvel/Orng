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
int64_t _1023_main(void);


/* Function definitions */
int64_t _1023_main(void){
    int64_t _1023_t1;
    int64_t _1023_t2;
    int64_t _1023_t3;
    int64_t _1023_t4;
    struct struct0 _1024_x;
    int64_t _1023_t6;
    int64_t _1023_t7;
    int64_t _1023_t8;
    int64_t _1023_t9;
    int64_t _1023_t10;
    int64_t _1023_t11;
    int64_t _1023_t12;
    int64_t _1023_t13;
    int64_t _1023_t14;
    int64_t _1023_t15;
    int64_t _1023_$retval;
    _1023_t1 = 100;
    _1023_t2 = 100;
    _1023_t3 = 3;
    _1023_t4 = 4;
    _1024_x = (struct struct0) {_1023_t1, _1023_t2, _1023_t3, _1023_t4};
    _1023_t6 = 0;
    _1023_t7 = 4;
    _1023_t8 = 1;
    _1023_t9 = 4;
    $bounds_check(_1023_t6, _1023_t7, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_1023_t8, _1023_t9, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1023_t10 = $add_int64_t(*((int64_t*)&_1024_x + _1023_t6), *((int64_t*)&_1024_x + _1023_t8), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1023_t11 = 2;
    _1023_t12 = 4;
    $bounds_check(_1023_t11, _1023_t12, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1023_t13 = $add_int64_t(_1023_t10, *((int64_t*)&_1024_x + _1023_t11), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1023_t14 = 3;
    _1023_t15 = 4;
    $bounds_check(_1023_t14, _1023_t15, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _1023_$retval = $add_int64_t(_1023_t13, *((int64_t*)&_1024_x + _1023_t14), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _1023_$retval;
}


int main(void) {
  printf("%ld",_1023_main());
  return 0;
}
