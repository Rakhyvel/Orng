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
    int64_t _3;
    int64_t _4;
    int64_t _5;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1324_main(void);
int64_t _1326_sum_up(struct struct1 _1326_xs);

/* Function definitions */
int64_t _1324_main(void){
    int64_t _1324_t1;
    int64_t _1324_t2;
    int64_t _1324_t3;
    int64_t _1324_t4;
    int64_t _1324_t5;
    int64_t _1324_t6;
    struct struct0 _1325_x;
    int64_t _1324_t8;
    int64_t _1324_t9;
    int64_t* _1324_t10;
    int64_t _1324_t11;
    struct struct1 _1325_y;
    int64_t _1324_t12;
    uint8_t _1324_t13;
    int64_t _1324_t14;
    int64_t* _1324_t15;
    struct struct1 _1325_z;
    function2 _1324_t17;
    int64_t _1324_t18;
    int64_t _1324_$retval;
    _1324_t1 = 34;
    _1324_t2 = 25;
    _1324_t3 = 34;
    _1324_t4 = 100;
    _1324_t5 = 8;
    _1324_t6 = 3;
    _1325_x = (struct struct0) {_1324_t1, _1324_t2, _1324_t3, _1324_t4, _1324_t5, _1324_t6};
    _1324_t8 = 0;
    _1324_t9 = 6;
    $bounds_check(_1324_t8, _1324_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1324_t10 = ((int64_t*)&_1325_x + _1324_t8);
    _1324_t11 = 6;
    _1325_y = (struct struct1) {_1324_t10, _1324_t11};
    _1324_t12 = 3;
    _1324_t13 = _1324_t12>_1325_y._1;
    if (_1324_t13) {
        goto BB1599;
    } else {
        goto BB1600;
    }
BB1599:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1600:
    _1324_t14 = $sub_int64_t(_1325_y._1, _1324_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1324_t15 = _1325_y._0+_1324_t12;
    _1325_z = (struct struct1) {_1324_t15, _1324_t14};
    _1324_t17 = _1326_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1324_t18 = _1324_t17(_1325_z);
    $line_idx--;
    _1324_$retval = _1324_t18;
    return _1324_$retval;
}

int64_t _1326_sum_up(struct struct1 _1326_xs){
    int64_t _1327_sum;
    int64_t _1328_i;
    uint8_t _1326_t3;
    int64_t _1326_t5;
    int64_t _1326_$retval;
    _1327_sum = 0;
    _1328_i = 0;
    goto BB1591;
BB1591:
    _1326_t3 = _1328_i<_1326_xs._1;
    if (_1326_t3) {
        goto BB1592;
    } else {
        goto BB1597;
    }
BB1592:
    $bounds_check(_1328_i, _1326_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1327_sum = $add_int64_t(_1327_sum, *((int64_t*)_1326_xs._0 + _1328_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1326_t5 = 1;
    _1328_i = $add_int64_t(_1328_i, _1326_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1591;
BB1597:
    _1326_$retval = _1327_sum;
    return _1326_$retval;
}

int main(void) {
  printf("%ld",_1324_main());
  return 0;
}
