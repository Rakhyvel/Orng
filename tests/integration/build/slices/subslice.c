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
int64_t _1439_main(void);
int64_t _1441_sum_up(struct struct1 _1441_xs);


/* Function definitions */
int64_t _1439_main(void){
    int64_t _1439_t1;
    int64_t _1439_t2;
    int64_t _1439_t3;
    int64_t _1439_t4;
    int64_t _1439_t5;
    int64_t _1439_t6;
    struct struct0 _1440_x;
    int64_t _1439_t9;
    int64_t _1439_t10;
    int64_t* _1439_t11;
    int64_t _1439_t12;
    struct struct1 _1440_y;
    int64_t _1439_t14;
    int64_t _1439_t17;
    int64_t* _1439_t18;
    struct struct1 _1440_z;
    int64_t _1439_t22;
    function2 _1439_t23;
    int64_t _1439_t24;
    int64_t _1439_$retval;
    _1439_t1 = 1;
    _1439_t2 = 15;
    _1439_t3 = 24;
    _1439_t4 = 4;
    _1439_t5 = 35;
    _1439_t6 = 6;
    _1440_x = (struct struct0) {_1439_t1, _1439_t2, _1439_t3, _1439_t4, _1439_t5, _1439_t6};
    _1439_t9 = 0;
    _1439_t10 = 6;
    $bounds_check(_1439_t9, _1439_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1439_t11 = ((int64_t*)&_1440_x + _1439_t9);
    _1439_t12 = 6;
    _1440_y = (struct struct1) {_1439_t11, _1439_t12};
    _1439_t14 = 1;
    _1439_t17 = 4;
    _1439_t18 = _1440_y._0+_1439_t14;
    _1440_z = (struct struct1) {_1439_t18, _1439_t17};
    _1439_t22 = 2;
    $bounds_check(_1439_t22, _1440_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1440_z._0 + _1439_t22) = 10;
    _1439_t23 = (function2) _1441_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1439_t24 = _1439_t23(_1440_z);
    $line_idx--;
    _1439_$retval = _1439_t24;
    return _1439_$retval;
}

int64_t _1441_sum_up(struct struct1 _1441_xs){
    int64_t _1442_sum;
    int64_t _1443_i;
    uint8_t _1441_t5;
    int64_t _1441_t7;
    int64_t _1441_$retval;
    _1442_sum = 0;
    _1443_i = 0;
    goto BB1683;
BB1683:
    _1441_t5 = _1443_i<_1441_xs._1;
    if (_1441_t5) {
        goto BB1684;
    } else {
        goto BB1689;
    }
BB1684:
    $bounds_check(_1443_i, _1441_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1442_sum = $add_int64_t(_1442_sum, *((int64_t*)_1441_xs._0 + _1443_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1441_t7 = 1;
    _1443_i = $add_int64_t(_1443_i, _1441_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1683;
BB1689:
    _1441_$retval = _1442_sum;
    return _1441_$retval;
}


int main(void) {
  printf("%ld",_1439_main());
  return 0;
}
