/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1319_main(void);
int64_t _1321_sum_up(struct struct1 _1321_xs);

/* Function definitions */
int64_t _1319_main(void){
    int64_t _1319_t1;
    int64_t _1319_t2;
    int64_t _1319_t3;
    int64_t _1319_t4;
    int64_t _1319_t5;
    int64_t _1319_t6;
    struct struct0 _1320_x;
    int64_t _1319_t8;
    int64_t _1319_t9;
    int64_t* _1319_t10;
    int64_t _1319_t11;
    struct struct1 _1320_y;
    int64_t _1319_t12;
    uint8_t _1319_t13;
    int64_t _1319_t14;
    int64_t* _1319_t15;
    struct struct1 _1320_z;
    function2 _1319_t17;
    int64_t _1319_t18;
    int64_t _1319_$retval;
    _1319_t1 = 34;
    _1319_t2 = 25;
    _1319_t3 = 34;
    _1319_t4 = 100;
    _1319_t5 = 8;
    _1319_t6 = 3;
    _1320_x = (struct struct0) {_1319_t1, _1319_t2, _1319_t3, _1319_t4, _1319_t5, _1319_t6};
    _1319_t8 = 0;
    _1319_t9 = 6;
    $bounds_check(_1319_t8, _1319_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1319_t10 = ((int64_t*)&_1320_x + _1319_t8);
    _1319_t11 = 6;
    _1320_y = (struct struct1) {_1319_t10, _1319_t11};
    _1319_t12 = 3;
    _1319_t13 = _1319_t12>_1320_y._1;
    if (_1319_t13) {
        goto BB1595;
    } else {
        goto BB1596;
    }
BB1595:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1596:
    _1319_t14 = $sub_int64_t(_1320_y._1, _1319_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1319_t15 = _1320_y._0+_1319_t12;
    _1320_z = (struct struct1) {_1319_t15, _1319_t14};
    _1319_t17 = _1321_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1319_t18 = _1319_t17(_1320_z);
    $line_idx--;
    _1319_$retval = _1319_t18;
    return _1319_$retval;
}

int64_t _1321_sum_up(struct struct1 _1321_xs){
    int64_t _1322_sum;
    int64_t _1323_i;
    uint8_t _1321_t3;
    int64_t _1321_t5;
    int64_t _1321_$retval;
    _1322_sum = 0;
    _1323_i = 0;
    goto BB1587;
BB1587:
    _1321_t3 = _1323_i<_1321_xs._1;
    if (_1321_t3) {
        goto BB1588;
    } else {
        goto BB1593;
    }
BB1588:
    $bounds_check(_1323_i, _1321_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1322_sum = $add_int64_t(_1322_sum, *((int64_t*)_1321_xs._0 + _1323_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1321_t5 = 1;
    _1323_i = $add_int64_t(_1323_i, _1321_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1587;
BB1593:
    _1321_$retval = _1322_sum;
    return _1321_$retval;
}

int main(void) {
  printf("%ld",_1319_main());
  return 0;
}
