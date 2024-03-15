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
int64_t _1319_main(void);
int64_t _1321_sum_up(struct struct1 _1321_xs);


/* Function definitions */
int64_t _1319_main(void){
    int64_t _1319_t1;
    int64_t _1319_t2;
    int64_t _1319_t3;
    struct struct0 _1320_x;
    int64_t _1319_t6;
    int64_t _1319_t7;
    int64_t* _1319_t8;
    int64_t _1319_t9;
    struct struct1 _1320_y;
    int64_t _1319_t11;
    uint8_t _1319_t12;
    int64_t _1319_t13;
    int64_t* _1319_t14;
    struct struct1 _1320_z;
    function2 _1319_t17;
    int64_t _1319_t18;
    int64_t _1319_$retval;
    _1319_t1 = 100;
    _1319_t2 = 10;
    _1319_t3 = 1;
    _1320_x = (struct struct0) {_1319_t1, _1319_t2, _1319_t3};
    _1319_t6 = 0;
    _1319_t7 = 3;
    $bounds_check(_1319_t6, _1319_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1319_t8 = ((int64_t*)&_1320_x + _1319_t6);
    _1319_t9 = 3;
    _1320_y = (struct struct1) {_1319_t8, _1319_t9};
    _1319_t11 = 0;
    _1319_t12 = _1319_t11>_1320_y._1;
    if (_1319_t12) {
        goto BB1554;
    } else {
        goto BB1555;
    }
BB1554:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1555:
    _1319_t13 = $sub_int64_t(_1320_y._1, _1319_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1319_t14 = _1320_y._0+_1319_t11;
    _1320_z = (struct struct1) {_1319_t14, _1319_t13};
    _1319_t17 = (function2) _1321_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1319_t18 = _1319_t17(_1320_z);
    $line_idx--;
    _1319_$retval = _1319_t18;
    return _1319_$retval;
}

int64_t _1321_sum_up(struct struct1 _1321_xs){
    int64_t _1322_sum;
    int64_t _1323_i;
    uint8_t _1321_t5;
    int64_t _1321_t7;
    int64_t _1321_$retval;
    _1322_sum = 0;
    _1323_i = 0;
    goto BB1546;
BB1546:
    _1321_t5 = _1323_i<_1321_xs._1;
    if (_1321_t5) {
        goto BB1547;
    } else {
        goto BB1552;
    }
BB1547:
    $bounds_check(_1323_i, _1321_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1322_sum = $add_int64_t(_1322_sum, *((int64_t*)_1321_xs._0 + _1323_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1321_t7 = 1;
    _1323_i = $add_int64_t(_1323_i, _1321_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1546;
BB1552:
    _1321_$retval = _1322_sum;
    return _1321_$retval;
}


int main(void) {
  printf("%ld",_1319_main());
  return 0;
}
