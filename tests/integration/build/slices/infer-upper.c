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
int64_t _1388_main(void);
int64_t _1390_sum_up(struct struct1 _1390_xs);


/* Function definitions */
int64_t _1388_main(void){
    int64_t _1388_t1;
    int64_t _1388_t2;
    int64_t _1388_t3;
    int64_t _1388_t4;
    int64_t _1388_t5;
    int64_t _1388_t6;
    struct struct0 _1389_x;
    int64_t _1388_t9;
    int64_t _1388_t10;
    int64_t* _1388_t11;
    int64_t _1388_t12;
    struct struct1 _1389_y;
    int64_t _1388_t14;
    uint8_t _1388_t15;
    int64_t _1388_t16;
    int64_t* _1388_t17;
    struct struct1 _1389_z;
    function2 _1388_t20;
    int64_t _1388_t21;
    int64_t _1388_$retval;
    _1388_t1 = 34;
    _1388_t2 = 25;
    _1388_t3 = 34;
    _1388_t4 = 100;
    _1388_t5 = 8;
    _1388_t6 = 3;
    _1389_x = (struct struct0) {_1388_t1, _1388_t2, _1388_t3, _1388_t4, _1388_t5, _1388_t6};
    _1388_t9 = 0;
    _1388_t10 = 6;
    $bounds_check(_1388_t9, _1388_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1388_t11 = ((int64_t*)&_1389_x + _1388_t9);
    _1388_t12 = 6;
    _1389_y = (struct struct1) {_1388_t11, _1388_t12};
    _1388_t14 = 3;
    _1388_t15 = _1388_t14>_1389_y._1;
    if (_1388_t15) {
        goto BB1636;
    } else {
        goto BB1637;
    }
BB1636:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1637:
    _1388_t16 = $sub_int64_t(_1389_y._1, _1388_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1388_t17 = _1389_y._0+_1388_t14;
    _1389_z = (struct struct1) {_1388_t17, _1388_t16};
    _1388_t20 = (function2) _1390_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1388_t21 = _1388_t20(_1389_z);
    $line_idx--;
    _1388_$retval = _1388_t21;
    return _1388_$retval;
}

int64_t _1390_sum_up(struct struct1 _1390_xs){
    int64_t _1391_sum;
    int64_t _1392_i;
    uint8_t _1390_t5;
    int64_t _1390_t7;
    int64_t _1390_$retval;
    _1391_sum = 0;
    _1392_i = 0;
    goto BB1628;
BB1628:
    _1390_t5 = _1392_i<_1390_xs._1;
    if (_1390_t5) {
        goto BB1629;
    } else {
        goto BB1634;
    }
BB1629:
    $bounds_check(_1392_i, _1390_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1391_sum = $add_int64_t(_1391_sum, *((int64_t*)_1390_xs._0 + _1392_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1390_t7 = 1;
    _1392_i = $add_int64_t(_1392_i, _1390_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1628;
BB1634:
    _1390_$retval = _1391_sum;
    return _1390_$retval;
}


int main(void) {
  printf("%ld",_1388_main());
  return 0;
}
