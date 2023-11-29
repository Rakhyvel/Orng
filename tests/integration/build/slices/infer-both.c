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
int64_t _1236_main(void);
int64_t _1241_sum_up(struct1 _1241_xs);

/* Function definitions */
int64_t _1236_main(void) {
    int64_t _1236_t1;
    int64_t _1236_t2;
    int64_t _1236_t3;
    struct0 _1237_x;
    int64_t _1236_t5;
    int64_t* _1236_t6;
    int64_t _1236_t7;
    struct1 _1237_y;
    int64_t _1236_t8;
    uint8_t _1236_t9;
    int64_t _1236_t10;
    int64_t* _1236_t11;
    struct1 _1237_z;
    function2 _1236_t13;
    int64_t _1236_t14;
    int64_t _1236_$retval;
    _1236_t1 = 100;
    _1236_t2 = 10;
    _1236_t3 = 1;
    _1237_x = (struct0) {_1236_t1, _1236_t2, _1236_t3};
    _1236_t5 = 0;
    _1236_t6 = ((int64_t*)&_1237_x + _1236_t5);
    _1236_t7 = 3;
    _1237_y = (struct1) {_1236_t6, _1236_t7};
    _1236_t8 = 0;
    _1236_t9 = _1236_t8 > _1237_y._1;
    if (_1236_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1236_t10 = $sub_int64_t(_1237_y._1, _1236_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1236_t11 = _1237_y._0 + _1236_t8;
    _1237_z = (struct1) {_1236_t11, _1236_t10};
    _1236_t13 = _1241_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1236_t14 = _1236_t13(_1237_z);
    $line_idx--;
    _1236_$retval = _1236_t14;
    return _1236_$retval;
}

int64_t _1241_sum_up(struct1 _1241_xs) {
    int64_t _1243_sum;
    int64_t _1245_i;
    uint8_t _1241_t3;
    int64_t _1241_t5;
    int64_t _1241_$retval;
    _1243_sum = 0;
    _1245_i = 0;
    goto BB1;
BB1:
    _1241_t3 = _1245_i < _1241_xs._1;
    if (_1241_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1243_sum = $add_int64_t(_1243_sum, *((int64_t*)_1241_xs._0 + _1245_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1241_t5 = 1;
    _1245_i = $add_int64_t(_1245_i, _1241_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1241_$retval = _1243_sum;
    return _1241_$retval;
}

int main(void) {
  printf("%ld",_1236_main());
  return 0;
}
