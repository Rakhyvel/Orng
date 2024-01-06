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
int64_t _1308_main(void);
int64_t _1310_sum_up(struct struct1 _1310_xs);

/* Function definitions */
int64_t _1308_main(void){
    int64_t _1308_t1;
    int64_t _1308_t2;
    int64_t _1308_t3;
    struct struct0 _1309_x;
    int64_t _1308_t5;
    int64_t _1308_t6;
    int64_t* _1308_t7;
    int64_t _1308_t8;
    struct struct1 _1309_y;
    int64_t _1308_t9;
    uint8_t _1308_t10;
    int64_t _1308_t11;
    int64_t* _1308_t12;
    struct struct1 _1309_z;
    function2 _1308_t14;
    int64_t _1308_t15;
    int64_t _1308_$retval;
    _1308_t1 = 100;
    _1308_t2 = 10;
    _1308_t3 = 1;
    _1309_x = (struct struct0) {_1308_t1, _1308_t2, _1308_t3};
    _1308_t5 = 0;
    _1308_t6 = 3;
    $bounds_check(_1308_t5, _1308_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1308_t7 = ((int64_t*)&_1309_x + _1308_t5);
    _1308_t8 = 3;
    _1309_y = (struct struct1) {_1308_t7, _1308_t8};
    _1308_t9 = 0;
    _1308_t10 = _1308_t9>_1309_y._1;
    if (_1308_t10) {
        goto BB1575;
    } else {
        goto BB1576;
    }
BB1575:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1576:
    _1308_t11 = $sub_int64_t(_1309_y._1, _1308_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1308_t12 = _1309_y._0+_1308_t9;
    _1309_z = (struct struct1) {_1308_t12, _1308_t11};
    _1308_t14 = _1310_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1308_t15 = _1308_t14(_1309_z);
    $line_idx--;
    _1308_$retval = _1308_t15;
    return _1308_$retval;
}

int64_t _1310_sum_up(struct struct1 _1310_xs){
    int64_t _1311_sum;
    int64_t _1312_i;
    uint8_t _1310_t3;
    int64_t _1310_t5;
    int64_t _1310_$retval;
    _1311_sum = 0;
    _1312_i = 0;
    goto BB1567;
BB1567:
    _1310_t3 = _1312_i<_1310_xs._1;
    if (_1310_t3) {
        goto BB1568;
    } else {
        goto BB1573;
    }
BB1568:
    $bounds_check(_1312_i, _1310_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1311_sum = $add_int64_t(_1311_sum, *((int64_t*)_1310_xs._0 + _1312_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1310_t5 = 1;
    _1312_i = $add_int64_t(_1312_i, _1310_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1567;
BB1573:
    _1310_$retval = _1311_sum;
    return _1310_$retval;
}

int main(void) {
  printf("%ld",_1308_main());
  return 0;
}
