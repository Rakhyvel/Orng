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
int64_t _1436_main(void);
int64_t _1438_sum_up(struct struct1 _1438_xs);


/* Function definitions */
int64_t _1436_main(void){
    int64_t _1436_t1;
    int64_t _1436_t2;
    int64_t _1436_t3;
    int64_t _1436_t4;
    int64_t _1436_t5;
    int64_t _1436_t6;
    struct struct0 _1437_x;
    int64_t _1436_t9;
    int64_t _1436_t10;
    int64_t* _1436_t11;
    int64_t _1436_t12;
    struct struct1 _1437_y;
    int64_t _1436_t14;
    uint8_t _1436_t15;
    int64_t _1436_t16;
    int64_t* _1436_t17;
    struct struct1 _1437_z;
    function2 _1436_t20;
    int64_t _1436_t21;
    int64_t _1436_$retval;
    _1436_t1 = 34;
    _1436_t2 = 25;
    _1436_t3 = 34;
    _1436_t4 = 100;
    _1436_t5 = 8;
    _1436_t6 = 3;
    _1437_x = (struct struct0) {_1436_t1, _1436_t2, _1436_t3, _1436_t4, _1436_t5, _1436_t6};
    _1436_t9 = 0;
    _1436_t10 = 6;
    $bounds_check(_1436_t9, _1436_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1436_t11 = ((int64_t*)&_1437_x + _1436_t9);
    _1436_t12 = 6;
    _1437_y = (struct struct1) {_1436_t11, _1436_t12};
    _1436_t14 = 3;
    _1436_t15 = _1436_t14>_1437_y._1;
    if (_1436_t15) {
        goto BB1684;
    } else {
        goto BB1685;
    }
BB1684:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1685:
    _1436_t16 = $sub_int64_t(_1437_y._1, _1436_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1436_t17 = _1437_y._0+_1436_t14;
    _1437_z = (struct struct1) {_1436_t17, _1436_t16};
    _1436_t20 = (function2) _1438_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1436_t21 = _1436_t20(_1437_z);
    $line_idx--;
    _1436_$retval = _1436_t21;
    return _1436_$retval;
}

int64_t _1438_sum_up(struct struct1 _1438_xs){
    int64_t _1439_sum;
    int64_t _1440_i;
    uint8_t _1438_t5;
    int64_t _1438_t7;
    int64_t _1438_$retval;
    _1439_sum = 0;
    _1440_i = 0;
    goto BB1676;
BB1676:
    _1438_t5 = _1440_i<_1438_xs._1;
    if (_1438_t5) {
        goto BB1677;
    } else {
        goto BB1682;
    }
BB1677:
    $bounds_check(_1440_i, _1438_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1439_sum = $add_int64_t(_1439_sum, *((int64_t*)_1438_xs._0 + _1440_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1438_t7 = 1;
    _1440_i = $add_int64_t(_1440_i, _1438_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1676;
BB1682:
    _1438_$retval = _1439_sum;
    return _1438_$retval;
}


int main(void) {
  printf("%ld",_1436_main());
  return 0;
}
