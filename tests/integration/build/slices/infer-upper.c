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
int64_t _1316_main(void);
int64_t _1318_sum_up(struct1 _1318_xs);

/* Function definitions */
int64_t _1316_main(void){
    int64_t _1316_t1;
    int64_t _1316_t2;
    int64_t _1316_t3;
    int64_t _1316_t4;
    int64_t _1316_t5;
    int64_t _1316_t6;
    struct0 _1317_x;
    int64_t _1316_t8;
    int64_t _1316_t9;
    int64_t* _1316_t10;
    int64_t _1316_t11;
    struct1 _1317_y;
    int64_t _1316_t12;
    uint8_t _1316_t13;
    int64_t _1316_t14;
    int64_t* _1316_t15;
    struct1 _1317_z;
    function2 _1316_t17;
    int64_t _1316_t18;
    int64_t _1316_$retval;
    _1316_t1 = 34;
    _1316_t2 = 25;
    _1316_t3 = 34;
    _1316_t4 = 100;
    _1316_t5 = 8;
    _1316_t6 = 3;
    _1317_x = (struct0) {_1316_t1, _1316_t2, _1316_t3, _1316_t4, _1316_t5, _1316_t6};
    _1316_t8 = 0;
    _1316_t9 = 6;
    $bounds_check(_1316_t8, _1316_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1316_t10 = ((int64_t*)&_1317_x + _1316_t8);
    _1316_t11 = 6;
    _1317_y = (struct1) {_1316_t10, _1316_t11};
    _1316_t12 = 3;
    _1316_t13 = _1316_t12>_1317_y._1;
    if (_1316_t13) {
        goto BB1603;
    } else {
        goto BB1604;
    }
BB1603:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1604:
    _1316_t14 = $sub_int64_t(_1317_y._1, _1316_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1316_t15 = _1317_y._0+_1316_t12;
    _1317_z = (struct1) {_1316_t15, _1316_t14};
    _1316_t17 = _1318_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1316_t18 = _1316_t17(_1317_z);
    $line_idx--;
    _1316_$retval = _1316_t18;
    return _1316_$retval;
}

int64_t _1318_sum_up(struct1 _1318_xs){
    int64_t _1319_sum;
    int64_t _1320_i;
    uint8_t _1318_t3;
    int64_t _1318_t5;
    int64_t _1318_$retval;
    _1319_sum = 0;
    _1320_i = 0;
    goto BB1595;
BB1595:
    _1318_t3 = _1320_i<_1318_xs._1;
    if (_1318_t3) {
        goto BB1596;
    } else {
        goto BB1601;
    }
BB1596:
    $bounds_check(_1320_i, _1318_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1319_sum = $add_int64_t(_1319_sum, *((int64_t*)_1318_xs._0 + _1320_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1318_t5 = 1;
    _1320_i = $add_int64_t(_1320_i, _1318_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1595;
BB1601:
    _1318_$retval = _1319_sum;
    return _1318_$retval;
}

int main(void) {
  printf("%ld",_1316_main());
  return 0;
}
