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
int64_t _1514_main(void);
int64_t _1519_sum_up(struct1 _1519_xs);

/* Function definitions */
int64_t _1514_main(void){
    int64_t _1514_t1;
    int64_t _1514_t2;
    int64_t _1514_t3;
    int64_t _1514_t4;
    int64_t _1514_t5;
    int64_t _1514_t6;
    struct0 _1515_x;
    int64_t _1514_t8;
    int64_t _1514_t9;
    int64_t* _1514_t10;
    int64_t _1514_t11;
    struct1 _1515_y;
    int64_t _1514_t12;
    uint8_t _1514_t13;
    int64_t _1514_t14;
    int64_t* _1514_t15;
    struct1 _1515_z;
    function2 _1514_t17;
    int64_t _1514_t18;
    int64_t _1514_$retval;
    _1514_t1 = 34;
    _1514_t2 = 25;
    _1514_t3 = 34;
    _1514_t4 = 100;
    _1514_t5 = 8;
    _1514_t6 = 3;
    _1515_x = (struct0) {_1514_t1, _1514_t2, _1514_t3, _1514_t4, _1514_t5, _1514_t6};
    _1514_t8 = 0;
    _1514_t9 = 6;
    $bounds_check(_1514_t8, _1514_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1514_t10 = ((int64_t*)&_1515_x + _1514_t8);
    _1514_t11 = 6;
    _1515_y = (struct1) {_1514_t10, _1514_t11};
    _1514_t12 = 3;
    _1514_t13 = _1514_t12 > _1515_y._1;
    if (_1514_t13) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1514_t14 = $sub_int64_t(_1515_y._1, _1514_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1514_t15 = _1515_y._0 + _1514_t12;
    _1515_z = (struct1) {_1514_t15, _1514_t14};
    _1514_t17 = _1519_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1514_t18 = _1514_t17(_1515_z);
    $line_idx--;
    _1514_$retval = _1514_t18;
    return _1514_$retval;
}

int64_t _1519_sum_up(struct1 _1519_xs){
    int64_t _1522_sum;
    int64_t _1523_i;
    uint8_t _1519_t3;
    int64_t _1519_t5;
    int64_t _1519_$retval;
    _1522_sum = 0;
    _1523_i = 0;
    goto BB1;
BB1:
    _1519_t3 = _1523_i < _1519_xs._1;
    if (_1519_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1523_i, _1519_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1522_sum = $add_int64_t(_1522_sum, *((int64_t*)_1519_xs._0 + _1523_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1519_t5 = 1;
    _1523_i = $add_int64_t(_1523_i, _1519_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1519_$retval = _1522_sum;
    return _1519_$retval;
}

int main(void) {
  printf("%ld",_1514_main());
  return 0;
}
