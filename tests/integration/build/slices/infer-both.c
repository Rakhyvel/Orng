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
int64_t _1391_main(void);
int64_t _1393_sum_up(struct struct1 _1393_xs);


/* Function definitions */
int64_t _1391_main(void){
    int64_t _1391_t1;
    int64_t _1391_t2;
    int64_t _1391_t3;
    struct struct0 _1392_x;
    int64_t _1391_t6;
    int64_t _1391_t7;
    int64_t* _1391_t8;
    int64_t _1391_t9;
    struct struct1 _1392_y;
    int64_t _1391_t11;
    uint8_t _1391_t12;
    int64_t _1391_t13;
    int64_t* _1391_t14;
    struct struct1 _1392_z;
    function2 _1391_t17;
    int64_t _1391_t18;
    int64_t _1391_$retval;
    _1391_t1 = 100;
    _1391_t2 = 10;
    _1391_t3 = 1;
    _1392_x = (struct struct0) {_1391_t1, _1391_t2, _1391_t3};
    _1391_t6 = 0;
    _1391_t7 = 3;
    $bounds_check(_1391_t6, _1391_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1391_t8 = ((int64_t*)&_1392_x + _1391_t6);
    _1391_t9 = 3;
    _1392_y = (struct struct1) {_1391_t8, _1391_t9};
    _1391_t11 = 0;
    _1391_t12 = _1391_t11>_1392_y._1;
    if (_1391_t12) {
        goto BB1629;
    } else {
        goto BB1630;
    }
BB1629:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1630:
    _1391_t13 = $sub_int64_t(_1392_y._1, _1391_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1391_t14 = _1392_y._0+_1391_t11;
    _1392_z = (struct struct1) {_1391_t14, _1391_t13};
    _1391_t17 = (function2) _1393_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1391_t18 = _1391_t17(_1392_z);
    $line_idx--;
    _1391_$retval = _1391_t18;
    return _1391_$retval;
}

int64_t _1393_sum_up(struct struct1 _1393_xs){
    int64_t _1394_sum;
    int64_t _1395_i;
    uint8_t _1393_t5;
    int64_t _1393_t7;
    int64_t _1393_$retval;
    _1394_sum = 0;
    _1395_i = 0;
    goto BB1621;
BB1621:
    _1393_t5 = _1395_i<_1393_xs._1;
    if (_1393_t5) {
        goto BB1622;
    } else {
        goto BB1627;
    }
BB1622:
    $bounds_check(_1395_i, _1393_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1394_sum = $add_int64_t(_1394_sum, *((int64_t*)_1393_xs._0 + _1395_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1393_t7 = 1;
    _1395_i = $add_int64_t(_1395_i, _1393_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1621;
BB1627:
    _1393_$retval = _1394_sum;
    return _1393_$retval;
}


int main(void) {
  printf("%ld",_1391_main());
  return 0;
}
