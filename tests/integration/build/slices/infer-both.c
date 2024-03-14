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
int64_t _1353_main(void);
int64_t _1355_sum_up(struct struct1 _1355_xs);


/* Function definitions */
int64_t _1353_main(void){
    int64_t _1353_t1;
    int64_t _1353_t2;
    int64_t _1353_t3;
    struct struct0 _1354_x;
    int64_t _1353_t6;
    int64_t _1353_t7;
    int64_t* _1353_t8;
    int64_t _1353_t9;
    struct struct1 _1354_y;
    int64_t _1353_t11;
    uint8_t _1353_t12;
    int64_t _1353_t13;
    int64_t* _1353_t14;
    struct struct1 _1354_z;
    function2 _1353_t17;
    int64_t _1353_t18;
    int64_t _1353_$retval;
    _1353_t1 = 100;
    _1353_t2 = 10;
    _1353_t3 = 1;
    _1354_x = (struct struct0) {_1353_t1, _1353_t2, _1353_t3};
    _1353_t6 = 0;
    _1353_t7 = 3;
    $bounds_check(_1353_t6, _1353_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1353_t8 = ((int64_t*)&_1354_x + _1353_t6);
    _1353_t9 = 3;
    _1354_y = (struct struct1) {_1353_t8, _1353_t9};
    _1353_t11 = 0;
    _1353_t12 = _1353_t11>_1354_y._1;
    if (_1353_t12) {
        goto BB1607;
    } else {
        goto BB1608;
    }
BB1607:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1608:
    _1353_t13 = $sub_int64_t(_1354_y._1, _1353_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1353_t14 = _1354_y._0+_1353_t11;
    _1354_z = (struct struct1) {_1353_t14, _1353_t13};
    _1353_t17 = (function2) _1355_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1353_t18 = _1353_t17(_1354_z);
    $line_idx--;
    _1353_$retval = _1353_t18;
    return _1353_$retval;
}

int64_t _1355_sum_up(struct struct1 _1355_xs){
    int64_t _1356_sum;
    int64_t _1357_i;
    uint8_t _1355_t5;
    int64_t _1355_t7;
    int64_t _1355_$retval;
    _1356_sum = 0;
    _1357_i = 0;
    goto BB1599;
BB1599:
    _1355_t5 = _1357_i<_1355_xs._1;
    if (_1355_t5) {
        goto BB1600;
    } else {
        goto BB1605;
    }
BB1600:
    $bounds_check(_1357_i, _1355_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1356_sum = $add_int64_t(_1356_sum, *((int64_t*)_1355_xs._0 + _1357_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1355_t7 = 1;
    _1357_i = $add_int64_t(_1357_i, _1355_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1599;
BB1605:
    _1355_$retval = _1356_sum;
    return _1355_$retval;
}


int main(void) {
  printf("%ld",_1353_main());
  return 0;
}
