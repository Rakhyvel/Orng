/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1276_main(void);
int64_t _1278_sum_up(struct1 _1278_xs);

/* Function definitions */
int64_t _1276_main(void){
    int64_t _1276_t1;
    int64_t _1276_t2;
    int64_t _1276_t3;
    struct0 _1277_x;
    int64_t _1276_t5;
    int64_t _1276_t6;
    int64_t* _1276_t7;
    int64_t _1276_t8;
    struct1 _1277_y;
    int64_t _1276_t9;
    uint8_t _1276_t10;
    int64_t _1276_t11;
    int64_t* _1276_t12;
    struct1 _1277_z;
    function2 _1276_t14;
    int64_t _1276_t15;
    int64_t _1276_$retval;
    _1276_t1 = 100;
    _1276_t2 = 10;
    _1276_t3 = 1;
    _1277_x = (struct0) {_1276_t1, _1276_t2, _1276_t3};
    _1276_t5 = 0;
    _1276_t6 = 3;
    $bounds_check(_1276_t5, _1276_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1276_t7 = ((int64_t*)&_1277_x + _1276_t5);
    _1276_t8 = 3;
    _1277_y = (struct1) {_1276_t7, _1276_t8};
    _1276_t9 = 0;
    _1276_t10 = _1276_t9 > _1277_y._1;
    if (_1276_t10) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1276_t11 = $sub_int64_t(_1277_y._1, _1276_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1276_t12 = _1277_y._0 + _1276_t9;
    _1277_z = (struct1) {_1276_t12, _1276_t11};
    _1276_t14 = _1278_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1276_t15 = _1276_t14(_1277_z);
    $line_idx--;
    _1276_$retval = _1276_t15;
    return _1276_$retval;
}

int64_t _1278_sum_up(struct1 _1278_xs){
    int64_t _1279_sum;
    int64_t _1280_i;
    uint8_t _1278_t3;
    int64_t _1278_t5;
    int64_t _1278_$retval;
    _1279_sum = 0;
    _1280_i = 0;
    goto BB1;
BB1:
    _1278_t3 = _1280_i < _1278_xs._1;
    if (_1278_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1280_i, _1278_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1279_sum = $add_int64_t(_1279_sum, *((int64_t*)_1278_xs._0 + _1280_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1278_t5 = 1;
    _1280_i = $add_int64_t(_1280_i, _1278_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1278_$retval = _1279_sum;
    return _1278_$retval;
}

int main(void) {
  printf("%ld",_1276_main());
  return 0;
}
