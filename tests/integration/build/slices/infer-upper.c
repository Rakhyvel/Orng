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
int64_t _1417_main(void);
int64_t _1419_sum_up(struct struct1 _1419_xs);


/* Function definitions */
int64_t _1417_main(void){
    int64_t _1417_t1;
    int64_t _1417_t2;
    int64_t _1417_t3;
    int64_t _1417_t4;
    int64_t _1417_t5;
    int64_t _1417_t6;
    struct struct0 _1418_x;
    int64_t _1417_t9;
    int64_t _1417_t10;
    int64_t* _1417_t11;
    int64_t _1417_t12;
    struct struct1 _1418_y;
    int64_t _1417_t14;
    uint8_t _1417_t15;
    int64_t _1417_t16;
    int64_t* _1417_t17;
    struct struct1 _1418_z;
    function2 _1417_t20;
    int64_t _1417_t21;
    int64_t _1417_$retval;
    _1417_t1 = 34;
    _1417_t2 = 25;
    _1417_t3 = 34;
    _1417_t4 = 100;
    _1417_t5 = 8;
    _1417_t6 = 3;
    _1418_x = (struct struct0) {_1417_t1, _1417_t2, _1417_t3, _1417_t4, _1417_t5, _1417_t6};
    _1417_t9 = 0;
    _1417_t10 = 6;
    $bounds_check(_1417_t9, _1417_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1417_t11 = ((int64_t*)&_1418_x + _1417_t9);
    _1417_t12 = 6;
    _1418_y = (struct struct1) {_1417_t11, _1417_t12};
    _1417_t14 = 3;
    _1417_t15 = _1417_t14>_1418_y._1;
    if (_1417_t15) {
        goto BB1661;
    } else {
        goto BB1662;
    }
BB1661:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1662:
    _1417_t16 = $sub_int64_t(_1418_y._1, _1417_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1417_t17 = _1418_y._0+_1417_t14;
    _1418_z = (struct struct1) {_1417_t17, _1417_t16};
    _1417_t20 = (function2) _1419_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1417_t21 = _1417_t20(_1418_z);
    $line_idx--;
    _1417_$retval = _1417_t21;
    return _1417_$retval;
}

int64_t _1419_sum_up(struct struct1 _1419_xs){
    int64_t _1420_sum;
    int64_t _1421_i;
    uint8_t _1419_t5;
    int64_t _1419_t7;
    int64_t _1419_$retval;
    _1420_sum = 0;
    _1421_i = 0;
    goto BB1653;
BB1653:
    _1419_t5 = _1421_i<_1419_xs._1;
    if (_1419_t5) {
        goto BB1654;
    } else {
        goto BB1659;
    }
BB1654:
    $bounds_check(_1421_i, _1419_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1420_sum = $add_int64_t(_1420_sum, *((int64_t*)_1419_xs._0 + _1421_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1419_t7 = 1;
    _1421_i = $add_int64_t(_1421_i, _1419_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1653;
BB1659:
    _1419_$retval = _1420_sum;
    return _1419_$retval;
}


int main(void) {
  printf("%ld",_1417_main());
  return 0;
}
