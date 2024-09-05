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
int64_t _1424_main(void);
int64_t _1426_sum_up(struct struct1 _1426_xs);


/* Function definitions */
int64_t _1424_main(void){
    int64_t _1424_t1;
    int64_t _1424_t2;
    int64_t _1424_t3;
    int64_t _1424_t4;
    int64_t _1424_t5;
    int64_t _1424_t6;
    struct struct0 _1425_x;
    int64_t _1424_t9;
    int64_t _1424_t10;
    int64_t* _1424_t11;
    int64_t _1424_t12;
    struct struct1 _1425_y;
    int64_t _1424_t14;
    int64_t _1424_t17;
    int64_t* _1424_t18;
    struct struct1 _1425_z;
    int64_t _1424_t22;
    function2 _1424_t23;
    int64_t _1424_t24;
    int64_t _1424_$retval;
    _1424_t1 = 1;
    _1424_t2 = 15;
    _1424_t3 = 24;
    _1424_t4 = 4;
    _1424_t5 = 35;
    _1424_t6 = 6;
    _1425_x = (struct struct0) {_1424_t1, _1424_t2, _1424_t3, _1424_t4, _1424_t5, _1424_t6};
    _1424_t9 = 0;
    _1424_t10 = 6;
    $bounds_check(_1424_t9, _1424_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1424_t11 = ((int64_t*)&_1425_x + _1424_t9);
    _1424_t12 = 6;
    _1425_y = (struct struct1) {_1424_t11, _1424_t12};
    _1424_t14 = 1;
    _1424_t17 = 4;
    _1424_t18 = _1425_y._0+_1424_t14;
    _1425_z = (struct struct1) {_1424_t18, _1424_t17};
    _1424_t22 = 2;
    $bounds_check(_1424_t22, _1425_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1425_z._0 + _1424_t22) = 10;
    _1424_t23 = (function2) _1426_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1424_t24 = _1424_t23(_1425_z);
    $line_idx--;
    _1424_$retval = _1424_t24;
    return _1424_$retval;
}

int64_t _1426_sum_up(struct struct1 _1426_xs){
    int64_t _1427_sum;
    int64_t _1428_i;
    uint8_t _1426_t5;
    int64_t _1426_t7;
    int64_t _1426_$retval;
    _1427_sum = 0;
    _1428_i = 0;
    goto BB1671;
BB1671:
    _1426_t5 = _1428_i<_1426_xs._1;
    if (_1426_t5) {
        goto BB1672;
    } else {
        goto BB1677;
    }
BB1672:
    $bounds_check(_1428_i, _1426_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1427_sum = $add_int64_t(_1427_sum, *((int64_t*)_1426_xs._0 + _1428_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1426_t7 = 1;
    _1428_i = $add_int64_t(_1428_i, _1426_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1671;
BB1677:
    _1426_$retval = _1427_sum;
    return _1426_$retval;
}


int main(void) {
  printf("%ld",_1424_main());
  return 0;
}
