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
int64_t _160_add(int64_t _160_a,int64_t _160_b);
int64_t _152_main(void);

/* Function definitions */
int64_t _160_add(int64_t _160_a,int64_t _160_b){
    int64_t _160_$retval;
    _160_$retval = $add_int64_t(_160_a, _160_b, "tests/integration/comptime/array-size.orng:12:36:\nfn add(a: Int, b: Int) -> Int { a + b }\n                                  ^");
    return _160_$retval;
}

int64_t _152_main(void){
    int64_t _152_t1;
    int64_t _152_t2;
    int64_t _152_t3;
    int64_t _152_t4;
    struct0 _153_x;
    int64_t _152_t8;
    int64_t _152_t9;
    int64_t _152_t13;
    int64_t _152_t14;
    int64_t _152_t18;
    int64_t _152_t19;
    int64_t _152_t23;
    int64_t _152_t24;
    int64_t _152_t25;
    int64_t _152_t26;
    int64_t _152_t27;
    int64_t _152_t28;
    int64_t _152_t29;
    int64_t _152_t30;
    int64_t _152_t31;
    int64_t _152_t32;
    int64_t _152_t33;
    int64_t _152_t34;
    int64_t _152_$retval;
    _152_t1 = 0;
    _152_t2 = 0;
    _152_t3 = 0;
    _152_t4 = 0;
    _153_x = (struct0) {_152_t1, _152_t2, _152_t3, _152_t4};
    _152_t8 = 3;
    _152_t9 = 4;
    $bounds_check(_152_t8, _152_t9, "tests/integration/comptime/array-size.orng:4:15:\n    x[3] = 0 * 1000\n             ^");
    *((int64_t*)&_153_x + _152_t8) = 0;
    _152_t13 = 2;
    _152_t14 = 4;
    $bounds_check(_152_t13, _152_t14, "tests/integration/comptime/array-size.orng:5:15:\n    x[2] = 2 * 100\n             ^");
    *((int64_t*)&_153_x + _152_t13) = 200;
    _152_t18 = 1;
    _152_t19 = 4;
    $bounds_check(_152_t18, _152_t19, "tests/integration/comptime/array-size.orng:6:15:\n    x[1] = 4 * 10\n             ^");
    *((int64_t*)&_153_x + _152_t18) = 40;
    _152_t23 = 0;
    _152_t24 = 4;
    $bounds_check(_152_t23, _152_t24, "tests/integration/comptime/array-size.orng:7:15:\n    x[0] = 6 * 1\n             ^");
    *((int64_t*)&_153_x + _152_t23) = 6;
    _152_t25 = 0;
    _152_t26 = 4;
    _152_t27 = 1;
    _152_t28 = 4;
    $bounds_check(_152_t25, _152_t26, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    $bounds_check(_152_t27, _152_t28, "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _152_t29 = $add_int64_t(*((int64_t*)&_153_x + _152_t25), *((int64_t*)&_153_x + _152_t27), "tests/integration/comptime/array-size.orng:9:11:\n    x[0] + x[1] + x[2] + x[3]\n         ^");
    _152_t30 = 2;
    _152_t31 = 4;
    $bounds_check(_152_t30, _152_t31, "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _152_t32 = $add_int64_t(_152_t29, *((int64_t*)&_153_x + _152_t30), "tests/integration/comptime/array-size.orng:9:18:\n    x[0] + x[1] + x[2] + x[3]\n                ^");
    _152_t33 = 3;
    _152_t34 = 4;
    $bounds_check(_152_t33, _152_t34, "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    _152_$retval = $add_int64_t(_152_t32, *((int64_t*)&_153_x + _152_t33), "tests/integration/comptime/array-size.orng:9:25:\n    x[0] + x[1] + x[2] + x[3]\n                       ^");
    return _152_$retval;
}

int main(void) {
  printf("%ld",_152_main());
  return 0;
}
