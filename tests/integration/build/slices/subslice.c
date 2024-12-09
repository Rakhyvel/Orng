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
int64_t _1466_main(void);
int64_t _1468_sum_up(struct struct1 _1468_xs);


/* Function definitions */
int64_t _1466_main(void){
    int64_t _1466_t1;
    int64_t _1466_t2;
    int64_t _1466_t3;
    int64_t _1466_t4;
    int64_t _1466_t5;
    int64_t _1466_t6;
    struct struct0 _1467_x;
    int64_t _1466_t9;
    int64_t _1466_t10;
    int64_t* _1466_t11;
    int64_t _1466_t12;
    struct struct1 _1467_y;
    int64_t _1466_t14;
    int64_t _1466_t17;
    int64_t* _1466_t18;
    struct struct1 _1467_z;
    int64_t _1466_t22;
    function2 _1466_t23;
    int64_t _1466_t24;
    int64_t _1466_$retval;
    _1466_t1 = 1;
    _1466_t2 = 15;
    _1466_t3 = 24;
    _1466_t4 = 4;
    _1466_t5 = 35;
    _1466_t6 = 6;
    _1467_x = (struct struct0) {_1466_t1, _1466_t2, _1466_t3, _1466_t4, _1466_t5, _1466_t6};
    _1466_t9 = 0;
    _1466_t10 = 6;
    $bounds_check(_1466_t9, _1466_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1466_t11 = ((int64_t*)&_1467_x + _1466_t9);
    _1466_t12 = 6;
    _1467_y = (struct struct1) {_1466_t11, _1466_t12};
    _1466_t14 = 1;
    _1466_t17 = 4;
    _1466_t18 = _1467_y._0+_1466_t14;
    _1467_z = (struct struct1) {_1466_t18, _1466_t17};
    _1466_t22 = 2;
    $bounds_check(_1466_t22, _1467_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1467_z._0 + _1466_t22) = 10;
    _1466_t23 = (function2) _1468_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1466_t24 = _1466_t23(_1467_z);
    $line_idx--;
    _1466_$retval = _1466_t24;
    return _1466_$retval;
}

int64_t _1468_sum_up(struct struct1 _1468_xs){
    int64_t _1469_sum;
    int64_t _1470_i;
    uint8_t _1468_t5;
    int64_t _1468_t7;
    int64_t _1468_$retval;
    _1469_sum = 0;
    _1470_i = 0;
    goto BB1711;
BB1711:
    _1468_t5 = _1470_i<_1468_xs._1;
    if (_1468_t5) {
        goto BB1712;
    } else {
        goto BB1717;
    }
BB1712:
    $bounds_check(_1470_i, _1468_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1469_sum = $add_int64_t(_1469_sum, *((int64_t*)_1468_xs._0 + _1470_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1468_t7 = 1;
    _1470_i = $add_int64_t(_1470_i, _1468_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1711;
BB1717:
    _1468_$retval = _1469_sum;
    return _1468_$retval;
}


int main(void) {
  printf("%ld",_1466_main());
  return 0;
}
