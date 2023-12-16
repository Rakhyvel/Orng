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
    int64_t _3;
    int64_t _4;
    int64_t _5;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1280_main(void);
int64_t _1285_sum_up(struct1 _1285_xs);

/* Function definitions */
int64_t _1280_main(void){
    int64_t _1280_t1;
    int64_t _1280_t2;
    int64_t _1280_t3;
    int64_t _1280_t4;
    int64_t _1280_t5;
    int64_t _1280_t6;
    struct0 _1281_x;
    int64_t _1280_t8;
    int64_t* _1280_t9;
    int64_t _1280_t10;
    struct1 _1281_y;
    int64_t _1280_t11;
    uint8_t _1280_t12;
    int64_t _1280_t13;
    int64_t* _1280_t14;
    struct1 _1281_z;
    function2 _1280_t16;
    int64_t _1280_t17;
    int64_t _1280_$retval;
    _1280_t1 = 34;
    _1280_t2 = 25;
    _1280_t3 = 34;
    _1280_t4 = 100;
    _1280_t5 = 8;
    _1280_t6 = 3;
    _1281_x = (struct0) {_1280_t1, _1280_t2, _1280_t3, _1280_t4, _1280_t5, _1280_t6};
    _1280_t8 = 0;
    _1280_t9 = ((int64_t*)&_1281_x + _1280_t8);
    _1280_t10 = 6;
    _1281_y = (struct1) {_1280_t9, _1280_t10};
    _1280_t11 = 3;
    _1280_t12 = _1280_t11 > _1281_y._1;
    if (_1280_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1280_t13 = $sub_int64_t(_1281_y._1, _1280_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1280_t14 = _1281_y._0 + _1280_t11;
    _1281_z = (struct1) {_1280_t14, _1280_t13};
    _1280_t16 = _1285_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1280_t17 = _1280_t16(_1281_z);
    $line_idx--;
    _1280_$retval = _1280_t17;
    return _1280_$retval;
}

int64_t _1285_sum_up(struct1 _1285_xs){
    int64_t _1288_sum;
    int64_t _1289_i;
    uint8_t _1285_t3;
    int64_t _1285_t5;
    int64_t _1285_$retval;
    _1288_sum = 0;
    _1289_i = 0;
    goto BB1;
BB1:
    _1285_t3 = _1289_i < _1285_xs._1;
    if (_1285_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1288_sum = $add_int64_t(_1288_sum, *((int64_t*)_1285_xs._0 + _1289_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1285_t5 = 1;
    _1289_i = $add_int64_t(_1289_i, _1285_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1285_$retval = _1288_sum;
    return _1285_$retval;
}

int main(void) {
  printf("%ld",_1280_main());
  return 0;
}
