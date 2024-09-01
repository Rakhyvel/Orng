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
int64_t _1380_main(void);
int64_t _1382_sum_up(struct struct1 _1382_xs);


/* Function definitions */
int64_t _1380_main(void){
    int64_t _1380_t1;
    int64_t _1380_t2;
    int64_t _1380_t3;
    int64_t _1380_t4;
    int64_t _1380_t5;
    int64_t _1380_t6;
    struct struct0 _1381_x;
    int64_t _1380_t9;
    int64_t _1380_t10;
    int64_t* _1380_t11;
    int64_t _1380_t12;
    struct struct1 _1381_y;
    int64_t _1380_t17;
    int64_t* _1380_t18;
    struct struct1 _1381_z;
    function2 _1380_t21;
    int64_t _1380_t22;
    int64_t _1380_$retval;
    _1380_t1 = 100;
    _1380_t2 = 8;
    _1380_t3 = 2;
    _1380_t4 = 4;
    _1380_t5 = 35;
    _1380_t6 = 6;
    _1381_x = (struct struct0) {_1380_t1, _1380_t2, _1380_t3, _1380_t4, _1380_t5, _1380_t6};
    _1380_t9 = 0;
    _1380_t10 = 6;
    $bounds_check(_1380_t9, _1380_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1380_t11 = ((int64_t*)&_1381_x + _1380_t9);
    _1380_t12 = 6;
    _1381_y = (struct struct1) {_1380_t11, _1380_t12};
    _1380_t17 = 3;
    _1380_t18 = _1381_y._0;
    _1381_z = (struct struct1) {_1380_t18, _1380_t17};
    _1380_t21 = (function2) _1382_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1380_t22 = _1380_t21(_1381_z);
    $line_idx--;
    _1380_$retval = _1380_t22;
    return _1380_$retval;
}

int64_t _1382_sum_up(struct struct1 _1382_xs){
    int64_t _1383_sum;
    int64_t _1384_i;
    uint8_t _1382_t5;
    int64_t _1382_t7;
    int64_t _1382_$retval;
    _1383_sum = 0;
    _1384_i = 0;
    goto BB1616;
BB1616:
    _1382_t5 = _1384_i<_1382_xs._1;
    if (_1382_t5) {
        goto BB1617;
    } else {
        goto BB1622;
    }
BB1617:
    $bounds_check(_1384_i, _1382_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1383_sum = $add_int64_t(_1383_sum, *((int64_t*)_1382_xs._0 + _1384_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1382_t7 = 1;
    _1384_i = $add_int64_t(_1384_i, _1382_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1616;
BB1622:
    _1382_$retval = _1383_sum;
    return _1382_$retval;
}


int main(void) {
  printf("%ld",_1380_main());
  return 0;
}
