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
int64_t _1401_main(void);
int64_t _1403_sum_up(struct struct1 _1403_xs);


/* Function definitions */
int64_t _1401_main(void){
    int64_t _1401_t1;
    int64_t _1401_t2;
    int64_t _1401_t3;
    struct struct0 _1402_x;
    int64_t _1401_t6;
    int64_t _1401_t7;
    int64_t* _1401_t8;
    int64_t _1401_t9;
    struct struct1 _1402_y;
    int64_t _1401_t11;
    uint8_t _1401_t12;
    int64_t _1401_t13;
    int64_t* _1401_t14;
    struct struct1 _1402_z;
    function2 _1401_t17;
    int64_t _1401_t18;
    int64_t _1401_$retval;
    _1401_t1 = 100;
    _1401_t2 = 10;
    _1401_t3 = 1;
    _1402_x = (struct struct0) {_1401_t1, _1401_t2, _1401_t3};
    _1401_t6 = 0;
    _1401_t7 = 3;
    $bounds_check(_1401_t6, _1401_t7, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1401_t8 = ((int64_t*)&_1402_x + _1401_t6);
    _1401_t9 = 3;
    _1402_y = (struct struct1) {_1401_t8, _1401_t9};
    _1401_t11 = 0;
    _1401_t12 = _1401_t11>_1402_y._1;
    if (_1401_t12) {
        goto BB1637;
    } else {
        goto BB1638;
    }
BB1637:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1638:
    _1401_t13 = $sub_int64_t(_1402_y._1, _1401_t11, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1401_t14 = _1402_y._0+_1401_t11;
    _1402_z = (struct struct1) {_1401_t14, _1401_t13};
    _1401_t17 = (function2) _1403_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1401_t18 = _1401_t17(_1402_z);
    $line_idx--;
    _1401_$retval = _1401_t18;
    return _1401_$retval;
}

int64_t _1403_sum_up(struct struct1 _1403_xs){
    int64_t _1404_sum;
    int64_t _1405_i;
    uint8_t _1403_t5;
    int64_t _1403_t7;
    int64_t _1403_$retval;
    _1404_sum = 0;
    _1405_i = 0;
    goto BB1629;
BB1629:
    _1403_t5 = _1405_i<_1403_xs._1;
    if (_1403_t5) {
        goto BB1630;
    } else {
        goto BB1635;
    }
BB1630:
    $bounds_check(_1405_i, _1403_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1404_sum = $add_int64_t(_1404_sum, *((int64_t*)_1403_xs._0 + _1405_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1403_t7 = 1;
    _1405_i = $add_int64_t(_1405_i, _1403_t7, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1629;
BB1635:
    _1403_$retval = _1404_sum;
    return _1403_$retval;
}


int main(void) {
  printf("%ld",_1401_main());
  return 0;
}
