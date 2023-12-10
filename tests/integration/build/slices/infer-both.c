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
int64_t _976_main(void);
int64_t _978_sum_up(struct1 _978_xs);

/* Function definitions */
int64_t _976_main(void) {
    int64_t _976_t1;
    int64_t _976_t2;
    int64_t _976_t3;
    struct0 _977_x;
    int64_t _976_t5;
    int64_t* _976_t6;
    int64_t _976_t7;
    struct1 _977_y;
    int64_t _976_t8;
    uint8_t _976_t9;
    int64_t _976_t10;
    int64_t* _976_t11;
    struct1 _977_z;
    function2 _976_t13;
    int64_t _976_t14;
    int64_t _976_$retval;
    _976_t1 = 100;
    _976_t2 = 10;
    _976_t3 = 1;
    _977_x = (struct0) {_976_t1, _976_t2, _976_t3};
    _976_t5 = 0;
    _976_t6 = ((int64_t*)&_977_x + _976_t5);
    _976_t7 = 3;
    _977_y = (struct1) {_976_t6, _976_t7};
    _976_t8 = 0;
    _976_t9 = _976_t8 > _977_y._1;
    if (_976_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _976_t10 = $sub_int64_t(_977_y._1, _976_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _976_t11 = _977_y._0 + _976_t8;
    _977_z = (struct1) {_976_t11, _976_t10};
    _976_t13 = _978_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _976_t14 = _976_t13(_977_z);
    $line_idx--;
    _976_$retval = _976_t14;
    return _976_$retval;
}

int64_t _978_sum_up(struct1 _978_xs) {
    int64_t _979_sum;
    int64_t _980_i;
    uint8_t _978_t3;
    int64_t _978_t5;
    int64_t _978_$retval;
    _979_sum = 0;
    _980_i = 0;
    goto BB1;
BB1:
    _978_t3 = _980_i < _978_xs._1;
    if (_978_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _979_sum = $add_int64_t(_979_sum, *((int64_t*)_978_xs._0 + _980_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _978_t5 = 1;
    _980_i = $add_int64_t(_980_i, _978_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _978_$retval = _979_sum;
    return _978_$retval;
}

int main(void) {
  printf("%ld",_976_main());
  return 0;
}
