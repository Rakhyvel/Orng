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
int64_t _1262_main(void);
int64_t _1267_sum_up(struct1 _1267_xs);

/* Function definitions */
int64_t _1262_main(void) {
    int64_t _1262_t1;
    int64_t _1262_t2;
    int64_t _1262_t3;
    int64_t _1262_t4;
    int64_t _1262_t5;
    int64_t _1262_t6;
    struct0 _1263_x;
    int64_t _1262_t8;
    int64_t* _1262_t9;
    int64_t _1262_t10;
    struct1 _1263_y;
    int64_t _1262_t11;
    uint8_t _1262_t12;
    int64_t _1262_t13;
    int64_t* _1262_t14;
    struct1 _1263_z;
    function2 _1262_t16;
    int64_t _1262_t17;
    int64_t _1262_$retval;
    _1262_t1 = 34;
    _1262_t2 = 25;
    _1262_t3 = 34;
    _1262_t4 = 100;
    _1262_t5 = 8;
    _1262_t6 = 3;
    _1263_x = (struct0) {_1262_t1, _1262_t2, _1262_t3, _1262_t4, _1262_t5, _1262_t6};
    _1262_t8 = 0;
    _1262_t9 = ((int64_t*)&_1263_x + _1262_t8);
    _1262_t10 = 6;
    _1263_y = (struct1) {_1262_t9, _1262_t10};
    _1262_t11 = 3;
    _1262_t12 = _1262_t11 > _1263_y._1;
    if (_1262_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1262_t13 = $sub_int64_t(_1263_y._1, _1262_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1262_t14 = _1263_y._0 + _1262_t11;
    _1263_z = (struct1) {_1262_t14, _1262_t13};
    _1262_t16 = _1267_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1262_t17 = _1262_t16(_1263_z);
    $line_idx--;
    _1262_$retval = _1262_t17;
    return _1262_$retval;
}

int64_t _1267_sum_up(struct1 _1267_xs) {
    int64_t _1269_sum;
    int64_t _1271_i;
    uint8_t _1267_t3;
    int64_t _1267_t5;
    int64_t _1267_$retval;
    _1269_sum = 0;
    _1271_i = 0;
    goto BB1;
BB1:
    _1267_t3 = _1271_i < _1267_xs._1;
    if (_1267_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1269_sum = $add_int64_t(_1269_sum, *((int64_t*)_1267_xs._0 + _1271_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1267_t5 = 1;
    _1271_i = $add_int64_t(_1271_i, _1267_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1267_$retval = _1269_sum;
    return _1267_$retval;
}

int main(void) {
  printf("%ld",_1262_main());
  return 0;
}
