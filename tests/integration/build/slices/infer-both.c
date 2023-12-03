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
int64_t _952_main(void);
int64_t _954_sum_up(struct1 _954_xs);

/* Function definitions */
int64_t _952_main(void) {
    int64_t _952_t1;
    int64_t _952_t2;
    int64_t _952_t3;
    struct0 _953_x;
    int64_t _952_t5;
    int64_t* _952_t6;
    int64_t _952_t7;
    struct1 _953_y;
    int64_t _952_t8;
    uint8_t _952_t9;
    int64_t _952_t10;
    int64_t* _952_t11;
    struct1 _953_z;
    function2 _952_t13;
    int64_t _952_t14;
    int64_t _952_$retval;
    _952_t1 = 100;
    _952_t2 = 10;
    _952_t3 = 1;
    _953_x = (struct0) {_952_t1, _952_t2, _952_t3};
    _952_t5 = 0;
    _952_t6 = ((int64_t*)&_953_x + _952_t5);
    _952_t7 = 3;
    _953_y = (struct1) {_952_t6, _952_t7};
    _952_t8 = 0;
    _952_t9 = _952_t8 > _953_y._1;
    if (_952_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _952_t10 = $sub_int64_t(_953_y._1, _952_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _952_t11 = _953_y._0 + _952_t8;
    _953_z = (struct1) {_952_t11, _952_t10};
    _952_t13 = _954_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _952_t14 = _952_t13(_953_z);
    $line_idx--;
    _952_$retval = _952_t14;
    return _952_$retval;
}

int64_t _954_sum_up(struct1 _954_xs) {
    int64_t _955_sum;
    int64_t _956_i;
    uint8_t _954_t3;
    int64_t _954_t5;
    int64_t _954_$retval;
    _955_sum = 0;
    _956_i = 0;
    goto BB1;
BB1:
    _954_t3 = _956_i < _954_xs._1;
    if (_954_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _955_sum = $add_int64_t(_955_sum, *((int64_t*)_954_xs._0 + _956_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _954_t5 = 1;
    _956_i = $add_int64_t(_956_i, _954_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _954_$retval = _955_sum;
    return _954_$retval;
}

int main(void) {
  printf("%ld",_952_main());
  return 0;
}
