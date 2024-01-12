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
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1318_main(void);
int64_t _1320_sum_up(struct struct1 _1320_xs);

/* Function definitions */
int64_t _1318_main(void){
    int64_t _1318_t1;
    int64_t _1318_t2;
    int64_t _1318_t3;
    struct struct0 _1319_x;
    int64_t _1318_t5;
    int64_t _1318_t6;
    int64_t* _1318_t7;
    int64_t _1318_t8;
    struct struct1 _1319_y;
    int64_t _1318_t9;
    uint8_t _1318_t10;
    int64_t _1318_t11;
    int64_t* _1318_t12;
    struct struct1 _1319_z;
    function2 _1318_t14;
    int64_t _1318_t15;
    int64_t _1318_$retval;
    _1318_t1 = 100;
    _1318_t2 = 10;
    _1318_t3 = 1;
    _1319_x = (struct struct0) {_1318_t1, _1318_t2, _1318_t3};
    _1318_t5 = 0;
    _1318_t6 = 3;
    $bounds_check(_1318_t5, _1318_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1318_t7 = ((int64_t*)&_1319_x + _1318_t5);
    _1318_t8 = 3;
    _1319_y = (struct struct1) {_1318_t7, _1318_t8};
    _1318_t9 = 0;
    _1318_t10 = _1318_t9>_1319_y._1;
    if (_1318_t10) {
        goto BB1587;
    } else {
        goto BB1588;
    }
BB1587:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1588:
    _1318_t11 = $sub_int64_t(_1319_y._1, _1318_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1318_t12 = _1319_y._0+_1318_t9;
    _1319_z = (struct struct1) {_1318_t12, _1318_t11};
    _1318_t14 = _1320_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1318_t15 = _1318_t14(_1319_z);
    $line_idx--;
    _1318_$retval = _1318_t15;
    return _1318_$retval;
}

int64_t _1320_sum_up(struct struct1 _1320_xs){
    int64_t _1321_sum;
    int64_t _1322_i;
    uint8_t _1320_t3;
    int64_t _1320_t5;
    int64_t _1320_$retval;
    _1321_sum = 0;
    _1322_i = 0;
    goto BB1579;
BB1579:
    _1320_t3 = _1322_i<_1320_xs._1;
    if (_1320_t3) {
        goto BB1580;
    } else {
        goto BB1585;
    }
BB1580:
    $bounds_check(_1322_i, _1320_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1321_sum = $add_int64_t(_1321_sum, *((int64_t*)_1320_xs._0 + _1322_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1320_t5 = 1;
    _1322_i = $add_int64_t(_1322_i, _1320_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1579;
BB1585:
    _1320_$retval = _1321_sum;
    return _1320_$retval;
}

int main(void) {
  printf("%ld",_1318_main());
  return 0;
}
