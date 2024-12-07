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
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1420_main(void);
int64_t _1422_sum_up(struct struct1 _1422_xs);


/* Function definitions */
int64_t _1420_main(void){
    int64_t _1420_t1;
    int64_t _1420_t2;
    int64_t _1420_t3;
    struct struct0 _1421_x;
    int64_t _1420_t6;
    int64_t _1420_t7;
    int64_t* _1420_t8;
    int64_t _1420_t9;
    struct struct1 _1421_y;
    int64_t _1420_t11;
    uint8_t _1420_t12;
    int64_t _1420_t13;
    int64_t* _1420_t14;
    struct struct1 _1421_z;
    function2 _1420_t17;
    int64_t _1420_t18;
    int64_t _1420_$retval;
    _1420_t1 = 100;
    _1420_t2 = 10;
    _1420_t3 = 1;
    _1421_x = (struct struct0) {_1420_t1, _1420_t2, _1420_t3};
    _1420_t6 = 0;
    _1420_t7 = 3;
    $bounds_check(_1420_t6, _1420_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1420_t8 = ((int64_t*)&_1421_x + _1420_t6);
    _1420_t9 = 3;
    _1421_y = (struct struct1) {_1420_t8, _1420_t9};
    _1420_t11 = 0;
    _1420_t12 = _1420_t11>_1421_y._1;
    if (_1420_t12) {
        goto BB1660;
    } else {
        goto BB1661;
    }
BB1660:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1661:
    _1420_t13 = $sub_int64_t(_1421_y._1, _1420_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1420_t14 = _1421_y._0+_1420_t11;
    _1421_z = (struct struct1) {_1420_t14, _1420_t13};
    _1420_t17 = (function2) _1422_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1420_t18 = _1420_t17(_1421_z);
    $line_idx--;
    _1420_$retval = _1420_t18;
    return _1420_$retval;
}

int64_t _1422_sum_up(struct struct1 _1422_xs){
    int64_t _1423_sum;
    int64_t _1424_i;
    uint8_t _1422_t5;
    int64_t _1422_t7;
    int64_t _1422_$retval;
    _1423_sum = 0;
    _1424_i = 0;
    goto BB1652;
BB1652:
    _1422_t5 = _1424_i<_1422_xs._1;
    if (_1422_t5) {
        goto BB1653;
    } else {
        goto BB1658;
    }
BB1653:
    $bounds_check(_1424_i, _1422_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1423_sum = $add_int64_t(_1423_sum, *((int64_t*)_1422_xs._0 + _1424_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1422_t7 = 1;
    _1424_i = $add_int64_t(_1424_i, _1422_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1652;
BB1658:
    _1422_$retval = _1423_sum;
    return _1422_$retval;
}


int main(void) {
  printf("%ld",_1420_main());
  return 0;
}
