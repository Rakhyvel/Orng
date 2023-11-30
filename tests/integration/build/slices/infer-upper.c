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
int64_t _1264_main(void);
int64_t _1269_sum_up(struct1 _1269_xs);

/* Function definitions */
int64_t _1264_main(void) {
    int64_t _1264_t1;
    int64_t _1264_t2;
    int64_t _1264_t3;
    int64_t _1264_t4;
    int64_t _1264_t5;
    int64_t _1264_t6;
    struct0 _1265_x;
    int64_t _1264_t8;
    int64_t* _1264_t9;
    int64_t _1264_t10;
    struct1 _1265_y;
    int64_t _1264_t11;
    uint8_t _1264_t12;
    int64_t _1264_t13;
    int64_t* _1264_t14;
    struct1 _1265_z;
    function2 _1264_t16;
    int64_t _1264_t17;
    int64_t _1264_$retval;
    _1264_t1 = 34;
    _1264_t2 = 25;
    _1264_t3 = 34;
    _1264_t4 = 100;
    _1264_t5 = 8;
    _1264_t6 = 3;
    _1265_x = (struct0) {_1264_t1, _1264_t2, _1264_t3, _1264_t4, _1264_t5, _1264_t6};
    _1264_t8 = 0;
    _1264_t9 = ((int64_t*)&_1265_x + _1264_t8);
    _1264_t10 = 6;
    _1265_y = (struct1) {_1264_t9, _1264_t10};
    _1264_t11 = 3;
    _1264_t12 = _1264_t11 > _1265_y._1;
    if (_1264_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1264_t13 = $sub_int64_t(_1265_y._1, _1264_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1264_t14 = _1265_y._0 + _1264_t11;
    _1265_z = (struct1) {_1264_t14, _1264_t13};
    _1264_t16 = _1269_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1264_t17 = _1264_t16(_1265_z);
    $line_idx--;
    _1264_$retval = _1264_t17;
    return _1264_$retval;
}

int64_t _1269_sum_up(struct1 _1269_xs) {
    int64_t _1271_sum;
    int64_t _1273_i;
    uint8_t _1269_t3;
    int64_t _1269_t5;
    int64_t _1269_$retval;
    _1271_sum = 0;
    _1273_i = 0;
    goto BB1;
BB1:
    _1269_t3 = _1273_i < _1269_xs._1;
    if (_1269_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1271_sum = $add_int64_t(_1271_sum, *((int64_t*)_1269_xs._0 + _1273_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1269_t5 = 1;
    _1273_i = $add_int64_t(_1273_i, _1269_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1269_$retval = _1271_sum;
    return _1269_$retval;
}

int main(void) {
  printf("%ld",_1264_main());
  return 0;
}
