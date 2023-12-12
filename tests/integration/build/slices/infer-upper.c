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
int64_t _1017_main(void);
int64_t _1019_sum_up(struct1 _1019_xs);

/* Function definitions */
int64_t _1017_main(void) {
    int64_t _1017_t1;
    int64_t _1017_t2;
    int64_t _1017_t3;
    int64_t _1017_t4;
    int64_t _1017_t5;
    int64_t _1017_t6;
    struct0 _1018_x;
    int64_t _1017_t8;
    int64_t* _1017_t9;
    int64_t _1017_t10;
    struct1 _1018_y;
    int64_t _1017_t11;
    uint8_t _1017_t12;
    int64_t _1017_t13;
    int64_t* _1017_t14;
    struct1 _1018_z;
    function2 _1017_t16;
    int64_t _1017_t17;
    int64_t _1017_$retval;
    _1017_t1 = 34;
    _1017_t2 = 25;
    _1017_t3 = 34;
    _1017_t4 = 100;
    _1017_t5 = 8;
    _1017_t6 = 3;
    _1018_x = (struct0) {_1017_t1, _1017_t2, _1017_t3, _1017_t4, _1017_t5, _1017_t6};
    _1017_t8 = 0;
    _1017_t9 = ((int64_t*)&_1018_x + _1017_t8);
    _1017_t10 = 6;
    _1018_y = (struct1) {_1017_t9, _1017_t10};
    _1017_t11 = 3;
    _1017_t12 = _1017_t11 > _1018_y._1;
    if (_1017_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1017_t13 = $sub_int64_t(_1018_y._1, _1017_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1017_t14 = _1018_y._0 + _1017_t11;
    _1018_z = (struct1) {_1017_t14, _1017_t13};
    _1017_t16 = _1019_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1017_t17 = _1017_t16(_1018_z);
    $line_idx--;
    _1017_$retval = _1017_t17;
    return _1017_$retval;
}

int64_t _1019_sum_up(struct1 _1019_xs) {
    int64_t _1020_sum;
    int64_t _1021_i;
    uint8_t _1019_t3;
    int64_t _1019_t5;
    int64_t _1019_$retval;
    _1020_sum = 0;
    _1021_i = 0;
    goto BB1;
BB1:
    _1019_t3 = _1021_i < _1019_xs._1;
    if (_1019_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1020_sum = $add_int64_t(_1020_sum, *((int64_t*)_1019_xs._0 + _1021_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1019_t5 = 1;
    _1021_i = $add_int64_t(_1021_i, _1019_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1019_$retval = _1020_sum;
    return _1019_$retval;
}

int main(void) {
  printf("%ld",_1017_main());
  return 0;
}
