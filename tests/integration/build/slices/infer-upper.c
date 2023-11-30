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
int64_t _1241_main(void);
int64_t _1246_sum_up(struct1 _1246_xs);

/* Function definitions */
int64_t _1241_main(void) {
    int64_t _1241_t1;
    int64_t _1241_t2;
    int64_t _1241_t3;
    int64_t _1241_t4;
    int64_t _1241_t5;
    int64_t _1241_t6;
    struct0 _1242_x;
    int64_t _1241_t8;
    int64_t* _1241_t9;
    int64_t _1241_t10;
    struct1 _1242_y;
    int64_t _1241_t11;
    uint8_t _1241_t12;
    int64_t _1241_t13;
    int64_t* _1241_t14;
    struct1 _1242_z;
    function2 _1241_t16;
    int64_t _1241_t17;
    int64_t _1241_$retval;
    _1241_t1 = 34;
    _1241_t2 = 25;
    _1241_t3 = 34;
    _1241_t4 = 100;
    _1241_t5 = 8;
    _1241_t6 = 3;
    _1242_x = (struct0) {_1241_t1, _1241_t2, _1241_t3, _1241_t4, _1241_t5, _1241_t6};
    _1241_t8 = 0;
    _1241_t9 = ((int64_t*)&_1242_x + _1241_t8);
    _1241_t10 = 6;
    _1242_y = (struct1) {_1241_t9, _1241_t10};
    _1241_t11 = 3;
    _1241_t12 = _1241_t11 > _1242_y._1;
    if (_1241_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1241_t13 = $sub_int64_t(_1242_y._1, _1241_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1241_t14 = _1242_y._0 + _1241_t11;
    _1242_z = (struct1) {_1241_t14, _1241_t13};
    _1241_t16 = _1246_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1241_t17 = _1241_t16(_1242_z);
    $line_idx--;
    _1241_$retval = _1241_t17;
    return _1241_$retval;
}

int64_t _1246_sum_up(struct1 _1246_xs) {
    int64_t _1248_sum;
    int64_t _1250_i;
    uint8_t _1246_t3;
    int64_t _1246_t5;
    int64_t _1246_$retval;
    _1248_sum = 0;
    _1250_i = 0;
    goto BB1;
BB1:
    _1246_t3 = _1250_i < _1246_xs._1;
    if (_1246_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1248_sum = $add_int64_t(_1248_sum, *((int64_t*)_1246_xs._0 + _1250_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1246_t5 = 1;
    _1250_i = $add_int64_t(_1250_i, _1246_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1246_$retval = _1248_sum;
    return _1246_$retval;
}

int main(void) {
  printf("%ld",_1241_main());
  return 0;
}
