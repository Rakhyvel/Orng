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
int64_t _1341_main(void);
int64_t _1343_sum_up(struct struct1 _1343_xs);


/* Function definitions */
int64_t _1341_main(void){
    int64_t _1341_t1;
    int64_t _1341_t2;
    int64_t _1341_t3;
    int64_t _1341_t4;
    int64_t _1341_t5;
    int64_t _1341_t6;
    struct struct0 _1342_x;
    int64_t _1341_t9;
    int64_t _1341_t10;
    int64_t* _1341_t11;
    int64_t _1341_t12;
    struct struct1 _1342_y;
    int64_t _1341_t17;
    int64_t* _1341_t18;
    struct struct1 _1342_z;
    function2 _1341_t21;
    int64_t _1341_t22;
    int64_t _1341_$retval;
    _1341_t1 = 100;
    _1341_t2 = 8;
    _1341_t3 = 2;
    _1341_t4 = 4;
    _1341_t5 = 35;
    _1341_t6 = 6;
    _1342_x = (struct struct0) {_1341_t1, _1341_t2, _1341_t3, _1341_t4, _1341_t5, _1341_t6};
    _1341_t9 = 0;
    _1341_t10 = 6;
    $bounds_check(_1341_t9, _1341_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1341_t11 = ((int64_t*)&_1342_x + _1341_t9);
    _1341_t12 = 6;
    _1342_y = (struct struct1) {_1341_t11, _1341_t12};
    _1341_t17 = 3;
    _1341_t18 = _1342_y._0;
    _1342_z = (struct struct1) {_1341_t18, _1341_t17};
    _1341_t21 = (function2) _1343_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1341_t22 = _1341_t21(_1342_z);
    $line_idx--;
    _1341_$retval = _1341_t22;
    return _1341_$retval;
}

int64_t _1343_sum_up(struct struct1 _1343_xs){
    int64_t _1344_sum;
    int64_t _1345_i;
    uint8_t _1343_t5;
    int64_t _1343_t7;
    int64_t _1343_$retval;
    _1344_sum = 0;
    _1345_i = 0;
    goto BB1568;
BB1568:
    _1343_t5 = _1345_i<_1343_xs._1;
    if (_1343_t5) {
        goto BB1569;
    } else {
        goto BB1574;
    }
BB1569:
    $bounds_check(_1345_i, _1343_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1344_sum = $add_int64_t(_1344_sum, *((int64_t*)_1343_xs._0 + _1345_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1343_t7 = 1;
    _1345_i = $add_int64_t(_1345_i, _1343_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1568;
BB1574:
    _1343_$retval = _1344_sum;
    return _1343_$retval;
}


int main(void) {
  printf("%ld",_1341_main());
  return 0;
}
