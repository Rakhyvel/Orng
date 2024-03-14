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
int64_t _1394_main(void);
int64_t _1396_sum_up(struct struct1 _1396_xs);


/* Function definitions */
int64_t _1394_main(void){
    int64_t _1394_t1;
    int64_t _1394_t2;
    int64_t _1394_t3;
    int64_t _1394_t4;
    int64_t _1394_t5;
    int64_t _1394_t6;
    struct struct0 _1395_x;
    int64_t _1394_t9;
    int64_t _1394_t10;
    int64_t* _1394_t11;
    int64_t _1394_t12;
    struct struct1 _1395_y;
    int64_t _1394_t14;
    int64_t _1394_t17;
    int64_t* _1394_t18;
    struct struct1 _1395_z;
    int64_t _1394_t22;
    function2 _1394_t23;
    int64_t _1394_t24;
    int64_t _1394_$retval;
    _1394_t1 = 1;
    _1394_t2 = 15;
    _1394_t3 = 24;
    _1394_t4 = 4;
    _1394_t5 = 35;
    _1394_t6 = 6;
    _1395_x = (struct struct0) {_1394_t1, _1394_t2, _1394_t3, _1394_t4, _1394_t5, _1394_t6};
    _1394_t9 = 0;
    _1394_t10 = 6;
    $bounds_check(_1394_t9, _1394_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1394_t11 = ((int64_t*)&_1395_x + _1394_t9);
    _1394_t12 = 6;
    _1395_y = (struct struct1) {_1394_t11, _1394_t12};
    _1394_t14 = 1;
    _1394_t17 = 4;
    _1394_t18 = _1395_y._0+_1394_t14;
    _1395_z = (struct struct1) {_1394_t18, _1394_t17};
    _1394_t22 = 2;
    $bounds_check(_1394_t22, _1395_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1395_z._0 + _1394_t22) = 10;
    _1394_t23 = (function2) _1396_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1394_t24 = _1394_t23(_1395_z);
    $line_idx--;
    _1394_$retval = _1394_t24;
    return _1394_$retval;
}

int64_t _1396_sum_up(struct struct1 _1396_xs){
    int64_t _1397_sum;
    int64_t _1398_i;
    uint8_t _1396_t5;
    int64_t _1396_t7;
    int64_t _1396_$retval;
    _1397_sum = 0;
    _1398_i = 0;
    goto BB1655;
BB1655:
    _1396_t5 = _1398_i<_1396_xs._1;
    if (_1396_t5) {
        goto BB1656;
    } else {
        goto BB1661;
    }
BB1656:
    $bounds_check(_1398_i, _1396_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1397_sum = $add_int64_t(_1397_sum, *((int64_t*)_1396_xs._0 + _1398_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1396_t7 = 1;
    _1398_i = $add_int64_t(_1398_i, _1396_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1655;
BB1661:
    _1396_$retval = _1397_sum;
    return _1396_$retval;
}


int main(void) {
  printf("%ld",_1394_main());
  return 0;
}
