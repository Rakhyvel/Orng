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
int64_t _931_main(void);
int64_t _933_sum_up(struct1 _933_xs);

/* Function definitions */
int64_t _931_main(void) {
    int64_t _931_t1;
    int64_t _931_t2;
    int64_t _931_t3;
    int64_t _931_t4;
    int64_t _931_t5;
    int64_t _931_t6;
    struct0 _932_x;
    int64_t _931_t8;
    int64_t* _931_t9;
    int64_t _931_t10;
    struct1 _932_y;
    int64_t _931_t11;
    uint8_t _931_t12;
    int64_t _931_t13;
    int64_t* _931_t14;
    struct1 _932_z;
    function2 _931_t16;
    int64_t _931_t17;
    int64_t _931_$retval;
    _931_t1 = 34;
    _931_t2 = 25;
    _931_t3 = 34;
    _931_t4 = 100;
    _931_t5 = 8;
    _931_t6 = 3;
    _932_x = (struct0) {_931_t1, _931_t2, _931_t3, _931_t4, _931_t5, _931_t6};
    _931_t8 = 0;
    _931_t9 = ((int64_t*)&_932_x + _931_t8);
    _931_t10 = 6;
    _932_y = (struct1) {_931_t9, _931_t10};
    _931_t11 = 3;
    _931_t12 = _931_t11 > _932_y._1;
    if (_931_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _931_t13 = $sub_int64_t(_932_y._1, _931_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _931_t14 = _932_y._0 + _931_t11;
    _932_z = (struct1) {_931_t14, _931_t13};
    _931_t16 = _933_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _931_t17 = _931_t16(_932_z);
    $line_idx--;
    _931_$retval = _931_t17;
    return _931_$retval;
}

int64_t _933_sum_up(struct1 _933_xs) {
    int64_t _934_sum;
    int64_t _935_i;
    uint8_t _933_t3;
    int64_t _933_t5;
    int64_t _933_$retval;
    _934_sum = 0;
    _935_i = 0;
    goto BB1;
BB1:
    _933_t3 = _935_i < _933_xs._1;
    if (_933_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _934_sum = $add_int64_t(_934_sum, *((int64_t*)_933_xs._0 + _935_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _933_t5 = 1;
    _935_i = $add_int64_t(_935_i, _933_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _933_$retval = _934_sum;
    return _933_$retval;
}

int main(void) {
  printf("%ld",_931_main());
  return 0;
}
