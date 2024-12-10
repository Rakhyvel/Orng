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
int64_t _93_main(void);


/* Function definitions */
int64_t _93_main(void){
    int64_t _93_t1;
    int64_t _93_t2;
    int64_t _93_t3;
    int64_t _93_t4;
    struct struct0 _94_x;
    int64_t _93_t9;
    int64_t _93_t10;
    int64_t _93_t14;
    int64_t _93_t15;
    int64_t _93_t19;
    int64_t _93_t20;
    int64_t _93_t24;
    int64_t _93_t25;
    int64_t _93_t26;
    int64_t _93_t27;
    int64_t _93_t28;
    int64_t _93_t29;
    int64_t _93_t30;
    int64_t _93_t31;
    int64_t _93_t32;
    int64_t _93_t33;
    int64_t _93_t34;
    int64_t _93_t35;
    int64_t _93_$retval;
    _93_t1 = 0;
    _93_t2 = 0;
    _93_t3 = 0;
    _93_t4 = 0;
    _94_x = (struct struct0) {_93_t1, _93_t2, _93_t3, _93_t4};
    _93_t9 = 3;
    _93_t10 = 4;
    $bounds_check(_93_t9, _93_t10, "tests/integration/comptime/array-size.orng:4:15:\n    x[3] = 0 * 1000\n             ^");
    *((int64_t*)&_94_x + _93_t9) = 0;
    _93_t14 = 2;
    _93_t15 = 4;
    $bounds_check(_93_t14, _93_t15, "tests/integration/comptime/array-size.orng:5:15:\n    x[2] = 2 * 100\n             ^");
    *((int64_t*)&_94_x + _93_t14) = 200;
    _93_t19 = 1;
    _93_t20 = 4;
    $bounds_check(_93_t19, _93_t20, "tests/integration/comptime/array-size.orng:6:15:\n    x[1] = 4 * 10\n             ^");
    *((int64_t*)&_94_x + _93_t19) = 40;
    _93_t24 = 0;
    _93_t25 = 4;
    $bounds_check(_93_t24, _93_t25, "tests/integration/comptime/array-size.orng:7:15:\n    x[0] = 6 * 1\n             ^");
    *((int64_t*)&_94_x + _93_t24) = 6;
    _93_t26 = 0;
    _93_t27 = 4;
    _93_t28 = 1;
    _93_t29 = 4;
    $bounds_check(_93_t26, _93_t27, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_93_t28, _93_t29, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _93_t30 = $add_int64_t(*((int64_t*)&_94_x + _93_t26), *((int64_t*)&_94_x + _93_t28), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _93_t31 = 2;
    _93_t32 = 4;
    $bounds_check(_93_t31, _93_t32, "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _93_t33 = $add_int64_t(_93_t30, *((int64_t*)&_94_x + _93_t31), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _93_t34 = 3;
    _93_t35 = 4;
    $bounds_check(_93_t34, _93_t35, "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _93_$retval = $add_int64_t(_93_t33, *((int64_t*)&_94_x + _93_t34), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _93_$retval;
}


int main(void) {
  printf("%ld",_93_main());
  return 0;
}
