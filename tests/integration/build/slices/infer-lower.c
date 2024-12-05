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
int64_t _1414_main(void);
int64_t _1416_sum_up(struct struct1 _1416_xs);


/* Function definitions */
int64_t _1414_main(void){
    int64_t _1414_t1;
    int64_t _1414_t2;
    int64_t _1414_t3;
    int64_t _1414_t4;
    int64_t _1414_t5;
    int64_t _1414_t6;
    struct struct0 _1415_x;
    int64_t _1414_t9;
    int64_t _1414_t10;
    int64_t* _1414_t11;
    int64_t _1414_t12;
    struct struct1 _1415_y;
    int64_t _1414_t17;
    int64_t* _1414_t18;
    struct struct1 _1415_z;
    function2 _1414_t21;
    int64_t _1414_t22;
    int64_t _1414_$retval;
    _1414_t1 = 100;
    _1414_t2 = 8;
    _1414_t3 = 2;
    _1414_t4 = 4;
    _1414_t5 = 35;
    _1414_t6 = 6;
    _1415_x = (struct struct0) {_1414_t1, _1414_t2, _1414_t3, _1414_t4, _1414_t5, _1414_t6};
    _1414_t9 = 0;
    _1414_t10 = 6;
    $bounds_check(_1414_t9, _1414_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1414_t11 = ((int64_t*)&_1415_x + _1414_t9);
    _1414_t12 = 6;
    _1415_y = (struct struct1) {_1414_t11, _1414_t12};
    _1414_t17 = 3;
    _1414_t18 = _1415_y._0;
    _1415_z = (struct struct1) {_1414_t18, _1414_t17};
    _1414_t21 = (function2) _1416_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1414_t22 = _1414_t21(_1415_z);
    $line_idx--;
    _1414_$retval = _1414_t22;
    return _1414_$retval;
}

int64_t _1416_sum_up(struct struct1 _1416_xs){
    int64_t _1417_sum;
    int64_t _1418_i;
    uint8_t _1416_t5;
    int64_t _1416_t7;
    int64_t _1416_$retval;
    _1417_sum = 0;
    _1418_i = 0;
    goto BB1645;
BB1645:
    _1416_t5 = _1418_i<_1416_xs._1;
    if (_1416_t5) {
        goto BB1646;
    } else {
        goto BB1651;
    }
BB1646:
    $bounds_check(_1418_i, _1416_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1417_sum = $add_int64_t(_1417_sum, *((int64_t*)_1416_xs._0 + _1418_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1416_t7 = 1;
    _1418_i = $add_int64_t(_1418_i, _1416_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1645;
BB1651:
    _1416_$retval = _1417_sum;
    return _1416_$retval;
}


int main(void) {
  printf("%ld",_1414_main());
  return 0;
}
