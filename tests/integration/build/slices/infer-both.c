/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1323_main(void);
int64_t _1325_sum_up(struct struct1 _1325_xs);

/* Function definitions */
int64_t _1323_main(void){
    int64_t _1323_t1;
    int64_t _1323_t2;
    int64_t _1323_t3;
    struct struct0 _1324_x;
    int64_t _1323_t5;
    int64_t _1323_t6;
    int64_t* _1323_t7;
    int64_t _1323_t8;
    struct struct1 _1324_y;
    int64_t _1323_t9;
    uint8_t _1323_t10;
    int64_t _1323_t11;
    int64_t* _1323_t12;
    struct struct1 _1324_z;
    function2 _1323_t14;
    int64_t _1323_t15;
    int64_t _1323_$retval;
    _1323_t1 = 100;
    _1323_t2 = 10;
    _1323_t3 = 1;
    _1324_x = (struct struct0) {_1323_t1, _1323_t2, _1323_t3};
    _1323_t5 = 0;
    _1323_t6 = 3;
    $bounds_check(_1323_t5, _1323_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1323_t7 = ((int64_t*)&_1324_x + _1323_t5);
    _1323_t8 = 3;
    _1324_y = (struct struct1) {_1323_t7, _1323_t8};
    _1323_t9 = 0;
    _1323_t10 = _1323_t9>_1324_y._1;
    if (_1323_t10) {
        goto BB1591;
    } else {
        goto BB1592;
    }
BB1591:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1592:
    _1323_t11 = $sub_int64_t(_1324_y._1, _1323_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1323_t12 = _1324_y._0+_1323_t9;
    _1324_z = (struct struct1) {_1323_t12, _1323_t11};
    _1323_t14 = _1325_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1323_t15 = _1323_t14(_1324_z);
    $line_idx--;
    _1323_$retval = _1323_t15;
    return _1323_$retval;
}

int64_t _1325_sum_up(struct struct1 _1325_xs){
    int64_t _1326_sum;
    int64_t _1327_i;
    uint8_t _1325_t3;
    int64_t _1325_t5;
    int64_t _1325_$retval;
    _1326_sum = 0;
    _1327_i = 0;
    goto BB1583;
BB1583:
    _1325_t3 = _1327_i<_1325_xs._1;
    if (_1325_t3) {
        goto BB1584;
    } else {
        goto BB1589;
    }
BB1584:
    $bounds_check(_1327_i, _1325_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1326_sum = $add_int64_t(_1326_sum, *((int64_t*)_1325_xs._0 + _1327_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1325_t5 = 1;
    _1327_i = $add_int64_t(_1327_i, _1325_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1583;
BB1589:
    _1325_$retval = _1326_sum;
    return _1325_$retval;
}

int main(void) {
  printf("%ld",_1323_main());
  return 0;
}
