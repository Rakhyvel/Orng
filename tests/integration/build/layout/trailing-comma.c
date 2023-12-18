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
} struct0;

/* Function forward definitions */
int64_t _1129_main(void);

/* Function definitions */
int64_t _1129_main(void){
    int64_t _1129_t1;
    int64_t _1129_t2;
    int64_t _1129_t3;
    int64_t _1129_t4;
    struct0 _1130_x;
    int64_t _1129_t5;
    int64_t _1129_t6;
    int64_t _1129_t7;
    int64_t _1129_t8;
    int64_t _1129_t9;
    int64_t _1129_t10;
    int64_t _1129_t11;
    int64_t _1129_t12;
    int64_t _1129_t13;
    int64_t _1129_t14;
    int64_t _1129_$retval;
    _1129_t1 = 100;
    _1129_t2 = 100;
    _1129_t3 = 3;
    _1129_t4 = 4;
    _1130_x = (struct0) {_1129_t1, _1129_t2, _1129_t3, _1129_t4};
    _1129_t5 = 0;
    _1129_t6 = 4;
    _1129_t7 = 1;
    _1129_t8 = 4;
    $bounds_check(_1129_t5, _1129_t6, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_1129_t7, _1129_t8, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1129_t9 = $add_int64_t(*((int64_t*)&_1130_x + _1129_t5), *((int64_t*)&_1130_x + _1129_t7), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _1129_t10 = 2;
    _1129_t11 = 4;
    $bounds_check(_1129_t10, _1129_t11, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1129_t12 = $add_int64_t(_1129_t9, *((int64_t*)&_1130_x + _1129_t10), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _1129_t13 = 3;
    _1129_t14 = 4;
    $bounds_check(_1129_t13, _1129_t14, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _1129_$retval = $add_int64_t(_1129_t12, *((int64_t*)&_1130_x + _1129_t13), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _1129_$retval;
}

int main(void) {
  printf("%ld",_1129_main());
  return 0;
}
