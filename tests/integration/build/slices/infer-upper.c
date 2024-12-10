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
int64_t _1456_main(void);
int64_t _1458_sum_up(struct struct1 _1458_xs);


/* Function definitions */
int64_t _1456_main(void){
    int64_t _1456_t1;
    int64_t _1456_t2;
    int64_t _1456_t3;
    int64_t _1456_t4;
    int64_t _1456_t5;
    int64_t _1456_t6;
    struct struct0 _1457_x;
    int64_t _1456_t9;
    int64_t _1456_t10;
    int64_t* _1456_t11;
    int64_t _1456_t12;
    struct struct1 _1457_y;
    int64_t _1456_t14;
    uint8_t _1456_t15;
    int64_t _1456_t16;
    int64_t* _1456_t17;
    struct struct1 _1457_z;
    function2 _1456_t20;
    int64_t _1456_t21;
    int64_t _1456_$retval;
    _1456_t1 = 34;
    _1456_t2 = 25;
    _1456_t3 = 34;
    _1456_t4 = 100;
    _1456_t5 = 8;
    _1456_t6 = 3;
    _1457_x = (struct struct0) {_1456_t1, _1456_t2, _1456_t3, _1456_t4, _1456_t5, _1456_t6};
    _1456_t9 = 0;
    _1456_t10 = 6;
    $bounds_check(_1456_t9, _1456_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1456_t11 = ((int64_t*)&_1457_x + _1456_t9);
    _1456_t12 = 6;
    _1457_y = (struct struct1) {_1456_t11, _1456_t12};
    _1456_t14 = 3;
    _1456_t15 = _1456_t14>_1457_y._1;
    if (_1456_t15) {
        goto BB1703;
    } else {
        goto BB1704;
    }
BB1703:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1704:
    _1456_t16 = $sub_int64_t(_1457_y._1, _1456_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1456_t17 = _1457_y._0+_1456_t14;
    _1457_z = (struct struct1) {_1456_t17, _1456_t16};
    _1456_t20 = (function2) _1458_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1456_t21 = _1456_t20(_1457_z);
    $line_idx--;
    _1456_$retval = _1456_t21;
    return _1456_$retval;
}

int64_t _1458_sum_up(struct struct1 _1458_xs){
    int64_t _1459_sum;
    int64_t _1460_i;
    uint8_t _1458_t5;
    int64_t _1458_t7;
    int64_t _1458_$retval;
    _1459_sum = 0;
    _1460_i = 0;
    goto BB1695;
BB1695:
    _1458_t5 = _1460_i<_1458_xs._1;
    if (_1458_t5) {
        goto BB1696;
    } else {
        goto BB1701;
    }
BB1696:
    $bounds_check(_1460_i, _1458_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1459_sum = $add_int64_t(_1459_sum, *((int64_t*)_1458_xs._0 + _1460_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1458_t7 = 1;
    _1460_i = $add_int64_t(_1460_i, _1458_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1695;
BB1701:
    _1458_$retval = _1459_sum;
    return _1458_$retval;
}


int main(void) {
  printf("%ld",_1456_main());
  return 0;
}
