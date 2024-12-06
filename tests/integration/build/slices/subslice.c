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
int64_t _1453_main(void);
int64_t _1455_sum_up(struct struct1 _1455_xs);


/* Function definitions */
int64_t _1453_main(void){
    int64_t _1453_t1;
    int64_t _1453_t2;
    int64_t _1453_t3;
    int64_t _1453_t4;
    int64_t _1453_t5;
    int64_t _1453_t6;
    struct struct0 _1454_x;
    int64_t _1453_t9;
    int64_t _1453_t10;
    int64_t* _1453_t11;
    int64_t _1453_t12;
    struct struct1 _1454_y;
    int64_t _1453_t14;
    int64_t _1453_t17;
    int64_t* _1453_t18;
    struct struct1 _1454_z;
    int64_t _1453_t22;
    function2 _1453_t23;
    int64_t _1453_t24;
    int64_t _1453_$retval;
    _1453_t1 = 1;
    _1453_t2 = 15;
    _1453_t3 = 24;
    _1453_t4 = 4;
    _1453_t5 = 35;
    _1453_t6 = 6;
    _1454_x = (struct struct0) {_1453_t1, _1453_t2, _1453_t3, _1453_t4, _1453_t5, _1453_t6};
    _1453_t9 = 0;
    _1453_t10 = 6;
    $bounds_check(_1453_t9, _1453_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1453_t11 = ((int64_t*)&_1454_x + _1453_t9);
    _1453_t12 = 6;
    _1454_y = (struct struct1) {_1453_t11, _1453_t12};
    _1453_t14 = 1;
    _1453_t17 = 4;
    _1453_t18 = _1454_y._0+_1453_t14;
    _1454_z = (struct struct1) {_1453_t18, _1453_t17};
    _1453_t22 = 2;
    $bounds_check(_1453_t22, _1454_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1454_z._0 + _1453_t22) = 10;
    _1453_t23 = (function2) _1455_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1453_t24 = _1453_t23(_1454_z);
    $line_idx--;
    _1453_$retval = _1453_t24;
    return _1453_$retval;
}

int64_t _1455_sum_up(struct struct1 _1455_xs){
    int64_t _1456_sum;
    int64_t _1457_i;
    uint8_t _1455_t5;
    int64_t _1455_t7;
    int64_t _1455_$retval;
    _1456_sum = 0;
    _1457_i = 0;
    goto BB1698;
BB1698:
    _1455_t5 = _1457_i<_1455_xs._1;
    if (_1455_t5) {
        goto BB1699;
    } else {
        goto BB1704;
    }
BB1699:
    $bounds_check(_1457_i, _1455_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1456_sum = $add_int64_t(_1456_sum, *((int64_t*)_1455_xs._0 + _1457_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1455_t7 = 1;
    _1457_i = $add_int64_t(_1457_i, _1455_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1698;
BB1704:
    _1455_$retval = _1456_sum;
    return _1455_$retval;
}


int main(void) {
  printf("%ld",_1453_main());
  return 0;
}
