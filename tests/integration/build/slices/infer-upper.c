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
int64_t _1339_main(void);
int64_t _1341_sum_up(struct struct1 _1341_xs);


/* Function definitions */
int64_t _1339_main(void){
    int64_t _1339_t1;
    int64_t _1339_t2;
    int64_t _1339_t3;
    int64_t _1339_t4;
    int64_t _1339_t5;
    int64_t _1339_t6;
    struct struct0 _1340_x;
    int64_t _1339_t8;
    int64_t _1339_t9;
    int64_t* _1339_t10;
    int64_t _1339_t11;
    struct struct1 _1340_y;
    int64_t _1339_t12;
    uint8_t _1339_t13;
    int64_t _1339_t14;
    int64_t* _1339_t15;
    struct struct1 _1340_z;
    function2 _1339_t17;
    int64_t _1339_t18;
    int64_t _1339_$retval;
    _1339_t1 = 34;
    _1339_t2 = 25;
    _1339_t3 = 34;
    _1339_t4 = 100;
    _1339_t5 = 8;
    _1339_t6 = 3;
    _1340_x = (struct struct0) {_1339_t1, _1339_t2, _1339_t3, _1339_t4, _1339_t5, _1339_t6};
    _1339_t8 = 0;
    _1339_t9 = 6;
    $bounds_check(_1339_t8, _1339_t9, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1339_t10 = ((int64_t*)&_1340_x + _1339_t8);
    _1339_t11 = 6;
    _1340_y = (struct struct1) {_1339_t10, _1339_t11};
    _1339_t12 = 3;
    _1339_t13 = _1339_t12>_1340_y._1;
    if (_1339_t13) {
        goto BB1615;
    } else {
        goto BB1616;
    }
BB1615:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1616:
    _1339_t14 = $sub_int64_t(_1340_y._1, _1339_t12, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1339_t15 = _1340_y._0+_1339_t12;
    _1340_z = (struct struct1) {_1339_t15, _1339_t14};
    _1339_t17 = _1341_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1339_t18 = _1339_t17(_1340_z);
    $line_idx--;
    _1339_$retval = _1339_t18;
    return _1339_$retval;
}

int64_t _1341_sum_up(struct struct1 _1341_xs){
    int64_t _1342_sum;
    int64_t _1343_i;
    uint8_t _1341_t3;
    int64_t _1341_t5;
    int64_t _1341_$retval;
    _1342_sum = 0;
    _1343_i = 0;
    goto BB1607;
BB1607:
    _1341_t3 = _1343_i<_1341_xs._1;
    if (_1341_t3) {
        goto BB1608;
    } else {
        goto BB1613;
    }
BB1608:
    $bounds_check(_1343_i, _1341_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1342_sum = $add_int64_t(_1342_sum, *((int64_t*)_1341_xs._0 + _1343_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1341_t5 = 1;
    _1343_i = $add_int64_t(_1343_i, _1341_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1607;
BB1613:
    _1341_$retval = _1342_sum;
    return _1341_$retval;
}


int main(void) {
  printf("%ld",_1339_main());
  return 0;
}
