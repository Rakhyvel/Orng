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
int64_t _1447_main(void);
int64_t _1449_sum_up(struct struct1 _1449_xs);


/* Function definitions */
int64_t _1447_main(void){
    int64_t _1447_t1;
    int64_t _1447_t2;
    int64_t _1447_t3;
    int64_t _1447_t4;
    int64_t _1447_t5;
    int64_t _1447_t6;
    struct struct0 _1448_x;
    int64_t _1447_t9;
    int64_t _1447_t10;
    int64_t* _1447_t11;
    int64_t _1447_t12;
    struct struct1 _1448_y;
    int64_t _1447_t14;
    int64_t _1447_t17;
    int64_t* _1447_t18;
    struct struct1 _1448_z;
    int64_t _1447_t22;
    function2 _1447_t23;
    int64_t _1447_t24;
    int64_t _1447_$retval;
    _1447_t1 = 1;
    _1447_t2 = 15;
    _1447_t3 = 24;
    _1447_t4 = 4;
    _1447_t5 = 35;
    _1447_t6 = 6;
    _1448_x = (struct struct0) {_1447_t1, _1447_t2, _1447_t3, _1447_t4, _1447_t5, _1447_t6};
    _1447_t9 = 0;
    _1447_t10 = 6;
    $bounds_check(_1447_t9, _1447_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1447_t11 = ((int64_t*)&_1448_x + _1447_t9);
    _1447_t12 = 6;
    _1448_y = (struct struct1) {_1447_t11, _1447_t12};
    _1447_t14 = 1;
    _1447_t17 = 4;
    _1447_t18 = _1448_y._0+_1447_t14;
    _1448_z = (struct struct1) {_1447_t18, _1447_t17};
    _1447_t22 = 2;
    $bounds_check(_1447_t22, _1448_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1448_z._0 + _1447_t22) = 10;
    _1447_t23 = (function2) _1449_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1447_t24 = _1447_t23(_1448_z);
    $line_idx--;
    _1447_$retval = _1447_t24;
    return _1447_$retval;
}

int64_t _1449_sum_up(struct struct1 _1449_xs){
    int64_t _1450_sum;
    int64_t _1451_i;
    uint8_t _1449_t5;
    int64_t _1449_t7;
    int64_t _1449_$retval;
    _1450_sum = 0;
    _1451_i = 0;
    goto BB1689;
BB1689:
    _1449_t5 = _1451_i<_1449_xs._1;
    if (_1449_t5) {
        goto BB1690;
    } else {
        goto BB1695;
    }
BB1690:
    $bounds_check(_1451_i, _1449_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1450_sum = $add_int64_t(_1450_sum, *((int64_t*)_1449_xs._0 + _1451_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1449_t7 = 1;
    _1451_i = $add_int64_t(_1451_i, _1449_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1689;
BB1695:
    _1449_$retval = _1450_sum;
    return _1449_$retval;
}


int main(void) {
  printf("%ld",_1447_main());
  return 0;
}
