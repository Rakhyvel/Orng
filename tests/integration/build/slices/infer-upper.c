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
int64_t _1344_main(void);
int64_t _1346_sum_up(struct struct1 _1346_xs);


/* Function definitions */
int64_t _1344_main(void){
    int64_t _1344_t1;
    int64_t _1344_t2;
    int64_t _1344_t3;
    int64_t _1344_t4;
    int64_t _1344_t5;
    int64_t _1344_t6;
    struct struct0 _1345_x;
    int64_t _1344_t9;
    int64_t _1344_t10;
    int64_t* _1344_t11;
    int64_t _1344_t12;
    struct struct1 _1345_y;
    int64_t _1344_t14;
    uint8_t _1344_t15;
    int64_t _1344_t16;
    int64_t* _1344_t17;
    struct struct1 _1345_z;
    function2 _1344_t20;
    int64_t _1344_t21;
    int64_t _1344_$retval;
    _1344_t1 = 34;
    _1344_t2 = 25;
    _1344_t3 = 34;
    _1344_t4 = 100;
    _1344_t5 = 8;
    _1344_t6 = 3;
    _1345_x = (struct struct0) {_1344_t1, _1344_t2, _1344_t3, _1344_t4, _1344_t5, _1344_t6};
    _1344_t9 = 0;
    _1344_t10 = 6;
    $bounds_check(_1344_t9, _1344_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1344_t11 = ((int64_t*)&_1345_x + _1344_t9);
    _1344_t12 = 6;
    _1345_y = (struct struct1) {_1344_t11, _1344_t12};
    _1344_t14 = 3;
    _1344_t15 = _1344_t14>_1345_y._1;
    if (_1344_t15) {
        goto BB1584;
    } else {
        goto BB1585;
    }
BB1584:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1585:
    _1344_t16 = $sub_int64_t(_1345_y._1, _1344_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1344_t17 = _1345_y._0+_1344_t14;
    _1345_z = (struct struct1) {_1344_t17, _1344_t16};
    _1344_t20 = (function2) _1346_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1344_t21 = _1344_t20(_1345_z);
    $line_idx--;
    _1344_$retval = _1344_t21;
    return _1344_$retval;
}

int64_t _1346_sum_up(struct struct1 _1346_xs){
    int64_t _1347_sum;
    int64_t _1348_i;
    uint8_t _1346_t5;
    int64_t _1346_t7;
    int64_t _1346_$retval;
    _1347_sum = 0;
    _1348_i = 0;
    goto BB1576;
BB1576:
    _1346_t5 = _1348_i<_1346_xs._1;
    if (_1346_t5) {
        goto BB1577;
    } else {
        goto BB1582;
    }
BB1577:
    $bounds_check(_1348_i, _1346_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1347_sum = $add_int64_t(_1347_sum, *((int64_t*)_1346_xs._0 + _1348_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1346_t7 = 1;
    _1348_i = $add_int64_t(_1348_i, _1346_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1576;
BB1582:
    _1346_$retval = _1347_sum;
    return _1346_$retval;
}


int main(void) {
  printf("%ld",_1344_main());
  return 0;
}
