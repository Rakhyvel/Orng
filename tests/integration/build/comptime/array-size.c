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
int64_t _2_main(void);


/* Function definitions */
int64_t _2_main(void){
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct struct0 _3_x;
    int64_t _2_t9;
    int64_t _2_t10;
    int64_t _2_t14;
    int64_t _2_t15;
    int64_t _2_t19;
    int64_t _2_t20;
    int64_t _2_t24;
    int64_t _2_t25;
    int64_t _2_t26;
    int64_t _2_t27;
    int64_t _2_t28;
    int64_t _2_t29;
    int64_t _2_t30;
    int64_t _2_t31;
    int64_t _2_t32;
    int64_t _2_t33;
    int64_t _2_t34;
    int64_t _2_t35;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _2_t4 = 0;
    _3_x = (struct struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _2_t9 = 3;
    _2_t10 = 4;
    $bounds_check(_2_t9, _2_t10, "tests/integration/comptime/array-size.orng:4:15:\n    x[3] = 0 * 1000\n             ^");
    *((int64_t*)&_3_x + _2_t9) = 0;
    _2_t14 = 2;
    _2_t15 = 4;
    $bounds_check(_2_t14, _2_t15, "tests/integration/comptime/array-size.orng:5:15:\n    x[2] = 2 * 100\n             ^");
    *((int64_t*)&_3_x + _2_t14) = 200;
    _2_t19 = 1;
    _2_t20 = 4;
    $bounds_check(_2_t19, _2_t20, "tests/integration/comptime/array-size.orng:6:15:\n    x[1] = 4 * 10\n             ^");
    *((int64_t*)&_3_x + _2_t19) = 40;
    _2_t24 = 0;
    _2_t25 = 4;
    $bounds_check(_2_t24, _2_t25, "tests/integration/comptime/array-size.orng:7:15:\n    x[0] = 6 * 1\n             ^");
    *((int64_t*)&_3_x + _2_t24) = 6;
    _2_t26 = 0;
    _2_t27 = 4;
    _2_t28 = 1;
    _2_t29 = 4;
    $bounds_check(_2_t26, _2_t27, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_2_t28, _2_t29, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _2_t30 = $add_int64_t(*((int64_t*)&_3_x + _2_t26), *((int64_t*)&_3_x + _2_t28), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _2_t31 = 2;
    _2_t32 = 4;
    $bounds_check(_2_t31, _2_t32, "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _2_t33 = $add_int64_t(_2_t30, *((int64_t*)&_3_x + _2_t31), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _2_t34 = 3;
    _2_t35 = 4;
    $bounds_check(_2_t34, _2_t35, "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _2_$retval = $add_int64_t(_2_t33, *((int64_t*)&_3_x + _2_t34), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _2_$retval;
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
