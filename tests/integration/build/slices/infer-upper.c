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
int64_t _26_main(void);
int64_t _28_sum_up(struct1 _28_xs);

/* Function definitions */
int64_t _26_main(void) {
    int64_t _26_t1;
    int64_t _26_t2;
    int64_t _26_t3;
    int64_t _26_t4;
    int64_t _26_t5;
    int64_t _26_t6;
    struct0 _27_x;
    int64_t _26_t8;
    int64_t* _26_t9;
    int64_t _26_t10;
    struct1 _27_y;
    int64_t _26_t11;
    uint8_t _26_t12;
    int64_t _26_t13;
    int64_t* _26_t14;
    struct1 _27_z;
    function2 _26_t16;
    int64_t _26_t17;
    int64_t _26_$retval;
    _26_t1 = 34;
    _26_t2 = 25;
    _26_t3 = 34;
    _26_t4 = 100;
    _26_t5 = 8;
    _26_t6 = 3;
    _27_x = (struct0) {_26_t1, _26_t2, _26_t3, _26_t4, _26_t5, _26_t6};
    _26_t8 = 0;
    _26_t9 = ((int64_t*)&_27_x + _26_t8);
    _26_t10 = 6;
    _27_y = (struct1) {_26_t9, _26_t10};
    _26_t11 = 3;
    _26_t12 = _26_t11 > _27_y._1;
    if (_26_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _26_t13 = $sub_int64_t(_27_y._1, _26_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _26_t14 = _27_y._0 + _26_t11;
    _27_z = (struct1) {_26_t14, _26_t13};
    _26_t16 = _28_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _26_t17 = _26_t16(_27_z);
    $line_idx--;
    _26_$retval = _26_t17;
    return _26_$retval;
}

int64_t _28_sum_up(struct1 _28_xs) {
    int64_t _29_sum;
    int64_t _30_i;
    uint8_t _28_t3;
    int64_t _28_t5;
    int64_t _28_$retval;
    _29_sum = 0;
    _30_i = 0;
    goto BB1;
BB1:
    _28_t3 = _30_i < _28_xs._1;
    if (_28_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _29_sum = $add_int64_t(_29_sum, *((int64_t*)_28_xs._0 + _30_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _28_t5 = 1;
    _30_i = $add_int64_t(_30_i, _28_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _28_$retval = _29_sum;
    return _28_$retval;
}

int main(void) {
  printf("%ld",_26_main());
  return 0;
}
