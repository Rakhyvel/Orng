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
int64_t _1483_main(void);
int64_t _1485_sum_up(struct struct1 _1485_xs);


/* Function definitions */
int64_t _1483_main(void){
    int64_t _1483_t1;
    int64_t _1483_t2;
    int64_t _1483_t3;
    int64_t _1483_t4;
    int64_t _1483_t5;
    int64_t _1483_t6;
    struct struct0 _1484_x;
    int64_t _1483_t9;
    int64_t _1483_t10;
    int64_t* _1483_t11;
    int64_t _1483_t12;
    struct struct1 _1484_y;
    int64_t _1483_t14;
    int64_t _1483_t17;
    int64_t* _1483_t18;
    struct struct1 _1484_z;
    int64_t _1483_t22;
    function2 _1483_t23;
    int64_t _1483_t24;
    int64_t _1483_$retval;
    _1483_t1 = 1;
    _1483_t2 = 15;
    _1483_t3 = 24;
    _1483_t4 = 4;
    _1483_t5 = 35;
    _1483_t6 = 6;
    _1484_x = (struct struct0) {_1483_t1, _1483_t2, _1483_t3, _1483_t4, _1483_t5, _1483_t6};
    _1483_t9 = 0;
    _1483_t10 = 6;
    $bounds_check(_1483_t9, _1483_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1483_t11 = ((int64_t*)&_1484_x + _1483_t9);
    _1483_t12 = 6;
    _1484_y = (struct struct1) {_1483_t11, _1483_t12};
    _1483_t14 = 1;
    _1483_t17 = 4;
    _1483_t18 = _1484_y._0+_1483_t14;
    _1484_z = (struct struct1) {_1483_t18, _1483_t17};
    _1483_t22 = 2;
    $bounds_check(_1483_t22, _1484_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1484_z._0 + _1483_t22) = 10;
    _1483_t23 = (function2) _1485_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1483_t24 = _1483_t23(_1484_z);
    $line_idx--;
    _1483_$retval = _1483_t24;
    return _1483_$retval;
}

int64_t _1485_sum_up(struct struct1 _1485_xs){
    int64_t _1486_sum;
    int64_t _1487_i;
    uint8_t _1485_t5;
    int64_t _1485_t7;
    int64_t _1485_$retval;
    _1486_sum = 0;
    _1487_i = 0;
    goto BB1729;
BB1729:
    _1485_t5 = _1487_i<_1485_xs._1;
    if (_1485_t5) {
        goto BB1730;
    } else {
        goto BB1735;
    }
BB1730:
    $bounds_check(_1487_i, _1485_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1486_sum = $add_int64_t(_1486_sum, *((int64_t*)_1485_xs._0 + _1487_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1485_t7 = 1;
    _1487_i = $add_int64_t(_1487_i, _1485_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1729;
BB1735:
    _1485_$retval = _1486_sum;
    return _1485_$retval;
}


int main(void) {
  printf("%ld",_1483_main());
  return 0;
}
