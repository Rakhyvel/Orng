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
int64_t _1350_main(void);
int64_t _1352_sum_up(struct struct1 _1352_xs);


/* Function definitions */
int64_t _1350_main(void){
    int64_t _1350_t1;
    int64_t _1350_t2;
    int64_t _1350_t3;
    struct struct0 _1351_x;
    int64_t _1350_t5;
    int64_t _1350_t6;
    int64_t* _1350_t7;
    int64_t _1350_t8;
    struct struct1 _1351_y;
    int64_t _1350_t9;
    uint8_t _1350_t10;
    int64_t _1350_t11;
    int64_t* _1350_t12;
    struct struct1 _1351_z;
    function2 _1350_t14;
    int64_t _1350_t15;
    int64_t _1350_$retval;
    _1350_t1 = 100;
    _1350_t2 = 10;
    _1350_t3 = 1;
    _1351_x = (struct struct0) {_1350_t1, _1350_t2, _1350_t3};
    _1350_t5 = 0;
    _1350_t6 = 3;
    $bounds_check(_1350_t5, _1350_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1350_t7 = ((int64_t*)&_1351_x + _1350_t5);
    _1350_t8 = 3;
    _1351_y = (struct struct1) {_1350_t7, _1350_t8};
    _1350_t9 = 0;
    _1350_t10 = _1350_t9>_1351_y._1;
    if (_1350_t10) {
        goto BB1613;
    } else {
        goto BB1614;
    }
BB1613:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1614:
    _1350_t11 = $sub_int64_t(_1351_y._1, _1350_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1350_t12 = _1351_y._0+_1350_t9;
    _1351_z = (struct struct1) {_1350_t12, _1350_t11};
    _1350_t14 = (function2) _1352_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1350_t15 = _1350_t14(_1351_z);
    $line_idx--;
    _1350_$retval = _1350_t15;
    return _1350_$retval;
}

int64_t _1352_sum_up(struct struct1 _1352_xs){
    int64_t _1353_sum;
    int64_t _1354_i;
    uint8_t _1352_t3;
    int64_t _1352_t5;
    int64_t _1352_$retval;
    _1353_sum = 0;
    _1354_i = 0;
    goto BB1605;
BB1605:
    _1352_t3 = _1354_i<_1352_xs._1;
    if (_1352_t3) {
        goto BB1606;
    } else {
        goto BB1611;
    }
BB1606:
    $bounds_check(_1354_i, _1352_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1353_sum = $add_int64_t(_1353_sum, *((int64_t*)_1352_xs._0 + _1354_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1352_t5 = 1;
    _1354_i = $add_int64_t(_1354_i, _1352_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1605;
BB1611:
    _1352_$retval = _1353_sum;
    return _1352_$retval;
}


int main(void) {
  printf("%ld",_1350_main());
  return 0;
}
