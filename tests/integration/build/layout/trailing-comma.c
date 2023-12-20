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
int64_t _999_main(void);

/* Function definitions */
int64_t _999_main(void){
    int64_t _999_t1;
    int64_t _999_t2;
    int64_t _999_t3;
    int64_t _999_t4;
    struct0 _1000_x;
    int64_t _999_t5;
    int64_t _999_t6;
    int64_t _999_t7;
    int64_t _999_t8;
    int64_t _999_t9;
    int64_t _999_t10;
    int64_t _999_t11;
    int64_t _999_t12;
    int64_t _999_t13;
    int64_t _999_t14;
    int64_t _999_$retval;
    _999_t1 = 100;
    _999_t2 = 100;
    _999_t3 = 3;
    _999_t4 = 4;
    _1000_x = (struct0) {_999_t1, _999_t2, _999_t3, _999_t4};
    _999_t5 = 0;
    _999_t6 = 4;
    _999_t7 = 1;
    _999_t8 = 4;
    $bounds_check(_999_t5, _999_t6, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_999_t7, _999_t8, "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _999_t9 = $add_int64_t(*((int64_t*)&_1000_x + _999_t5), *((int64_t*)&_1000_x + _999_t7), "tests/integration/layout/trailing-comma.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _999_t10 = 2;
    _999_t11 = 4;
    $bounds_check(_999_t10, _999_t11, "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _999_t12 = $add_int64_t(_999_t9, *((int64_t*)&_1000_x + _999_t10), "tests/integration/layout/trailing-comma.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _999_t13 = 3;
    _999_t14 = 4;
    $bounds_check(_999_t13, _999_t14, "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _999_$retval = $add_int64_t(_999_t12, *((int64_t*)&_1000_x + _999_t13), "tests/integration/layout/trailing-comma.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _999_$retval;
}

int main(void) {
  printf("%ld",_999_main());
  return 0;
}
