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
int64_t _1261_main(void);
int64_t _1266_sum_up(struct1 _1266_xs);

/* Function definitions */
int64_t _1261_main(void) {
    int64_t _1261_t1;
    int64_t _1261_t2;
    int64_t _1261_t3;
    int64_t _1261_t4;
    int64_t _1261_t5;
    int64_t _1261_t6;
    struct0 _1262_x;
    int64_t _1261_t8;
    int64_t* _1261_t9;
    int64_t _1261_t10;
    struct1 _1262_y;
    int64_t _1261_t11;
    uint8_t _1261_t12;
    int64_t _1261_t13;
    int64_t* _1261_t14;
    struct1 _1262_z;
    function2 _1261_t16;
    int64_t _1261_t17;
    int64_t _1261_$retval;
    _1261_t1 = 34;
    _1261_t2 = 25;
    _1261_t3 = 34;
    _1261_t4 = 100;
    _1261_t5 = 8;
    _1261_t6 = 3;
    _1262_x = (struct0) {_1261_t1, _1261_t2, _1261_t3, _1261_t4, _1261_t5, _1261_t6};
    _1261_t8 = 0;
    _1261_t9 = ((int64_t*)&_1262_x + _1261_t8);
    _1261_t10 = 6;
    _1262_y = (struct1) {_1261_t9, _1261_t10};
    _1261_t11 = 3;
    _1261_t12 = _1261_t11 > _1262_y._1;
    if (_1261_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1261_t13 = $sub_int64_t(_1262_y._1, _1261_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1261_t14 = _1262_y._0 + _1261_t11;
    _1262_z = (struct1) {_1261_t14, _1261_t13};
    _1261_t16 = _1266_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1261_t17 = _1261_t16(_1262_z);
    $line_idx--;
    _1261_$retval = _1261_t17;
    return _1261_$retval;
}

int64_t _1266_sum_up(struct1 _1266_xs) {
    int64_t _1269_sum;
    int64_t _1270_i;
    uint8_t _1266_t3;
    int64_t _1266_t5;
    int64_t _1266_$retval;
    _1269_sum = 0;
    _1270_i = 0;
    goto BB1;
BB1:
    _1266_t3 = _1270_i < _1266_xs._1;
    if (_1266_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1269_sum = $add_int64_t(_1269_sum, *((int64_t*)_1266_xs._0 + _1270_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1266_t5 = 1;
    _1270_i = $add_int64_t(_1270_i, _1266_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1266_$retval = _1269_sum;
    return _1266_$retval;
}

int main(void) {
  printf("%ld",_1261_main());
  return 0;
}
