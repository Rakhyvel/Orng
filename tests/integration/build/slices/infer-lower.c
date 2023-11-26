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
int64_t _893_main(void);
int64_t _895_sum_up(struct1 _895_xs);

/* Function definitions */
int64_t _893_main(void) {
    int64_t _893_t1;
    int64_t _893_t2;
    int64_t _893_t3;
    int64_t _893_t4;
    int64_t _893_t5;
    int64_t _893_t6;
    struct0 _894_x;
    int64_t _893_t8;
    int64_t* _893_t9;
    int64_t _893_t10;
    struct1 _894_y;
    int64_t _893_t11;
    int64_t _893_t12;
    uint8_t _893_t13;
    int64_t _893_t14;
    int64_t* _893_t15;
    struct1 _894_z;
    function2 _893_t17;
    int64_t _893_t18;
    int64_t _893_$retval;
    _893_t1 = 100;
    _893_t2 = 8;
    _893_t3 = 2;
    _893_t4 = 4;
    _893_t5 = 35;
    _893_t6 = 6;
    _894_x = (struct0) {_893_t1, _893_t2, _893_t3, _893_t4, _893_t5, _893_t6};
    _893_t8 = 0;
    _893_t9 = ((int64_t*)&_894_x + _893_t8);
    _893_t10 = 6;
    _894_y = (struct1) {_893_t9, _893_t10};
    _893_t11 = 0;
    _893_t12 = 3;
    _893_t13 = 0;
    if (_893_t13) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:5:25:\n    let z: [mut]Int = y[..3]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _893_t14 = $sub_int64_t(_893_t12, _893_t11, "tests/integration/slices/infer-lower.orng:5:25:\n    let z: [mut]Int = y[..3]\n                       ^");
    _893_t15 = _894_y._0 + _893_t11;
    _894_z = (struct1) {_893_t15, _893_t14};
    _893_t17 = _895_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _893_t18 = _893_t17(_894_z);
    $line_idx--;
    _893_$retval = _893_t18;
    return _893_$retval;
}

int64_t _895_sum_up(struct1 _895_xs) {
    int64_t _896_sum;
    int64_t _897_i;
    uint8_t _895_t3;
    int64_t _895_t5;
    int64_t _895_$retval;
    _896_sum = 0;
    _897_i = 0;
    goto BB1;
BB1:
    _895_t3 = _897_i < _895_xs._1;
    if (_895_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _896_sum = $add_int64_t(_896_sum, *((int64_t*)_895_xs._0 + _897_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _895_t5 = 1;
    _897_i = $add_int64_t(_897_i, _895_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _895_$retval = _896_sum;
    return _895_$retval;
}

int main(void) {
  printf("%ld",_893_main());
  return 0;
}
