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
int64_t _1481_main(void);
int64_t _1483_sum_up(struct struct1 _1483_xs);


/* Function definitions */
int64_t _1481_main(void){
    int64_t _1481_t1;
    int64_t _1481_t2;
    int64_t _1481_t3;
    int64_t _1481_t4;
    int64_t _1481_t5;
    int64_t _1481_t6;
    struct struct0 _1482_x;
    int64_t _1481_t9;
    int64_t _1481_t10;
    int64_t* _1481_t11;
    int64_t _1481_t12;
    struct struct1 _1482_y;
    int64_t _1481_t14;
    int64_t _1481_t17;
    int64_t* _1481_t18;
    struct struct1 _1482_z;
    int64_t _1481_t22;
    function2 _1481_t23;
    int64_t _1481_t24;
    int64_t _1481_$retval;
    _1481_t1 = 1;
    _1481_t2 = 15;
    _1481_t3 = 24;
    _1481_t4 = 4;
    _1481_t5 = 35;
    _1481_t6 = 6;
    _1482_x = (struct struct0) {_1481_t1, _1481_t2, _1481_t3, _1481_t4, _1481_t5, _1481_t6};
    _1481_t9 = 0;
    _1481_t10 = 6;
    $bounds_check(_1481_t9, _1481_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1481_t11 = ((int64_t*)&_1482_x + _1481_t9);
    _1481_t12 = 6;
    _1482_y = (struct struct1) {_1481_t11, _1481_t12};
    _1481_t14 = 1;
    _1481_t17 = 4;
    _1481_t18 = _1482_y._0+_1481_t14;
    _1482_z = (struct struct1) {_1481_t18, _1481_t17};
    _1481_t22 = 2;
    $bounds_check(_1481_t22, _1482_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1482_z._0 + _1481_t22) = 10;
    _1481_t23 = (function2) _1483_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1481_t24 = _1481_t23(_1482_z);
    $line_idx--;
    _1481_$retval = _1481_t24;
    return _1481_$retval;
}

int64_t _1483_sum_up(struct struct1 _1483_xs){
    int64_t _1484_sum;
    int64_t _1485_i;
    uint8_t _1483_t5;
    int64_t _1483_t7;
    int64_t _1483_$retval;
    _1484_sum = 0;
    _1485_i = 0;
    goto BB1727;
BB1727:
    _1483_t5 = _1485_i<_1483_xs._1;
    if (_1483_t5) {
        goto BB1728;
    } else {
        goto BB1733;
    }
BB1728:
    $bounds_check(_1485_i, _1483_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1484_sum = $add_int64_t(_1484_sum, *((int64_t*)_1483_xs._0 + _1485_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1483_t7 = 1;
    _1485_i = $add_int64_t(_1485_i, _1483_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1727;
BB1733:
    _1483_$retval = _1484_sum;
    return _1483_$retval;
}


int main(void) {
  printf("%ld",_1481_main());
  return 0;
}
