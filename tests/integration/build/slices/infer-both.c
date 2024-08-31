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
int64_t _1333_main(void);
int64_t _1335_sum_up(struct struct1 _1335_xs);


/* Function definitions */
int64_t _1333_main(void){
    int64_t _1333_t1;
    int64_t _1333_t2;
    int64_t _1333_t3;
    struct struct0 _1334_x;
    int64_t _1333_t6;
    int64_t _1333_t7;
    int64_t* _1333_t8;
    int64_t _1333_t9;
    struct struct1 _1334_y;
    int64_t _1333_t11;
    uint8_t _1333_t12;
    int64_t _1333_t13;
    int64_t* _1333_t14;
    struct struct1 _1334_z;
    function2 _1333_t17;
    int64_t _1333_t18;
    int64_t _1333_$retval;
    _1333_t1 = 100;
    _1333_t2 = 10;
    _1333_t3 = 1;
    _1334_x = (struct struct0) {_1333_t1, _1333_t2, _1333_t3};
    _1333_t6 = 0;
    _1333_t7 = 3;
    $bounds_check(_1333_t6, _1333_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1333_t8 = ((int64_t*)&_1334_x + _1333_t6);
    _1333_t9 = 3;
    _1334_y = (struct struct1) {_1333_t8, _1333_t9};
    _1333_t11 = 0;
    _1333_t12 = _1333_t11>_1334_y._1;
    if (_1333_t12) {
        goto BB1564;
    } else {
        goto BB1565;
    }
BB1564:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1565:
    _1333_t13 = $sub_int64_t(_1334_y._1, _1333_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1333_t14 = _1334_y._0+_1333_t11;
    _1334_z = (struct struct1) {_1333_t14, _1333_t13};
    _1333_t17 = (function2) _1335_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1333_t18 = _1333_t17(_1334_z);
    $line_idx--;
    _1333_$retval = _1333_t18;
    return _1333_$retval;
}

int64_t _1335_sum_up(struct struct1 _1335_xs){
    int64_t _1336_sum;
    int64_t _1337_i;
    uint8_t _1335_t5;
    int64_t _1335_t7;
    int64_t _1335_$retval;
    _1336_sum = 0;
    _1337_i = 0;
    goto BB1556;
BB1556:
    _1335_t5 = _1337_i<_1335_xs._1;
    if (_1335_t5) {
        goto BB1557;
    } else {
        goto BB1562;
    }
BB1557:
    $bounds_check(_1337_i, _1335_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1336_sum = $add_int64_t(_1336_sum, *((int64_t*)_1335_xs._0 + _1337_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1335_t7 = 1;
    _1337_i = $add_int64_t(_1337_i, _1335_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1556;
BB1562:
    _1335_$retval = _1336_sum;
    return _1335_$retval;
}


int main(void) {
  printf("%ld",_1333_main());
  return 0;
}
