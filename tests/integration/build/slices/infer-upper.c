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
    int64_t _3;
    int64_t _4;
    int64_t _5;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1335_main(void);
int64_t _1337_sum_up(struct struct1 _1337_xs);


/* Function definitions */
int64_t _1335_main(void){
    int64_t _1335_t1;
    int64_t _1335_t2;
    int64_t _1335_t3;
    int64_t _1335_t4;
    int64_t _1335_t5;
    int64_t _1335_t6;
    struct struct0 _1336_x;
    int64_t _1335_t9;
    int64_t _1335_t10;
    int64_t* _1335_t11;
    int64_t _1335_t12;
    struct struct1 _1336_y;
    int64_t _1335_t14;
    uint8_t _1335_t15;
    int64_t _1335_t16;
    int64_t* _1335_t17;
    struct struct1 _1336_z;
    function2 _1335_t20;
    int64_t _1335_t21;
    int64_t _1335_$retval;
    _1335_t1 = 34;
    _1335_t2 = 25;
    _1335_t3 = 34;
    _1335_t4 = 100;
    _1335_t5 = 8;
    _1335_t6 = 3;
    _1336_x = (struct struct0) {_1335_t1, _1335_t2, _1335_t3, _1335_t4, _1335_t5, _1335_t6};
    _1335_t9 = 0;
    _1335_t10 = 6;
    $bounds_check(_1335_t9, _1335_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1335_t11 = ((int64_t*)&_1336_x + _1335_t9);
    _1335_t12 = 6;
    _1336_y = (struct struct1) {_1335_t11, _1335_t12};
    _1335_t14 = 3;
    _1335_t15 = _1335_t14>_1336_y._1;
    if (_1335_t15) {
        goto BB1578;
    } else {
        goto BB1579;
    }
BB1578:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1579:
    _1335_t16 = $sub_int64_t(_1336_y._1, _1335_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1335_t17 = _1336_y._0+_1335_t14;
    _1336_z = (struct struct1) {_1335_t17, _1335_t16};
    _1335_t20 = (function2) _1337_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1335_t21 = _1335_t20(_1336_z);
    $line_idx--;
    _1335_$retval = _1335_t21;
    return _1335_$retval;
}

int64_t _1337_sum_up(struct struct1 _1337_xs){
    int64_t _1338_sum;
    int64_t _1339_i;
    uint8_t _1337_t5;
    int64_t _1337_t7;
    int64_t _1337_$retval;
    _1338_sum = 0;
    _1339_i = 0;
    goto BB1570;
BB1570:
    _1337_t5 = _1339_i<_1337_xs._1;
    if (_1337_t5) {
        goto BB1571;
    } else {
        goto BB1576;
    }
BB1571:
    $bounds_check(_1339_i, _1337_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1338_sum = $add_int64_t(_1338_sum, *((int64_t*)_1337_xs._0 + _1339_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1337_t7 = 1;
    _1339_i = $add_int64_t(_1339_i, _1337_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1570;
BB1576:
    _1337_$retval = _1338_sum;
    return _1337_$retval;
}


int main(void) {
  printf("%ld",_1335_main());
  return 0;
}
