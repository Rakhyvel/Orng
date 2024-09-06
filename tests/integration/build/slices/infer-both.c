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
int64_t _1383_main(void);
int64_t _1385_sum_up(struct struct1 _1385_xs);


/* Function definitions */
int64_t _1383_main(void){
    int64_t _1383_t1;
    int64_t _1383_t2;
    int64_t _1383_t3;
    struct struct0 _1384_x;
    int64_t _1383_t6;
    int64_t _1383_t7;
    int64_t* _1383_t8;
    int64_t _1383_t9;
    struct struct1 _1384_y;
    int64_t _1383_t11;
    uint8_t _1383_t12;
    int64_t _1383_t13;
    int64_t* _1383_t14;
    struct struct1 _1384_z;
    function2 _1383_t17;
    int64_t _1383_t18;
    int64_t _1383_$retval;
    _1383_t1 = 100;
    _1383_t2 = 10;
    _1383_t3 = 1;
    _1384_x = (struct struct0) {_1383_t1, _1383_t2, _1383_t3};
    _1383_t6 = 0;
    _1383_t7 = 3;
    $bounds_check(_1383_t6, _1383_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1383_t8 = ((int64_t*)&_1384_x + _1383_t6);
    _1383_t9 = 3;
    _1384_y = (struct struct1) {_1383_t8, _1383_t9};
    _1383_t11 = 0;
    _1383_t12 = _1383_t11>_1384_y._1;
    if (_1383_t12) {
        goto BB1623;
    } else {
        goto BB1624;
    }
BB1623:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1624:
    _1383_t13 = $sub_int64_t(_1384_y._1, _1383_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1383_t14 = _1384_y._0+_1383_t11;
    _1384_z = (struct struct1) {_1383_t14, _1383_t13};
    _1383_t17 = (function2) _1385_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1383_t18 = _1383_t17(_1384_z);
    $line_idx--;
    _1383_$retval = _1383_t18;
    return _1383_$retval;
}

int64_t _1385_sum_up(struct struct1 _1385_xs){
    int64_t _1386_sum;
    int64_t _1387_i;
    uint8_t _1385_t5;
    int64_t _1385_t7;
    int64_t _1385_$retval;
    _1386_sum = 0;
    _1387_i = 0;
    goto BB1615;
BB1615:
    _1385_t5 = _1387_i<_1385_xs._1;
    if (_1385_t5) {
        goto BB1616;
    } else {
        goto BB1621;
    }
BB1616:
    $bounds_check(_1387_i, _1385_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1386_sum = $add_int64_t(_1386_sum, *((int64_t*)_1385_xs._0 + _1387_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1385_t7 = 1;
    _1387_i = $add_int64_t(_1387_i, _1385_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1615;
BB1621:
    _1385_$retval = _1386_sum;
    return _1385_$retval;
}


int main(void) {
  printf("%ld",_1383_main());
  return 0;
}
