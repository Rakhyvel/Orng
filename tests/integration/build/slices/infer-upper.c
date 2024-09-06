/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
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
int64_t _1407_main(void);
int64_t _1409_sum_up(struct struct1 _1409_xs);


/* Function definitions */
int64_t _1407_main(void){
    int64_t _1407_t1;
    int64_t _1407_t2;
    int64_t _1407_t3;
    int64_t _1407_t4;
    int64_t _1407_t5;
    int64_t _1407_t6;
    struct struct0 _1408_x;
    int64_t _1407_t9;
    int64_t _1407_t10;
    int64_t* _1407_t11;
    int64_t _1407_t12;
    struct struct1 _1408_y;
    int64_t _1407_t14;
    uint8_t _1407_t15;
    int64_t _1407_t16;
    int64_t* _1407_t17;
    struct struct1 _1408_z;
    function2 _1407_t20;
    int64_t _1407_t21;
    int64_t _1407_$retval;
    _1407_t1 = 34;
    _1407_t2 = 25;
    _1407_t3 = 34;
    _1407_t4 = 100;
    _1407_t5 = 8;
    _1407_t6 = 3;
    _1408_x = (struct struct0) {_1407_t1, _1407_t2, _1407_t3, _1407_t4, _1407_t5, _1407_t6};
    _1407_t9 = 0;
    _1407_t10 = 6;
    $bounds_check(_1407_t9, _1407_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1407_t11 = ((int64_t*)&_1408_x + _1407_t9);
    _1407_t12 = 6;
    _1408_y = (struct struct1) {_1407_t11, _1407_t12};
    _1407_t14 = 3;
    _1407_t15 = _1407_t14>_1408_y._1;
    if (_1407_t15) {
        goto BB1657;
    } else {
        goto BB1658;
    }
BB1657:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1658:
    _1407_t16 = $sub_int64_t(_1408_y._1, _1407_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1407_t17 = _1408_y._0+_1407_t14;
    _1408_z = (struct struct1) {_1407_t17, _1407_t16};
    _1407_t20 = (function2) _1409_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1407_t21 = _1407_t20(_1408_z);
    $line_idx--;
    _1407_$retval = _1407_t21;
    return _1407_$retval;
}

int64_t _1409_sum_up(struct struct1 _1409_xs){
    int64_t _1410_sum;
    int64_t _1411_i;
    uint8_t _1409_t5;
    int64_t _1409_t7;
    int64_t _1409_$retval;
    _1410_sum = 0;
    _1411_i = 0;
    goto BB1649;
BB1649:
    _1409_t5 = _1411_i<_1409_xs._1;
    if (_1409_t5) {
        goto BB1650;
    } else {
        goto BB1655;
    }
BB1650:
    $bounds_check(_1411_i, _1409_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1410_sum = $add_int64_t(_1410_sum, *((int64_t*)_1409_xs._0 + _1411_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1409_t7 = 1;
    _1411_i = $add_int64_t(_1411_i, _1409_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1649;
BB1655:
    _1409_$retval = _1410_sum;
    return _1409_$retval;
}


int main(void) {
  printf("%ld",_1407_main());
  return 0;
}
