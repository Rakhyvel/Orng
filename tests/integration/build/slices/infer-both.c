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
int64_t _1328_main(void);
int64_t _1330_sum_up(struct struct1 _1330_xs);


/* Function definitions */
int64_t _1328_main(void){
    int64_t _1328_t1;
    int64_t _1328_t2;
    int64_t _1328_t3;
    struct struct0 _1329_x;
    int64_t _1328_t6;
    int64_t _1328_t7;
    int64_t* _1328_t8;
    int64_t _1328_t9;
    struct struct1 _1329_y;
    int64_t _1328_t11;
    uint8_t _1328_t12;
    int64_t _1328_t13;
    int64_t* _1328_t14;
    struct struct1 _1329_z;
    function2 _1328_t17;
    int64_t _1328_t18;
    int64_t _1328_$retval;
    _1328_t1 = 100;
    _1328_t2 = 10;
    _1328_t3 = 1;
    _1329_x = (struct struct0) {_1328_t1, _1328_t2, _1328_t3};
    _1328_t6 = 0;
    _1328_t7 = 3;
    $bounds_check(_1328_t6, _1328_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1328_t8 = ((int64_t*)&_1329_x + _1328_t6);
    _1328_t9 = 3;
    _1329_y = (struct struct1) {_1328_t8, _1328_t9};
    _1328_t11 = 0;
    _1328_t12 = _1328_t11>_1329_y._1;
    if (_1328_t12) {
        goto BB1560;
    } else {
        goto BB1561;
    }
BB1560:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1561:
    _1328_t13 = $sub_int64_t(_1329_y._1, _1328_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1328_t14 = _1329_y._0+_1328_t11;
    _1329_z = (struct struct1) {_1328_t14, _1328_t13};
    _1328_t17 = (function2) _1330_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1328_t18 = _1328_t17(_1329_z);
    $line_idx--;
    _1328_$retval = _1328_t18;
    return _1328_$retval;
}

int64_t _1330_sum_up(struct struct1 _1330_xs){
    int64_t _1331_sum;
    int64_t _1332_i;
    uint8_t _1330_t5;
    int64_t _1330_t7;
    int64_t _1330_$retval;
    _1331_sum = 0;
    _1332_i = 0;
    goto BB1552;
BB1552:
    _1330_t5 = _1332_i<_1330_xs._1;
    if (_1330_t5) {
        goto BB1553;
    } else {
        goto BB1558;
    }
BB1553:
    $bounds_check(_1332_i, _1330_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1331_sum = $add_int64_t(_1331_sum, *((int64_t*)_1330_xs._0 + _1332_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1330_t7 = 1;
    _1332_i = $add_int64_t(_1332_i, _1330_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1552;
BB1558:
    _1330_$retval = _1331_sum;
    return _1330_$retval;
}


int main(void) {
  printf("%ld",_1328_main());
  return 0;
}
