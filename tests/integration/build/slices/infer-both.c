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
int64_t _1440_main(void);
int64_t _1442_sum_up(struct struct1 _1442_xs);


/* Function definitions */
int64_t _1440_main(void){
    int64_t _1440_t1;
    int64_t _1440_t2;
    int64_t _1440_t3;
    struct struct0 _1441_x;
    int64_t _1440_t6;
    int64_t _1440_t7;
    int64_t* _1440_t8;
    int64_t _1440_t9;
    struct struct1 _1441_y;
    int64_t _1440_t11;
    uint8_t _1440_t12;
    int64_t _1440_t13;
    int64_t* _1440_t14;
    struct struct1 _1441_z;
    function2 _1440_t17;
    int64_t _1440_t18;
    int64_t _1440_$retval;
    _1440_t1 = 100;
    _1440_t2 = 10;
    _1440_t3 = 1;
    _1441_x = (struct struct0) {_1440_t1, _1440_t2, _1440_t3};
    _1440_t6 = 0;
    _1440_t7 = 3;
    $bounds_check(_1440_t6, _1440_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1440_t8 = ((int64_t*)&_1441_x + _1440_t6);
    _1440_t9 = 3;
    _1441_y = (struct struct1) {_1440_t8, _1440_t9};
    _1440_t11 = 0;
    _1440_t12 = _1440_t11>_1441_y._1;
    if (_1440_t12) {
        goto BB1679;
    } else {
        goto BB1680;
    }
BB1679:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1680:
    _1440_t13 = $sub_int64_t(_1441_y._1, _1440_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1440_t14 = _1441_y._0+_1440_t11;
    _1441_z = (struct struct1) {_1440_t14, _1440_t13};
    _1440_t17 = (function2) _1442_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1440_t18 = _1440_t17(_1441_z);
    $line_idx--;
    _1440_$retval = _1440_t18;
    return _1440_$retval;
}

int64_t _1442_sum_up(struct struct1 _1442_xs){
    int64_t _1443_sum;
    int64_t _1444_i;
    uint8_t _1442_t5;
    int64_t _1442_t7;
    int64_t _1442_$retval;
    _1443_sum = 0;
    _1444_i = 0;
    goto BB1671;
BB1671:
    _1442_t5 = _1444_i<_1442_xs._1;
    if (_1442_t5) {
        goto BB1672;
    } else {
        goto BB1677;
    }
BB1672:
    $bounds_check(_1444_i, _1442_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1443_sum = $add_int64_t(_1443_sum, *((int64_t*)_1442_xs._0 + _1444_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1442_t7 = 1;
    _1444_i = $add_int64_t(_1444_i, _1442_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1671;
BB1677:
    _1442_$retval = _1443_sum;
    return _1442_$retval;
}


int main(void) {
  printf("%ld",_1440_main());
  return 0;
}
