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
int64_t _1458_main(void);
int64_t _1460_sum_up(struct struct1 _1460_xs);


/* Function definitions */
int64_t _1458_main(void){
    int64_t _1458_t1;
    int64_t _1458_t2;
    int64_t _1458_t3;
    int64_t _1458_t4;
    int64_t _1458_t5;
    int64_t _1458_t6;
    struct struct0 _1459_x;
    int64_t _1458_t9;
    int64_t _1458_t10;
    int64_t* _1458_t11;
    int64_t _1458_t12;
    struct struct1 _1459_y;
    int64_t _1458_t14;
    uint8_t _1458_t15;
    int64_t _1458_t16;
    int64_t* _1458_t17;
    struct struct1 _1459_z;
    function2 _1458_t20;
    int64_t _1458_t21;
    int64_t _1458_$retval;
    _1458_t1 = 34;
    _1458_t2 = 25;
    _1458_t3 = 34;
    _1458_t4 = 100;
    _1458_t5 = 8;
    _1458_t6 = 3;
    _1459_x = (struct struct0) {_1458_t1, _1458_t2, _1458_t3, _1458_t4, _1458_t5, _1458_t6};
    _1458_t9 = 0;
    _1458_t10 = 6;
    $bounds_check(_1458_t9, _1458_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1458_t11 = ((int64_t*)&_1459_x + _1458_t9);
    _1458_t12 = 6;
    _1459_y = (struct struct1) {_1458_t11, _1458_t12};
    _1458_t14 = 3;
    _1458_t15 = _1458_t14>_1459_y._1;
    if (_1458_t15) {
        goto BB1705;
    } else {
        goto BB1706;
    }
BB1705:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1706:
    _1458_t16 = $sub_int64_t(_1459_y._1, _1458_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1458_t17 = _1459_y._0+_1458_t14;
    _1459_z = (struct struct1) {_1458_t17, _1458_t16};
    _1458_t20 = (function2) _1460_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1458_t21 = _1458_t20(_1459_z);
    $line_idx--;
    _1458_$retval = _1458_t21;
    return _1458_$retval;
}

int64_t _1460_sum_up(struct struct1 _1460_xs){
    int64_t _1461_sum;
    int64_t _1462_i;
    uint8_t _1460_t5;
    int64_t _1460_t7;
    int64_t _1460_$retval;
    _1461_sum = 0;
    _1462_i = 0;
    goto BB1697;
BB1697:
    _1460_t5 = _1462_i<_1460_xs._1;
    if (_1460_t5) {
        goto BB1698;
    } else {
        goto BB1703;
    }
BB1698:
    $bounds_check(_1462_i, _1460_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1461_sum = $add_int64_t(_1461_sum, *((int64_t*)_1460_xs._0 + _1462_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1460_t7 = 1;
    _1462_i = $add_int64_t(_1462_i, _1460_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1697;
BB1703:
    _1460_$retval = _1461_sum;
    return _1460_$retval;
}


int main(void) {
  printf("%ld",_1458_main());
  return 0;
}
