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
int64_t _1441_main(void);
int64_t _1443_sum_up(struct struct1 _1443_xs);


/* Function definitions */
int64_t _1441_main(void){
    int64_t _1441_t1;
    int64_t _1441_t2;
    int64_t _1441_t3;
    int64_t _1441_t4;
    int64_t _1441_t5;
    int64_t _1441_t6;
    struct struct0 _1442_x;
    int64_t _1441_t9;
    int64_t _1441_t10;
    int64_t* _1441_t11;
    int64_t _1441_t12;
    struct struct1 _1442_y;
    int64_t _1441_t14;
    uint8_t _1441_t15;
    int64_t _1441_t16;
    int64_t* _1441_t17;
    struct struct1 _1442_z;
    function2 _1441_t20;
    int64_t _1441_t21;
    int64_t _1441_$retval;
    _1441_t1 = 34;
    _1441_t2 = 25;
    _1441_t3 = 34;
    _1441_t4 = 100;
    _1441_t5 = 8;
    _1441_t6 = 3;
    _1442_x = (struct struct0) {_1441_t1, _1441_t2, _1441_t3, _1441_t4, _1441_t5, _1441_t6};
    _1441_t9 = 0;
    _1441_t10 = 6;
    $bounds_check(_1441_t9, _1441_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1441_t11 = ((int64_t*)&_1442_x + _1441_t9);
    _1441_t12 = 6;
    _1442_y = (struct struct1) {_1441_t11, _1441_t12};
    _1441_t14 = 3;
    _1441_t15 = _1441_t14>_1442_y._1;
    if (_1441_t15) {
        goto BB1687;
    } else {
        goto BB1688;
    }
BB1687:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1688:
    _1441_t16 = $sub_int64_t(_1442_y._1, _1441_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1441_t17 = _1442_y._0+_1441_t14;
    _1442_z = (struct struct1) {_1441_t17, _1441_t16};
    _1441_t20 = (function2) _1443_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1441_t21 = _1441_t20(_1442_z);
    $line_idx--;
    _1441_$retval = _1441_t21;
    return _1441_$retval;
}

int64_t _1443_sum_up(struct struct1 _1443_xs){
    int64_t _1444_sum;
    int64_t _1445_i;
    uint8_t _1443_t5;
    int64_t _1443_t7;
    int64_t _1443_$retval;
    _1444_sum = 0;
    _1445_i = 0;
    goto BB1679;
BB1679:
    _1443_t5 = _1445_i<_1443_xs._1;
    if (_1443_t5) {
        goto BB1680;
    } else {
        goto BB1685;
    }
BB1680:
    $bounds_check(_1445_i, _1443_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1444_sum = $add_int64_t(_1444_sum, *((int64_t*)_1443_xs._0 + _1445_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1443_t7 = 1;
    _1445_i = $add_int64_t(_1445_i, _1443_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1679;
BB1685:
    _1443_$retval = _1444_sum;
    return _1443_$retval;
}


int main(void) {
  printf("%ld",_1441_main());
  return 0;
}
