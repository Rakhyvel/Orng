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
int64_t _12_main(void);
int64_t _14_sum_up(struct1 _14_xs);

/* Function definitions */
int64_t _12_main(void) {
    int64_t _12_t1;
    int64_t _12_t2;
    int64_t _12_t3;
    struct0 _13_x;
    int64_t _12_t5;
    int64_t* _12_t6;
    int64_t _12_t7;
    struct1 _13_y;
    int64_t _12_t8;
    uint8_t _12_t9;
    int64_t _12_t10;
    int64_t* _12_t11;
    struct1 _13_z;
    function2 _12_t13;
    int64_t _12_t14;
    int64_t _12_$retval;
    _12_t1 = 100;
    _12_t2 = 10;
    _12_t3 = 1;
    _13_x = (struct0) {_12_t1, _12_t2, _12_t3};
    _12_t5 = 0;
    _12_t6 = ((int64_t*)&_13_x + _12_t5);
    _12_t7 = 3;
    _13_y = (struct1) {_12_t6, _12_t7};
    _12_t8 = 0;
    _12_t9 = _12_t8 > _13_y._1;
    if (_12_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _12_t10 = $sub_int64_t(_13_y._1, _12_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _12_t11 = _13_y._0 + _12_t8;
    _13_z = (struct1) {_12_t11, _12_t10};
    _12_t13 = _14_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _12_t14 = _12_t13(_13_z);
    $line_idx--;
    _12_$retval = _12_t14;
    return _12_$retval;
}

int64_t _14_sum_up(struct1 _14_xs) {
    int64_t _15_sum;
    int64_t _16_i;
    uint8_t _14_t3;
    int64_t _14_t5;
    int64_t _14_$retval;
    _15_sum = 0;
    _16_i = 0;
    goto BB1;
BB1:
    _14_t3 = _16_i < _14_xs._1;
    if (_14_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _15_sum = $add_int64_t(_15_sum, *((int64_t*)_14_xs._0 + _16_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _14_t5 = 1;
    _16_i = $add_int64_t(_16_i, _14_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _14_$retval = _15_sum;
    return _14_$retval;
}

int main(void) {
  printf("%ld",_12_main());
  return 0;
}
