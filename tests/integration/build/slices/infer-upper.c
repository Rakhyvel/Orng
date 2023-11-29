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
int64_t _1025_main(void);
int64_t _1028_sum_up(struct1 _1028_xs);

/* Function definitions */
int64_t _1025_main(void) {
    int64_t _1025_t1;
    int64_t _1025_t2;
    int64_t _1025_t3;
    int64_t _1025_t4;
    int64_t _1025_t5;
    int64_t _1025_t6;
    struct0 _1026_x;
    int64_t _1025_t8;
    int64_t* _1025_t9;
    int64_t _1025_t10;
    struct1 _1026_y;
    int64_t _1025_t11;
    uint8_t _1025_t12;
    int64_t _1025_t13;
    int64_t* _1025_t14;
    struct1 _1026_z;
    function2 _1025_t16;
    int64_t _1025_t17;
    int64_t _1025_$retval;
    _1025_t1 = 34;
    _1025_t2 = 25;
    _1025_t3 = 34;
    _1025_t4 = 100;
    _1025_t5 = 8;
    _1025_t6 = 3;
    _1026_x = (struct0) {_1025_t1, _1025_t2, _1025_t3, _1025_t4, _1025_t5, _1025_t6};
    _1025_t8 = 0;
    _1025_t9 = ((int64_t*)&_1026_x + _1025_t8);
    _1025_t10 = 6;
    _1026_y = (struct1) {_1025_t9, _1025_t10};
    _1025_t11 = 3;
    _1025_t12 = _1025_t11 > _1026_y._1;
    if (_1025_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1025_t13 = $sub_int64_t(_1026_y._1, _1025_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1025_t14 = _1026_y._0 + _1025_t11;
    _1026_z = (struct1) {_1025_t14, _1025_t13};
    _1025_t16 = _1028_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1025_t17 = _1025_t16(_1026_z);
    $line_idx--;
    _1025_$retval = _1025_t17;
    return _1025_$retval;
}

int64_t _1028_sum_up(struct1 _1028_xs) {
    int64_t _1029_sum;
    int64_t _1030_i;
    uint8_t _1028_t3;
    int64_t _1028_t5;
    int64_t _1028_$retval;
    _1029_sum = 0;
    _1030_i = 0;
    goto BB1;
BB1:
    _1028_t3 = _1030_i < _1028_xs._1;
    if (_1028_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1029_sum = $add_int64_t(_1029_sum, *((int64_t*)_1028_xs._0 + _1030_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1028_t5 = 1;
    _1030_i = $add_int64_t(_1030_i, _1028_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1028_$retval = _1029_sum;
    return _1028_$retval;
}

int main(void) {
  printf("%ld",_1025_main());
  return 0;
}
