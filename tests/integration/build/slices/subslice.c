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
int64_t _1432_main(void);
int64_t _1434_sum_up(struct struct1 _1434_xs);


/* Function definitions */
int64_t _1432_main(void){
    int64_t _1432_t1;
    int64_t _1432_t2;
    int64_t _1432_t3;
    int64_t _1432_t4;
    int64_t _1432_t5;
    int64_t _1432_t6;
    struct struct0 _1433_x;
    int64_t _1432_t9;
    int64_t _1432_t10;
    int64_t* _1432_t11;
    int64_t _1432_t12;
    struct struct1 _1433_y;
    int64_t _1432_t14;
    int64_t _1432_t17;
    int64_t* _1432_t18;
    struct struct1 _1433_z;
    int64_t _1432_t22;
    function2 _1432_t23;
    int64_t _1432_t24;
    int64_t _1432_$retval;
    _1432_t1 = 1;
    _1432_t2 = 15;
    _1432_t3 = 24;
    _1432_t4 = 4;
    _1432_t5 = 35;
    _1432_t6 = 6;
    _1433_x = (struct struct0) {_1432_t1, _1432_t2, _1432_t3, _1432_t4, _1432_t5, _1432_t6};
    _1432_t9 = 0;
    _1432_t10 = 6;
    $bounds_check(_1432_t9, _1432_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1432_t11 = ((int64_t*)&_1433_x + _1432_t9);
    _1432_t12 = 6;
    _1433_y = (struct struct1) {_1432_t11, _1432_t12};
    _1432_t14 = 1;
    _1432_t17 = 4;
    _1432_t18 = _1433_y._0+_1432_t14;
    _1433_z = (struct struct1) {_1432_t18, _1432_t17};
    _1432_t22 = 2;
    $bounds_check(_1432_t22, _1433_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1433_z._0 + _1432_t22) = 10;
    _1432_t23 = (function2) _1434_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1432_t24 = _1432_t23(_1433_z);
    $line_idx--;
    _1432_$retval = _1432_t24;
    return _1432_$retval;
}

int64_t _1434_sum_up(struct struct1 _1434_xs){
    int64_t _1435_sum;
    int64_t _1436_i;
    uint8_t _1434_t5;
    int64_t _1434_t7;
    int64_t _1434_$retval;
    _1435_sum = 0;
    _1436_i = 0;
    goto BB1677;
BB1677:
    _1434_t5 = _1436_i<_1434_xs._1;
    if (_1434_t5) {
        goto BB1678;
    } else {
        goto BB1683;
    }
BB1678:
    $bounds_check(_1436_i, _1434_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1435_sum = $add_int64_t(_1435_sum, *((int64_t*)_1434_xs._0 + _1436_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1434_t7 = 1;
    _1436_i = $add_int64_t(_1436_i, _1434_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1677;
BB1683:
    _1434_$retval = _1435_sum;
    return _1434_$retval;
}


int main(void) {
  printf("%ld",_1432_main());
  return 0;
}
