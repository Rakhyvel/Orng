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
int64_t _1245_main(void);
int64_t _1250_sum_up(struct1 _1250_xs);

/* Function definitions */
int64_t _1245_main(void){
    int64_t _1245_t1;
    int64_t _1245_t2;
    int64_t _1245_t3;
    struct0 _1246_x;
    int64_t _1245_t5;
    int64_t* _1245_t6;
    int64_t _1245_t7;
    struct1 _1246_y;
    int64_t _1245_t8;
    uint8_t _1245_t9;
    int64_t _1245_t10;
    int64_t* _1245_t11;
    struct1 _1246_z;
    function2 _1245_t13;
    int64_t _1245_t14;
    int64_t _1245_$retval;
    _1245_t1 = 100;
    _1245_t2 = 10;
    _1245_t3 = 1;
    _1246_x = (struct0) {_1245_t1, _1245_t2, _1245_t3};
    _1245_t5 = 0;
    _1245_t6 = ((int64_t*)&_1246_x + _1245_t5);
    _1245_t7 = 3;
    _1246_y = (struct1) {_1245_t6, _1245_t7};
    _1245_t8 = 0;
    _1245_t9 = _1245_t8 > _1246_y._1;
    if (_1245_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1245_t10 = $sub_int64_t(_1246_y._1, _1245_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1245_t11 = _1246_y._0 + _1245_t8;
    _1246_z = (struct1) {_1245_t11, _1245_t10};
    _1245_t13 = _1250_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1245_t14 = _1245_t13(_1246_z);
    $line_idx--;
    _1245_$retval = _1245_t14;
    return _1245_$retval;
}

int64_t _1250_sum_up(struct1 _1250_xs){
    int64_t _1253_sum;
    int64_t _1254_i;
    uint8_t _1250_t3;
    int64_t _1250_t5;
    int64_t _1250_$retval;
    _1253_sum = 0;
    _1254_i = 0;
    goto BB1;
BB1:
    _1250_t3 = _1254_i < _1250_xs._1;
    if (_1250_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1253_sum = $add_int64_t(_1253_sum, *((int64_t*)_1250_xs._0 + _1254_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1250_t5 = 1;
    _1254_i = $add_int64_t(_1254_i, _1250_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1250_$retval = _1253_sum;
    return _1250_$retval;
}

int main(void) {
  printf("%ld",_1245_main());
  return 0;
}
