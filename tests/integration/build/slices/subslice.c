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
int64_t _1442_main(void);
int64_t _1444_sum_up(struct struct1 _1444_xs);


/* Function definitions */
int64_t _1442_main(void){
    int64_t _1442_t1;
    int64_t _1442_t2;
    int64_t _1442_t3;
    int64_t _1442_t4;
    int64_t _1442_t5;
    int64_t _1442_t6;
    struct struct0 _1443_x;
    int64_t _1442_t9;
    int64_t _1442_t10;
    int64_t* _1442_t11;
    int64_t _1442_t12;
    struct struct1 _1443_y;
    int64_t _1442_t14;
    int64_t _1442_t17;
    int64_t* _1442_t18;
    struct struct1 _1443_z;
    int64_t _1442_t22;
    function2 _1442_t23;
    int64_t _1442_t24;
    int64_t _1442_$retval;
    _1442_t1 = 1;
    _1442_t2 = 15;
    _1442_t3 = 24;
    _1442_t4 = 4;
    _1442_t5 = 35;
    _1442_t6 = 6;
    _1443_x = (struct struct0) {_1442_t1, _1442_t2, _1442_t3, _1442_t4, _1442_t5, _1442_t6};
    _1442_t9 = 0;
    _1442_t10 = 6;
    $bounds_check(_1442_t9, _1442_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1442_t11 = ((int64_t*)&_1443_x + _1442_t9);
    _1442_t12 = 6;
    _1443_y = (struct struct1) {_1442_t11, _1442_t12};
    _1442_t14 = 1;
    _1442_t17 = 4;
    _1442_t18 = _1443_y._0+_1442_t14;
    _1443_z = (struct struct1) {_1442_t18, _1442_t17};
    _1442_t22 = 2;
    $bounds_check(_1442_t22, _1443_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1443_z._0 + _1442_t22) = 10;
    _1442_t23 = (function2) _1444_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1442_t24 = _1442_t23(_1443_z);
    $line_idx--;
    _1442_$retval = _1442_t24;
    return _1442_$retval;
}

int64_t _1444_sum_up(struct struct1 _1444_xs){
    int64_t _1445_sum;
    int64_t _1446_i;
    uint8_t _1444_t5;
    int64_t _1444_t7;
    int64_t _1444_$retval;
    _1445_sum = 0;
    _1446_i = 0;
    goto BB1685;
BB1685:
    _1444_t5 = _1446_i<_1444_xs._1;
    if (_1444_t5) {
        goto BB1686;
    } else {
        goto BB1691;
    }
BB1686:
    $bounds_check(_1446_i, _1444_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1445_sum = $add_int64_t(_1445_sum, *((int64_t*)_1444_xs._0 + _1446_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1444_t7 = 1;
    _1446_i = $add_int64_t(_1446_i, _1444_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1685;
BB1691:
    _1444_$retval = _1445_sum;
    return _1444_$retval;
}


int main(void) {
  printf("%ld",_1442_main());
  return 0;
}
