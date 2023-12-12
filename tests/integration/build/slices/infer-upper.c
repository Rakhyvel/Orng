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
int64_t _998_main(void);
int64_t _1000_sum_up(struct1 _1000_xs);

/* Function definitions */
int64_t _998_main(void) {
    int64_t _998_t1;
    int64_t _998_t2;
    int64_t _998_t3;
    int64_t _998_t4;
    int64_t _998_t5;
    int64_t _998_t6;
    struct0 _999_x;
    int64_t _998_t8;
    int64_t* _998_t9;
    int64_t _998_t10;
    struct1 _999_y;
    int64_t _998_t11;
    uint8_t _998_t12;
    int64_t _998_t13;
    int64_t* _998_t14;
    struct1 _999_z;
    function2 _998_t16;
    int64_t _998_t17;
    int64_t _998_$retval;
    _998_t1 = 34;
    _998_t2 = 25;
    _998_t3 = 34;
    _998_t4 = 100;
    _998_t5 = 8;
    _998_t6 = 3;
    _999_x = (struct0) {_998_t1, _998_t2, _998_t3, _998_t4, _998_t5, _998_t6};
    _998_t8 = 0;
    _998_t9 = ((int64_t*)&_999_x + _998_t8);
    _998_t10 = 6;
    _999_y = (struct1) {_998_t9, _998_t10};
    _998_t11 = 3;
    _998_t12 = _998_t11 > _999_y._1;
    if (_998_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _998_t13 = $sub_int64_t(_999_y._1, _998_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _998_t14 = _999_y._0 + _998_t11;
    _999_z = (struct1) {_998_t14, _998_t13};
    _998_t16 = _1000_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _998_t17 = _998_t16(_999_z);
    $line_idx--;
    _998_$retval = _998_t17;
    return _998_$retval;
}

int64_t _1000_sum_up(struct1 _1000_xs) {
    int64_t _1001_sum;
    int64_t _1002_i;
    uint8_t _1000_t3;
    int64_t _1000_t5;
    int64_t _1000_$retval;
    _1001_sum = 0;
    _1002_i = 0;
    goto BB1;
BB1:
    _1000_t3 = _1002_i < _1000_xs._1;
    if (_1000_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1001_sum = $add_int64_t(_1001_sum, *((int64_t*)_1000_xs._0 + _1002_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1000_t5 = 1;
    _1002_i = $add_int64_t(_1002_i, _1000_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1000_$retval = _1001_sum;
    return _1000_$retval;
}

int main(void) {
  printf("%ld",_998_main());
  return 0;
}
