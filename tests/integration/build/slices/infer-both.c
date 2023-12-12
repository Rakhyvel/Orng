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
int64_t _984_main(void);
int64_t _986_sum_up(struct1 _986_xs);

/* Function definitions */
int64_t _984_main(void) {
    int64_t _984_t1;
    int64_t _984_t2;
    int64_t _984_t3;
    struct0 _985_x;
    int64_t _984_t5;
    int64_t* _984_t6;
    int64_t _984_t7;
    struct1 _985_y;
    int64_t _984_t8;
    uint8_t _984_t9;
    int64_t _984_t10;
    int64_t* _984_t11;
    struct1 _985_z;
    function2 _984_t13;
    int64_t _984_t14;
    int64_t _984_$retval;
    _984_t1 = 100;
    _984_t2 = 10;
    _984_t3 = 1;
    _985_x = (struct0) {_984_t1, _984_t2, _984_t3};
    _984_t5 = 0;
    _984_t6 = ((int64_t*)&_985_x + _984_t5);
    _984_t7 = 3;
    _985_y = (struct1) {_984_t6, _984_t7};
    _984_t8 = 0;
    _984_t9 = _984_t8 > _985_y._1;
    if (_984_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _984_t10 = $sub_int64_t(_985_y._1, _984_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _984_t11 = _985_y._0 + _984_t8;
    _985_z = (struct1) {_984_t11, _984_t10};
    _984_t13 = _986_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _984_t14 = _984_t13(_985_z);
    $line_idx--;
    _984_$retval = _984_t14;
    return _984_$retval;
}

int64_t _986_sum_up(struct1 _986_xs) {
    int64_t _987_sum;
    int64_t _988_i;
    uint8_t _986_t3;
    int64_t _986_t5;
    int64_t _986_$retval;
    _987_sum = 0;
    _988_i = 0;
    goto BB1;
BB1:
    _986_t3 = _988_i < _986_xs._1;
    if (_986_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _987_sum = $add_int64_t(_987_sum, *((int64_t*)_986_xs._0 + _988_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _986_t5 = 1;
    _988_i = $add_int64_t(_988_i, _986_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _986_$retval = _987_sum;
    return _986_$retval;
}

int main(void) {
  printf("%ld",_984_main());
  return 0;
}
