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
int64_t _1425_main(void);
int64_t _1427_sum_up(struct struct1 _1427_xs);


/* Function definitions */
int64_t _1425_main(void){
    int64_t _1425_t1;
    int64_t _1425_t2;
    int64_t _1425_t3;
    struct struct0 _1426_x;
    int64_t _1425_t6;
    int64_t _1425_t7;
    int64_t* _1425_t8;
    int64_t _1425_t9;
    struct struct1 _1426_y;
    int64_t _1425_t11;
    uint8_t _1425_t12;
    int64_t _1425_t13;
    int64_t* _1425_t14;
    struct struct1 _1426_z;
    function2 _1425_t17;
    int64_t _1425_t18;
    int64_t _1425_$retval;
    _1425_t1 = 100;
    _1425_t2 = 10;
    _1425_t3 = 1;
    _1426_x = (struct struct0) {_1425_t1, _1425_t2, _1425_t3};
    _1425_t6 = 0;
    _1425_t7 = 3;
    $bounds_check(_1425_t6, _1425_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1425_t8 = ((int64_t*)&_1426_x + _1425_t6);
    _1425_t9 = 3;
    _1426_y = (struct struct1) {_1425_t8, _1425_t9};
    _1425_t11 = 0;
    _1425_t12 = _1425_t11>_1426_y._1;
    if (_1425_t12) {
        goto BB1663;
    } else {
        goto BB1664;
    }
BB1663:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1664:
    _1425_t13 = $sub_int64_t(_1426_y._1, _1425_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1425_t14 = _1426_y._0+_1425_t11;
    _1426_z = (struct struct1) {_1425_t14, _1425_t13};
    _1425_t17 = (function2) _1427_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1425_t18 = _1425_t17(_1426_z);
    $line_idx--;
    _1425_$retval = _1425_t18;
    return _1425_$retval;
}

int64_t _1427_sum_up(struct struct1 _1427_xs){
    int64_t _1428_sum;
    int64_t _1429_i;
    uint8_t _1427_t5;
    int64_t _1427_t7;
    int64_t _1427_$retval;
    _1428_sum = 0;
    _1429_i = 0;
    goto BB1655;
BB1655:
    _1427_t5 = _1429_i<_1427_xs._1;
    if (_1427_t5) {
        goto BB1656;
    } else {
        goto BB1661;
    }
BB1656:
    $bounds_check(_1429_i, _1427_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1428_sum = $add_int64_t(_1428_sum, *((int64_t*)_1427_xs._0 + _1429_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1427_t7 = 1;
    _1429_i = $add_int64_t(_1429_i, _1427_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1655;
BB1661:
    _1427_$retval = _1428_sum;
    return _1427_$retval;
}


int main(void) {
  printf("%ld",_1425_main());
  return 0;
}
