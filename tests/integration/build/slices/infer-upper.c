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
int64_t _1428_main(void);
int64_t _1430_sum_up(struct struct1 _1430_xs);


/* Function definitions */
int64_t _1428_main(void){
    int64_t _1428_t1;
    int64_t _1428_t2;
    int64_t _1428_t3;
    int64_t _1428_t4;
    int64_t _1428_t5;
    int64_t _1428_t6;
    struct struct0 _1429_x;
    int64_t _1428_t9;
    int64_t _1428_t10;
    int64_t* _1428_t11;
    int64_t _1428_t12;
    struct struct1 _1429_y;
    int64_t _1428_t14;
    uint8_t _1428_t15;
    int64_t _1428_t16;
    int64_t* _1428_t17;
    struct struct1 _1429_z;
    function2 _1428_t20;
    int64_t _1428_t21;
    int64_t _1428_$retval;
    _1428_t1 = 34;
    _1428_t2 = 25;
    _1428_t3 = 34;
    _1428_t4 = 100;
    _1428_t5 = 8;
    _1428_t6 = 3;
    _1429_x = (struct struct0) {_1428_t1, _1428_t2, _1428_t3, _1428_t4, _1428_t5, _1428_t6};
    _1428_t9 = 0;
    _1428_t10 = 6;
    $bounds_check(_1428_t9, _1428_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1428_t11 = ((int64_t*)&_1429_x + _1428_t9);
    _1428_t12 = 6;
    _1429_y = (struct struct1) {_1428_t11, _1428_t12};
    _1428_t14 = 3;
    _1428_t15 = _1428_t14>_1429_y._1;
    if (_1428_t15) {
        goto BB1674;
    } else {
        goto BB1675;
    }
BB1674:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1675:
    _1428_t16 = $sub_int64_t(_1429_y._1, _1428_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1428_t17 = _1429_y._0+_1428_t14;
    _1429_z = (struct struct1) {_1428_t17, _1428_t16};
    _1428_t20 = (function2) _1430_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1428_t21 = _1428_t20(_1429_z);
    $line_idx--;
    _1428_$retval = _1428_t21;
    return _1428_$retval;
}

int64_t _1430_sum_up(struct struct1 _1430_xs){
    int64_t _1431_sum;
    int64_t _1432_i;
    uint8_t _1430_t5;
    int64_t _1430_t7;
    int64_t _1430_$retval;
    _1431_sum = 0;
    _1432_i = 0;
    goto BB1666;
BB1666:
    _1430_t5 = _1432_i<_1430_xs._1;
    if (_1430_t5) {
        goto BB1667;
    } else {
        goto BB1672;
    }
BB1667:
    $bounds_check(_1432_i, _1430_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1431_sum = $add_int64_t(_1431_sum, *((int64_t*)_1430_xs._0 + _1432_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1430_t7 = 1;
    _1432_i = $add_int64_t(_1432_i, _1430_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1666;
BB1672:
    _1430_$retval = _1431_sum;
    return _1430_$retval;
}


int main(void) {
  printf("%ld",_1428_main());
  return 0;
}
