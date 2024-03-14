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
int64_t _1369_main(void);
int64_t _1371_sum_up(struct struct1 _1371_xs);


/* Function definitions */
int64_t _1369_main(void){
    int64_t _1369_t1;
    int64_t _1369_t2;
    int64_t _1369_t3;
    int64_t _1369_t4;
    int64_t _1369_t5;
    int64_t _1369_t6;
    struct struct0 _1370_x;
    int64_t _1369_t9;
    int64_t _1369_t10;
    int64_t* _1369_t11;
    int64_t _1369_t12;
    struct struct1 _1370_y;
    int64_t _1369_t14;
    uint8_t _1369_t15;
    int64_t _1369_t16;
    int64_t* _1369_t17;
    struct struct1 _1370_z;
    function2 _1369_t20;
    int64_t _1369_t21;
    int64_t _1369_$retval;
    _1369_t1 = 34;
    _1369_t2 = 25;
    _1369_t3 = 34;
    _1369_t4 = 100;
    _1369_t5 = 8;
    _1369_t6 = 3;
    _1370_x = (struct struct0) {_1369_t1, _1369_t2, _1369_t3, _1369_t4, _1369_t5, _1369_t6};
    _1369_t9 = 0;
    _1369_t10 = 6;
    $bounds_check(_1369_t9, _1369_t10, "tests/integration/slices/infer-upper.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1369_t11 = ((int64_t*)&_1370_x + _1369_t9);
    _1369_t12 = 6;
    _1370_y = (struct struct1) {_1369_t11, _1369_t12};
    _1369_t14 = 3;
    _1369_t15 = _1369_t14>_1370_y._1;
    if (_1369_t15) {
        goto BB1631;
    } else {
        goto BB1632;
    }
BB1631:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1632:
    _1369_t16 = $sub_int64_t(_1370_y._1, _1369_t14, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _1369_t17 = _1370_y._0+_1369_t14;
    _1370_z = (struct struct1) {_1369_t17, _1369_t16};
    _1369_t20 = (function2) _1371_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _1369_t21 = _1369_t20(_1370_z);
    $line_idx--;
    _1369_$retval = _1369_t21;
    return _1369_$retval;
}

int64_t _1371_sum_up(struct struct1 _1371_xs){
    int64_t _1372_sum;
    int64_t _1373_i;
    uint8_t _1371_t5;
    int64_t _1371_t7;
    int64_t _1371_$retval;
    _1372_sum = 0;
    _1373_i = 0;
    goto BB1623;
BB1623:
    _1371_t5 = _1373_i<_1371_xs._1;
    if (_1371_t5) {
        goto BB1624;
    } else {
        goto BB1629;
    }
BB1624:
    $bounds_check(_1373_i, _1371_xs._1, "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1372_sum = $add_int64_t(_1372_sum, *((int64_t*)_1371_xs._0 + _1373_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _1371_t7 = 1;
    _1373_i = $add_int64_t(_1373_i, _1371_t7, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1623;
BB1629:
    _1371_$retval = _1372_sum;
    return _1371_$retval;
}


int main(void) {
  printf("%ld",_1369_main());
  return 0;
}
