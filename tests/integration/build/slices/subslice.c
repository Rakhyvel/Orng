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
int64_t _1374_main(void);
int64_t _1376_sum_up(struct struct1 _1376_xs);


/* Function definitions */
int64_t _1374_main(void){
    int64_t _1374_t1;
    int64_t _1374_t2;
    int64_t _1374_t3;
    int64_t _1374_t4;
    int64_t _1374_t5;
    int64_t _1374_t6;
    struct struct0 _1375_x;
    int64_t _1374_t9;
    int64_t _1374_t10;
    int64_t* _1374_t11;
    int64_t _1374_t12;
    struct struct1 _1375_y;
    int64_t _1374_t14;
    int64_t _1374_t17;
    int64_t* _1374_t18;
    struct struct1 _1375_z;
    int64_t _1374_t22;
    function2 _1374_t23;
    int64_t _1374_t24;
    int64_t _1374_$retval;
    _1374_t1 = 1;
    _1374_t2 = 15;
    _1374_t3 = 24;
    _1374_t4 = 4;
    _1374_t5 = 35;
    _1374_t6 = 6;
    _1375_x = (struct struct0) {_1374_t1, _1374_t2, _1374_t3, _1374_t4, _1374_t5, _1374_t6};
    _1374_t9 = 0;
    _1374_t10 = 6;
    $bounds_check(_1374_t9, _1374_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1374_t11 = ((int64_t*)&_1375_x + _1374_t9);
    _1374_t12 = 6;
    _1375_y = (struct struct1) {_1374_t11, _1374_t12};
    _1374_t14 = 1;
    _1374_t17 = 4;
    _1374_t18 = _1375_y._0+_1374_t14;
    _1375_z = (struct struct1) {_1374_t18, _1374_t17};
    _1374_t22 = 2;
    $bounds_check(_1374_t22, _1375_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1375_z._0 + _1374_t22) = 10;
    _1374_t23 = (function2) _1376_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1374_t24 = _1374_t23(_1375_z);
    $line_idx--;
    _1374_$retval = _1374_t24;
    return _1374_$retval;
}

int64_t _1376_sum_up(struct struct1 _1376_xs){
    int64_t _1377_sum;
    int64_t _1378_i;
    uint8_t _1376_t5;
    int64_t _1376_t7;
    int64_t _1376_$retval;
    _1377_sum = 0;
    _1378_i = 0;
    goto BB1612;
BB1612:
    _1376_t5 = _1378_i<_1376_xs._1;
    if (_1376_t5) {
        goto BB1613;
    } else {
        goto BB1618;
    }
BB1613:
    $bounds_check(_1378_i, _1376_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1377_sum = $add_int64_t(_1377_sum, *((int64_t*)_1376_xs._0 + _1378_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1376_t7 = 1;
    _1378_i = $add_int64_t(_1378_i, _1376_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1612;
BB1618:
    _1376_$retval = _1377_sum;
    return _1376_$retval;
}


int main(void) {
  printf("%ld",_1374_main());
  return 0;
}
