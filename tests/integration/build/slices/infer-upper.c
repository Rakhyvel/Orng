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
int64_t _1366_main(void);
int64_t _1368_sum_up(struct struct1 _1368_xs);


/* Function definitions */
int64_t _1366_main(void){
    int64_t _1366_t1;
    int64_t _1366_t2;
    int64_t _1366_t3;
    int64_t _1366_t4;
    int64_t _1366_t5;
    int64_t _1366_t6;
    struct struct0 _1367_x;
    int64_t _1366_t8;
    int64_t _1366_t9;
    int64_t* _1366_t10;
    int64_t _1366_t11;
    struct struct1 _1367_y;
    int64_t _1366_t12;
    uint8_t _1366_t13;
    int64_t _1366_t14;
    int64_t* _1366_t15;
    struct struct1 _1367_z;
    function2 _1366_t17;
    int64_t _1366_t18;
    int64_t _1366_$retval;
    _1366_t1 = 34;
    _1366_t2 = 25;
    _1366_t3 = 34;
    _1366_t4 = 100;
    _1366_t5 = 8;
    _1366_t6 = 3;
    _1367_x = (struct struct0) {_1366_t1, _1366_t2, _1366_t3, _1366_t4, _1366_t5, _1366_t6};
    _1366_t8 = 0;
    _1366_t9 = 6;
    $bounds_check(_1366_t8, _1366_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1366_t10 = ((int64_t*)&_1367_x + _1366_t8);
    _1366_t11 = 6;
    _1367_y = (struct struct1) {_1366_t10, _1366_t11};
    _1366_t12 = 3;
    _1366_t13 = _1366_t12>_1367_y._1;
    if (_1366_t13) {
        goto BB1637;
    } else {
        goto BB1638;
    }
BB1637:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1638:
    _1366_t14 = $sub_int64_t(_1367_y._1, _1366_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1366_t15 = _1367_y._0+_1366_t12;
    _1367_z = (struct struct1) {_1366_t15, _1366_t14};
    _1366_t17 = (function2) _1368_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1366_t18 = _1366_t17(_1367_z);
    $line_idx--;
    _1366_$retval = _1366_t18;
    return _1366_$retval;
}

int64_t _1368_sum_up(struct struct1 _1368_xs){
    int64_t _1369_sum;
    int64_t _1370_i;
    uint8_t _1368_t3;
    int64_t _1368_t5;
    int64_t _1368_$retval;
    _1369_sum = 0;
    _1370_i = 0;
    goto BB1629;
BB1629:
    _1368_t3 = _1370_i<_1368_xs._1;
    if (_1368_t3) {
        goto BB1630;
    } else {
        goto BB1635;
    }
BB1630:
    $bounds_check(_1370_i, _1368_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1369_sum = $add_int64_t(_1369_sum, *((int64_t*)_1368_xs._0 + _1370_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1368_t5 = 1;
    _1370_i = $add_int64_t(_1370_i, _1368_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1629;
BB1635:
    _1368_$retval = _1369_sum;
    return _1368_$retval;
}


int main(void) {
  printf("%ld",_1366_main());
  return 0;
}
