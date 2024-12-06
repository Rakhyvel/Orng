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
int64_t _1412_main(void);
int64_t _1414_sum_up(struct struct1 _1414_xs);


/* Function definitions */
int64_t _1412_main(void){
    int64_t _1412_t1;
    int64_t _1412_t2;
    int64_t _1412_t3;
    struct struct0 _1413_x;
    int64_t _1412_t6;
    int64_t _1412_t7;
    int64_t* _1412_t8;
    int64_t _1412_t9;
    struct struct1 _1413_y;
    int64_t _1412_t11;
    uint8_t _1412_t12;
    int64_t _1412_t13;
    int64_t* _1412_t14;
    struct struct1 _1413_z;
    function2 _1412_t17;
    int64_t _1412_t18;
    int64_t _1412_$retval;
    _1412_t1 = 100;
    _1412_t2 = 10;
    _1412_t3 = 1;
    _1413_x = (struct struct0) {_1412_t1, _1412_t2, _1412_t3};
    _1412_t6 = 0;
    _1412_t7 = 3;
    $bounds_check(_1412_t6, _1412_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1412_t8 = ((int64_t*)&_1413_x + _1412_t6);
    _1412_t9 = 3;
    _1413_y = (struct struct1) {_1412_t8, _1412_t9};
    _1412_t11 = 0;
    _1412_t12 = _1412_t11>_1413_y._1;
    if (_1412_t12) {
        goto BB1650;
    } else {
        goto BB1651;
    }
BB1650:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1651:
    _1412_t13 = $sub_int64_t(_1413_y._1, _1412_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1412_t14 = _1413_y._0+_1412_t11;
    _1413_z = (struct struct1) {_1412_t14, _1412_t13};
    _1412_t17 = (function2) _1414_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1412_t18 = _1412_t17(_1413_z);
    $line_idx--;
    _1412_$retval = _1412_t18;
    return _1412_$retval;
}

int64_t _1414_sum_up(struct struct1 _1414_xs){
    int64_t _1415_sum;
    int64_t _1416_i;
    uint8_t _1414_t5;
    int64_t _1414_t7;
    int64_t _1414_$retval;
    _1415_sum = 0;
    _1416_i = 0;
    goto BB1642;
BB1642:
    _1414_t5 = _1416_i<_1414_xs._1;
    if (_1414_t5) {
        goto BB1643;
    } else {
        goto BB1648;
    }
BB1643:
    $bounds_check(_1416_i, _1414_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1415_sum = $add_int64_t(_1415_sum, *((int64_t*)_1414_xs._0 + _1416_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1414_t7 = 1;
    _1416_i = $add_int64_t(_1416_i, _1414_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1642;
BB1648:
    _1414_$retval = _1415_sum;
    return _1414_$retval;
}


int main(void) {
  printf("%ld",_1412_main());
  return 0;
}
