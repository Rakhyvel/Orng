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
int64_t _1433_main(void);
int64_t _1435_sum_up(struct struct1 _1435_xs);


/* Function definitions */
int64_t _1433_main(void){
    int64_t _1433_t1;
    int64_t _1433_t2;
    int64_t _1433_t3;
    int64_t _1433_t4;
    int64_t _1433_t5;
    int64_t _1433_t6;
    struct struct0 _1434_x;
    int64_t _1433_t9;
    int64_t _1433_t10;
    int64_t* _1433_t11;
    int64_t _1433_t12;
    struct struct1 _1434_y;
    int64_t _1433_t17;
    int64_t* _1433_t18;
    struct struct1 _1434_z;
    function2 _1433_t21;
    int64_t _1433_t22;
    int64_t _1433_$retval;
    _1433_t1 = 100;
    _1433_t2 = 8;
    _1433_t3 = 2;
    _1433_t4 = 4;
    _1433_t5 = 35;
    _1433_t6 = 6;
    _1434_x = (struct struct0) {_1433_t1, _1433_t2, _1433_t3, _1433_t4, _1433_t5, _1433_t6};
    _1433_t9 = 0;
    _1433_t10 = 6;
    $bounds_check(_1433_t9, _1433_t10, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1433_t11 = ((int64_t*)&_1434_x + _1433_t9);
    _1433_t12 = 6;
    _1434_y = (struct struct1) {_1433_t11, _1433_t12};
    _1433_t17 = 3;
    _1433_t18 = _1434_y._0;
    _1434_z = (struct struct1) {_1433_t18, _1433_t17};
    _1433_t21 = (function2) _1435_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1433_t22 = _1433_t21(_1434_z);
    $line_idx--;
    _1433_$retval = _1433_t22;
    return _1433_$retval;
}

int64_t _1435_sum_up(struct struct1 _1435_xs){
    int64_t _1436_sum;
    int64_t _1437_i;
    uint8_t _1435_t5;
    int64_t _1435_t7;
    int64_t _1435_$retval;
    _1436_sum = 0;
    _1437_i = 0;
    goto BB1667;
BB1667:
    _1435_t5 = _1437_i<_1435_xs._1;
    if (_1435_t5) {
        goto BB1668;
    } else {
        goto BB1673;
    }
BB1668:
    $bounds_check(_1437_i, _1435_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1436_sum = $add_int64_t(_1436_sum, *((int64_t*)_1435_xs._0 + _1437_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1435_t7 = 1;
    _1437_i = $add_int64_t(_1437_i, _1435_t7, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1667;
BB1673:
    _1435_$retval = _1436_sum;
    return _1435_$retval;
}


int main(void) {
  printf("%ld",_1433_main());
  return 0;
}
