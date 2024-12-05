/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1406_main(void);
int64_t _1408_sum_up(struct struct1 _1408_xs);


/* Function definitions */
int64_t _1406_main(void){
    int64_t _1406_t1;
    int64_t _1406_t2;
    int64_t _1406_t3;
    struct struct0 _1407_x;
    int64_t _1406_t6;
    int64_t _1406_t7;
    int64_t* _1406_t8;
    int64_t _1406_t9;
    struct struct1 _1407_y;
    int64_t _1406_t11;
    uint8_t _1406_t12;
    int64_t _1406_t13;
    int64_t* _1406_t14;
    struct struct1 _1407_z;
    function2 _1406_t17;
    int64_t _1406_t18;
    int64_t _1406_$retval;
    _1406_t1 = 100;
    _1406_t2 = 10;
    _1406_t3 = 1;
    _1407_x = (struct struct0) {_1406_t1, _1406_t2, _1406_t3};
    _1406_t6 = 0;
    _1406_t7 = 3;
    $bounds_check(_1406_t6, _1406_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1406_t8 = ((int64_t*)&_1407_x + _1406_t6);
    _1406_t9 = 3;
    _1407_y = (struct struct1) {_1406_t8, _1406_t9};
    _1406_t11 = 0;
    _1406_t12 = _1406_t11>_1407_y._1;
    if (_1406_t12) {
        goto BB1641;
    } else {
        goto BB1642;
    }
BB1641:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1642:
    _1406_t13 = $sub_int64_t(_1407_y._1, _1406_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1406_t14 = _1407_y._0+_1406_t11;
    _1407_z = (struct struct1) {_1406_t14, _1406_t13};
    _1406_t17 = (function2) _1408_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1406_t18 = _1406_t17(_1407_z);
    $line_idx--;
    _1406_$retval = _1406_t18;
    return _1406_$retval;
}

int64_t _1408_sum_up(struct struct1 _1408_xs){
    int64_t _1409_sum;
    int64_t _1410_i;
    uint8_t _1408_t5;
    int64_t _1408_t7;
    int64_t _1408_$retval;
    _1409_sum = 0;
    _1410_i = 0;
    goto BB1633;
BB1633:
    _1408_t5 = _1410_i<_1408_xs._1;
    if (_1408_t5) {
        goto BB1634;
    } else {
        goto BB1639;
    }
BB1634:
    $bounds_check(_1410_i, _1408_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1409_sum = $add_int64_t(_1409_sum, *((int64_t*)_1408_xs._0 + _1410_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1408_t7 = 1;
    _1410_i = $add_int64_t(_1410_i, _1408_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1633;
BB1639:
    _1408_$retval = _1409_sum;
    return _1408_$retval;
}


int main(void) {
  printf("%ld",_1406_main());
  return 0;
}
