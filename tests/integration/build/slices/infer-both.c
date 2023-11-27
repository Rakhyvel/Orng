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
int64_t _917_main(void);
int64_t _919_sum_up(struct1 _919_xs);

/* Function definitions */
int64_t _917_main(void) {
    int64_t _917_t1;
    int64_t _917_t2;
    int64_t _917_t3;
    struct0 _918_x;
    int64_t _917_t5;
    int64_t* _917_t6;
    int64_t _917_t7;
    struct1 _918_y;
    int64_t _917_t8;
    uint8_t _917_t9;
    int64_t _917_t10;
    int64_t* _917_t11;
    struct1 _918_z;
    function2 _917_t13;
    int64_t _917_t14;
    int64_t _917_$retval;
    _917_t1 = 100;
    _917_t2 = 10;
    _917_t3 = 1;
    _918_x = (struct0) {_917_t1, _917_t2, _917_t3};
    _917_t5 = 0;
    _917_t6 = ((int64_t*)&_918_x + _917_t5);
    _917_t7 = 3;
    _918_y = (struct1) {_917_t6, _917_t7};
    _917_t8 = 0;
    _917_t9 = _917_t8 > _918_y._1;
    if (_917_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _917_t10 = $sub_int64_t(_918_y._1, _917_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _917_t11 = _918_y._0 + _917_t8;
    _918_z = (struct1) {_917_t11, _917_t10};
    _917_t13 = _919_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _917_t14 = _917_t13(_918_z);
    $line_idx--;
    _917_$retval = _917_t14;
    return _917_$retval;
}

int64_t _919_sum_up(struct1 _919_xs) {
    int64_t _920_sum;
    int64_t _921_i;
    uint8_t _919_t3;
    int64_t _919_t5;
    int64_t _919_$retval;
    _920_sum = 0;
    _921_i = 0;
    goto BB1;
BB1:
    _919_t3 = _921_i < _919_xs._1;
    if (_919_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _920_sum = $add_int64_t(_920_sum, *((int64_t*)_919_xs._0 + _921_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _919_t5 = 1;
    _921_i = $add_int64_t(_921_i, _919_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _919_$retval = _920_sum;
    return _919_$retval;
}

int main(void) {
  printf("%ld",_917_main());
  return 0;
}
