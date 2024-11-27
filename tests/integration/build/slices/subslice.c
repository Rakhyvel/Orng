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
int64_t _1437_main(void);
int64_t _1439_sum_up(struct struct1 _1439_xs);


/* Function definitions */
int64_t _1437_main(void){
    int64_t _1437_t1;
    int64_t _1437_t2;
    int64_t _1437_t3;
    int64_t _1437_t4;
    int64_t _1437_t5;
    int64_t _1437_t6;
    struct struct0 _1438_x;
    int64_t _1437_t9;
    int64_t _1437_t10;
    int64_t* _1437_t11;
    int64_t _1437_t12;
    struct struct1 _1438_y;
    int64_t _1437_t14;
    int64_t _1437_t17;
    int64_t* _1437_t18;
    struct struct1 _1438_z;
    int64_t _1437_t22;
    function2 _1437_t23;
    int64_t _1437_t24;
    int64_t _1437_$retval;
    _1437_t1 = 1;
    _1437_t2 = 15;
    _1437_t3 = 24;
    _1437_t4 = 4;
    _1437_t5 = 35;
    _1437_t6 = 6;
    _1438_x = (struct struct0) {_1437_t1, _1437_t2, _1437_t3, _1437_t4, _1437_t5, _1437_t6};
    _1437_t9 = 0;
    _1437_t10 = 6;
    $bounds_check(_1437_t9, _1437_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1437_t11 = ((int64_t*)&_1438_x + _1437_t9);
    _1437_t12 = 6;
    _1438_y = (struct struct1) {_1437_t11, _1437_t12};
    _1437_t14 = 1;
    _1437_t17 = 4;
    _1437_t18 = _1438_y._0+_1437_t14;
    _1438_z = (struct struct1) {_1437_t18, _1437_t17};
    _1437_t22 = 2;
    $bounds_check(_1437_t22, _1438_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1438_z._0 + _1437_t22) = 10;
    _1437_t23 = (function2) _1439_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1437_t24 = _1437_t23(_1438_z);
    $line_idx--;
    _1437_$retval = _1437_t24;
    return _1437_$retval;
}

int64_t _1439_sum_up(struct struct1 _1439_xs){
    int64_t _1440_sum;
    int64_t _1441_i;
    uint8_t _1439_t5;
    int64_t _1439_t7;
    int64_t _1439_$retval;
    _1440_sum = 0;
    _1441_i = 0;
    goto BB1681;
BB1681:
    _1439_t5 = _1441_i<_1439_xs._1;
    if (_1439_t5) {
        goto BB1682;
    } else {
        goto BB1687;
    }
BB1682:
    $bounds_check(_1441_i, _1439_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1440_sum = $add_int64_t(_1440_sum, *((int64_t*)_1439_xs._0 + _1441_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1439_t7 = 1;
    _1441_i = $add_int64_t(_1441_i, _1439_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1681;
BB1687:
    _1439_$retval = _1440_sum;
    return _1439_$retval;
}


int main(void) {
  printf("%ld",_1437_main());
  return 0;
}
