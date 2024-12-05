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
    int64_t _3;
    int64_t _4;
    int64_t _5;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1422_main(void);
int64_t _1424_sum_up(struct struct1 _1424_xs);


/* Function definitions */
int64_t _1422_main(void){
    int64_t _1422_t1;
    int64_t _1422_t2;
    int64_t _1422_t3;
    int64_t _1422_t4;
    int64_t _1422_t5;
    int64_t _1422_t6;
    struct struct0 _1423_x;
    int64_t _1422_t9;
    int64_t _1422_t10;
    int64_t* _1422_t11;
    int64_t _1422_t12;
    struct struct1 _1423_y;
    int64_t _1422_t14;
    uint8_t _1422_t15;
    int64_t _1422_t16;
    int64_t* _1422_t17;
    struct struct1 _1423_z;
    function2 _1422_t20;
    int64_t _1422_t21;
    int64_t _1422_$retval;
    _1422_t1 = 34;
    _1422_t2 = 25;
    _1422_t3 = 34;
    _1422_t4 = 100;
    _1422_t5 = 8;
    _1422_t6 = 3;
    _1423_x = (struct struct0) {_1422_t1, _1422_t2, _1422_t3, _1422_t4, _1422_t5, _1422_t6};
    _1422_t9 = 0;
    _1422_t10 = 6;
    $bounds_check(_1422_t9, _1422_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1422_t11 = ((int64_t*)&_1423_x + _1422_t9);
    _1422_t12 = 6;
    _1423_y = (struct struct1) {_1422_t11, _1422_t12};
    _1422_t14 = 3;
    _1422_t15 = _1422_t14>_1423_y._1;
    if (_1422_t15) {
        goto BB1665;
    } else {
        goto BB1666;
    }
BB1665:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1666:
    _1422_t16 = $sub_int64_t(_1423_y._1, _1422_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1422_t17 = _1423_y._0+_1422_t14;
    _1423_z = (struct struct1) {_1422_t17, _1422_t16};
    _1422_t20 = (function2) _1424_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1422_t21 = _1422_t20(_1423_z);
    $line_idx--;
    _1422_$retval = _1422_t21;
    return _1422_$retval;
}

int64_t _1424_sum_up(struct struct1 _1424_xs){
    int64_t _1425_sum;
    int64_t _1426_i;
    uint8_t _1424_t5;
    int64_t _1424_t7;
    int64_t _1424_$retval;
    _1425_sum = 0;
    _1426_i = 0;
    goto BB1657;
BB1657:
    _1424_t5 = _1426_i<_1424_xs._1;
    if (_1424_t5) {
        goto BB1658;
    } else {
        goto BB1663;
    }
BB1658:
    $bounds_check(_1426_i, _1424_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1425_sum = $add_int64_t(_1425_sum, *((int64_t*)_1424_xs._0 + _1426_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1424_t7 = 1;
    _1426_i = $add_int64_t(_1426_i, _1424_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1657;
BB1663:
    _1424_$retval = _1425_sum;
    return _1424_$retval;
}


int main(void) {
  printf("%ld",_1422_main());
  return 0;
}
