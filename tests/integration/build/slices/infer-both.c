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
int64_t _1396_main(void);
int64_t _1398_sum_up(struct struct1 _1398_xs);


/* Function definitions */
int64_t _1396_main(void){
    int64_t _1396_t1;
    int64_t _1396_t2;
    int64_t _1396_t3;
    struct struct0 _1397_x;
    int64_t _1396_t6;
    int64_t _1396_t7;
    int64_t* _1396_t8;
    int64_t _1396_t9;
    struct struct1 _1397_y;
    int64_t _1396_t11;
    uint8_t _1396_t12;
    int64_t _1396_t13;
    int64_t* _1396_t14;
    struct struct1 _1397_z;
    function2 _1396_t17;
    int64_t _1396_t18;
    int64_t _1396_$retval;
    _1396_t1 = 100;
    _1396_t2 = 10;
    _1396_t3 = 1;
    _1397_x = (struct struct0) {_1396_t1, _1396_t2, _1396_t3};
    _1396_t6 = 0;
    _1396_t7 = 3;
    $bounds_check(_1396_t6, _1396_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1396_t8 = ((int64_t*)&_1397_x + _1396_t6);
    _1396_t9 = 3;
    _1397_y = (struct struct1) {_1396_t8, _1396_t9};
    _1396_t11 = 0;
    _1396_t12 = _1396_t11>_1397_y._1;
    if (_1396_t12) {
        goto BB1633;
    } else {
        goto BB1634;
    }
BB1633:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1634:
    _1396_t13 = $sub_int64_t(_1397_y._1, _1396_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1396_t14 = _1397_y._0+_1396_t11;
    _1397_z = (struct struct1) {_1396_t14, _1396_t13};
    _1396_t17 = (function2) _1398_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1396_t18 = _1396_t17(_1397_z);
    $line_idx--;
    _1396_$retval = _1396_t18;
    return _1396_$retval;
}

int64_t _1398_sum_up(struct struct1 _1398_xs){
    int64_t _1399_sum;
    int64_t _1400_i;
    uint8_t _1398_t5;
    int64_t _1398_t7;
    int64_t _1398_$retval;
    _1399_sum = 0;
    _1400_i = 0;
    goto BB1625;
BB1625:
    _1398_t5 = _1400_i<_1398_xs._1;
    if (_1398_t5) {
        goto BB1626;
    } else {
        goto BB1631;
    }
BB1626:
    $bounds_check(_1400_i, _1398_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1399_sum = $add_int64_t(_1399_sum, *((int64_t*)_1398_xs._0 + _1400_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1398_t7 = 1;
    _1400_i = $add_int64_t(_1400_i, _1398_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1625;
BB1631:
    _1398_$retval = _1399_sum;
    return _1398_$retval;
}


int main(void) {
  printf("%ld",_1396_main());
  return 0;
}
