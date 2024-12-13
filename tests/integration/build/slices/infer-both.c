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
int64_t _1442_main(void);
int64_t _1444_sum_up(struct struct1 _1444_xs);


/* Function definitions */
int64_t _1442_main(void){
    int64_t _1442_t1;
    int64_t _1442_t2;
    int64_t _1442_t3;
    struct struct0 _1443_x;
    int64_t _1442_t6;
    int64_t _1442_t7;
    int64_t* _1442_t8;
    int64_t _1442_t9;
    struct struct1 _1443_y;
    int64_t _1442_t11;
    uint8_t _1442_t12;
    int64_t _1442_t13;
    int64_t* _1442_t14;
    struct struct1 _1443_z;
    function2 _1442_t17;
    int64_t _1442_t18;
    int64_t _1442_$retval;
    _1442_t1 = 100;
    _1442_t2 = 10;
    _1442_t3 = 1;
    _1443_x = (struct struct0) {_1442_t1, _1442_t2, _1442_t3};
    _1442_t6 = 0;
    _1442_t7 = 3;
    $bounds_check(_1442_t6, _1442_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1442_t8 = ((int64_t*)&_1443_x + _1442_t6);
    _1442_t9 = 3;
    _1443_y = (struct struct1) {_1442_t8, _1442_t9};
    _1442_t11 = 0;
    _1442_t12 = _1442_t11>_1443_y._1;
    if (_1442_t12) {
        goto BB1681;
    } else {
        goto BB1682;
    }
BB1681:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1682:
    _1442_t13 = $sub_int64_t(_1443_y._1, _1442_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1442_t14 = _1443_y._0+_1442_t11;
    _1443_z = (struct struct1) {_1442_t14, _1442_t13};
    _1442_t17 = (function2) _1444_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1442_t18 = _1442_t17(_1443_z);
    $line_idx--;
    _1442_$retval = _1442_t18;
    return _1442_$retval;
}

int64_t _1444_sum_up(struct struct1 _1444_xs){
    int64_t _1445_sum;
    int64_t _1446_i;
    uint8_t _1444_t5;
    int64_t _1444_t7;
    int64_t _1444_$retval;
    _1445_sum = 0;
    _1446_i = 0;
    goto BB1673;
BB1673:
    _1444_t5 = _1446_i<_1444_xs._1;
    if (_1444_t5) {
        goto BB1674;
    } else {
        goto BB1679;
    }
BB1674:
    $bounds_check(_1446_i, _1444_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1445_sum = $add_int64_t(_1445_sum, *((int64_t*)_1444_xs._0 + _1446_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1444_t7 = 1;
    _1446_i = $add_int64_t(_1446_i, _1444_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1673;
BB1679:
    _1444_$retval = _1445_sum;
    return _1444_$retval;
}


int main(void) {
  printf("%ld",_1442_main());
  return 0;
}
