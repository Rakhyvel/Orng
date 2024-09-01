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
int64_t _1413_main(void);
int64_t _1415_sum_up(struct struct1 _1415_xs);


/* Function definitions */
int64_t _1413_main(void){
    int64_t _1413_t1;
    int64_t _1413_t2;
    int64_t _1413_t3;
    int64_t _1413_t4;
    int64_t _1413_t5;
    int64_t _1413_t6;
    struct struct0 _1414_x;
    int64_t _1413_t9;
    int64_t _1413_t10;
    int64_t* _1413_t11;
    int64_t _1413_t12;
    struct struct1 _1414_y;
    int64_t _1413_t14;
    int64_t _1413_t17;
    int64_t* _1413_t18;
    struct struct1 _1414_z;
    int64_t _1413_t22;
    function2 _1413_t23;
    int64_t _1413_t24;
    int64_t _1413_$retval;
    _1413_t1 = 1;
    _1413_t2 = 15;
    _1413_t3 = 24;
    _1413_t4 = 4;
    _1413_t5 = 35;
    _1413_t6 = 6;
    _1414_x = (struct struct0) {_1413_t1, _1413_t2, _1413_t3, _1413_t4, _1413_t5, _1413_t6};
    _1413_t9 = 0;
    _1413_t10 = 6;
    $bounds_check(_1413_t9, _1413_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1413_t11 = ((int64_t*)&_1414_x + _1413_t9);
    _1413_t12 = 6;
    _1414_y = (struct struct1) {_1413_t11, _1413_t12};
    _1413_t14 = 1;
    _1413_t17 = 4;
    _1413_t18 = _1414_y._0+_1413_t14;
    _1414_z = (struct struct1) {_1413_t18, _1413_t17};
    _1413_t22 = 2;
    $bounds_check(_1413_t22, _1414_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1414_z._0 + _1413_t22) = 10;
    _1413_t23 = (function2) _1415_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1413_t24 = _1413_t23(_1414_z);
    $line_idx--;
    _1413_$retval = _1413_t24;
    return _1413_$retval;
}

int64_t _1415_sum_up(struct struct1 _1415_xs){
    int64_t _1416_sum;
    int64_t _1417_i;
    uint8_t _1415_t5;
    int64_t _1415_t7;
    int64_t _1415_$retval;
    _1416_sum = 0;
    _1417_i = 0;
    goto BB1660;
BB1660:
    _1415_t5 = _1417_i<_1415_xs._1;
    if (_1415_t5) {
        goto BB1661;
    } else {
        goto BB1666;
    }
BB1661:
    $bounds_check(_1417_i, _1415_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1416_sum = $add_int64_t(_1416_sum, *((int64_t*)_1415_xs._0 + _1417_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1415_t7 = 1;
    _1417_i = $add_int64_t(_1417_i, _1415_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1660;
BB1666:
    _1415_$retval = _1416_sum;
    return _1415_$retval;
}


int main(void) {
  printf("%ld",_1413_main());
  return 0;
}
