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
int64_t _1300_main(void);
int64_t _1302_sum_up(struct struct1 _1302_xs);

/* Function definitions */
int64_t _1300_main(void){
    int64_t _1300_t1;
    int64_t _1300_t2;
    int64_t _1300_t3;
    struct struct0 _1301_x;
    int64_t _1300_t5;
    int64_t _1300_t6;
    int64_t* _1300_t7;
    int64_t _1300_t8;
    struct struct1 _1301_y;
    int64_t _1300_t9;
    uint8_t _1300_t10;
    int64_t _1300_t11;
    int64_t* _1300_t12;
    struct struct1 _1301_z;
    function2 _1300_t14;
    int64_t _1300_t15;
    int64_t _1300_$retval;
    _1300_t1 = 100;
    _1300_t2 = 10;
    _1300_t3 = 1;
    _1301_x = (struct struct0) {_1300_t1, _1300_t2, _1300_t3};
    _1300_t5 = 0;
    _1300_t6 = 3;
    $bounds_check(_1300_t5, _1300_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1300_t7 = ((int64_t*)&_1301_x + _1300_t5);
    _1300_t8 = 3;
    _1301_y = (struct struct1) {_1300_t7, _1300_t8};
    _1300_t9 = 0;
    _1300_t10 = _1300_t9>_1301_y._1;
    if (_1300_t10) {
        goto BB1579;
    } else {
        goto BB1580;
    }
BB1579:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1580:
    _1300_t11 = $sub_int64_t(_1301_y._1, _1300_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1300_t12 = _1301_y._0+_1300_t9;
    _1301_z = (struct struct1) {_1300_t12, _1300_t11};
    _1300_t14 = _1302_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1300_t15 = _1300_t14(_1301_z);
    $line_idx--;
    _1300_$retval = _1300_t15;
    return _1300_$retval;
}

int64_t _1302_sum_up(struct struct1 _1302_xs){
    int64_t _1303_sum;
    int64_t _1304_i;
    uint8_t _1302_t3;
    int64_t _1302_t5;
    int64_t _1302_$retval;
    _1303_sum = 0;
    _1304_i = 0;
    goto BB1571;
BB1571:
    _1302_t3 = _1304_i<_1302_xs._1;
    if (_1302_t3) {
        goto BB1572;
    } else {
        goto BB1577;
    }
BB1572:
    $bounds_check(_1304_i, _1302_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1303_sum = $add_int64_t(_1303_sum, *((int64_t*)_1302_xs._0 + _1304_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1302_t5 = 1;
    _1304_i = $add_int64_t(_1304_i, _1302_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1571;
BB1577:
    _1302_$retval = _1303_sum;
    return _1302_$retval;
}

int main(void) {
  printf("%ld",_1300_main());
  return 0;
}
