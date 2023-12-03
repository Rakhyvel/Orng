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
int64_t _966_main(void);
int64_t _968_sum_up(struct1 _968_xs);

/* Function definitions */
int64_t _966_main(void) {
    int64_t _966_t1;
    int64_t _966_t2;
    int64_t _966_t3;
    int64_t _966_t4;
    int64_t _966_t5;
    int64_t _966_t6;
    struct0 _967_x;
    int64_t _966_t8;
    int64_t* _966_t9;
    int64_t _966_t10;
    struct1 _967_y;
    int64_t _966_t11;
    uint8_t _966_t12;
    int64_t _966_t13;
    int64_t* _966_t14;
    struct1 _967_z;
    function2 _966_t16;
    int64_t _966_t17;
    int64_t _966_$retval;
    _966_t1 = 34;
    _966_t2 = 25;
    _966_t3 = 34;
    _966_t4 = 100;
    _966_t5 = 8;
    _966_t6 = 3;
    _967_x = (struct0) {_966_t1, _966_t2, _966_t3, _966_t4, _966_t5, _966_t6};
    _966_t8 = 0;
    _966_t9 = ((int64_t*)&_967_x + _966_t8);
    _966_t10 = 6;
    _967_y = (struct1) {_966_t9, _966_t10};
    _966_t11 = 3;
    _966_t12 = _966_t11 > _967_y._1;
    if (_966_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _966_t13 = $sub_int64_t(_967_y._1, _966_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _966_t14 = _967_y._0 + _966_t11;
    _967_z = (struct1) {_966_t14, _966_t13};
    _966_t16 = _968_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _966_t17 = _966_t16(_967_z);
    $line_idx--;
    _966_$retval = _966_t17;
    return _966_$retval;
}

int64_t _968_sum_up(struct1 _968_xs) {
    int64_t _969_sum;
    int64_t _970_i;
    uint8_t _968_t3;
    int64_t _968_t5;
    int64_t _968_$retval;
    _969_sum = 0;
    _970_i = 0;
    goto BB1;
BB1:
    _968_t3 = _970_i < _968_xs._1;
    if (_968_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _969_sum = $add_int64_t(_969_sum, *((int64_t*)_968_xs._0 + _970_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _968_t5 = 1;
    _970_i = $add_int64_t(_970_i, _968_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _968_$retval = _969_sum;
    return _968_$retval;
}

int main(void) {
  printf("%ld",_966_main());
  return 0;
}
