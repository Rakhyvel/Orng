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
int64_t _1349_main(void);
int64_t _1351_sum_up(struct struct1 _1351_xs);


/* Function definitions */
int64_t _1349_main(void){
    int64_t _1349_t1;
    int64_t _1349_t2;
    int64_t _1349_t3;
    int64_t _1349_t4;
    int64_t _1349_t5;
    int64_t _1349_t6;
    struct struct0 _1350_x;
    int64_t _1349_t9;
    int64_t _1349_t10;
    int64_t* _1349_t11;
    int64_t _1349_t12;
    struct struct1 _1350_y;
    int64_t _1349_t14;
    uint8_t _1349_t15;
    int64_t _1349_t16;
    int64_t* _1349_t17;
    struct struct1 _1350_z;
    function2 _1349_t20;
    int64_t _1349_t21;
    int64_t _1349_$retval;
    _1349_t1 = 34;
    _1349_t2 = 25;
    _1349_t3 = 34;
    _1349_t4 = 100;
    _1349_t5 = 8;
    _1349_t6 = 3;
    _1350_x = (struct struct0) {_1349_t1, _1349_t2, _1349_t3, _1349_t4, _1349_t5, _1349_t6};
    _1349_t9 = 0;
    _1349_t10 = 6;
    $bounds_check(_1349_t9, _1349_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1349_t11 = ((int64_t*)&_1350_x + _1349_t9);
    _1349_t12 = 6;
    _1350_y = (struct struct1) {_1349_t11, _1349_t12};
    _1349_t14 = 3;
    _1349_t15 = _1349_t14>_1350_y._1;
    if (_1349_t15) {
        goto BB1588;
    } else {
        goto BB1589;
    }
BB1588:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1589:
    _1349_t16 = $sub_int64_t(_1350_y._1, _1349_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1349_t17 = _1350_y._0+_1349_t14;
    _1350_z = (struct struct1) {_1349_t17, _1349_t16};
    _1349_t20 = (function2) _1351_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1349_t21 = _1349_t20(_1350_z);
    $line_idx--;
    _1349_$retval = _1349_t21;
    return _1349_$retval;
}

int64_t _1351_sum_up(struct struct1 _1351_xs){
    int64_t _1352_sum;
    int64_t _1353_i;
    uint8_t _1351_t5;
    int64_t _1351_t7;
    int64_t _1351_$retval;
    _1352_sum = 0;
    _1353_i = 0;
    goto BB1580;
BB1580:
    _1351_t5 = _1353_i<_1351_xs._1;
    if (_1351_t5) {
        goto BB1581;
    } else {
        goto BB1586;
    }
BB1581:
    $bounds_check(_1353_i, _1351_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1352_sum = $add_int64_t(_1352_sum, *((int64_t*)_1351_xs._0 + _1353_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1351_t7 = 1;
    _1353_i = $add_int64_t(_1353_i, _1351_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1580;
BB1586:
    _1351_$retval = _1352_sum;
    return _1351_$retval;
}


int main(void) {
  printf("%ld",_1349_main());
  return 0;
}
