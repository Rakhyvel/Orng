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
int64_t _1369_main(void);
int64_t _1371_sum_up(struct struct1 _1371_xs);


/* Function definitions */
int64_t _1369_main(void){
    int64_t _1369_t1;
    int64_t _1369_t2;
    int64_t _1369_t3;
    int64_t _1369_t4;
    int64_t _1369_t5;
    int64_t _1369_t6;
    struct struct0 _1370_x;
    int64_t _1369_t9;
    int64_t _1369_t10;
    int64_t* _1369_t11;
    int64_t _1369_t12;
    struct struct1 _1370_y;
    int64_t _1369_t14;
    int64_t _1369_t17;
    int64_t* _1369_t18;
    struct struct1 _1370_z;
    int64_t _1369_t22;
    function2 _1369_t23;
    int64_t _1369_t24;
    int64_t _1369_$retval;
    _1369_t1 = 1;
    _1369_t2 = 15;
    _1369_t3 = 24;
    _1369_t4 = 4;
    _1369_t5 = 35;
    _1369_t6 = 6;
    _1370_x = (struct struct0) {_1369_t1, _1369_t2, _1369_t3, _1369_t4, _1369_t5, _1369_t6};
    _1369_t9 = 0;
    _1369_t10 = 6;
    $bounds_check(_1369_t9, _1369_t10, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1369_t11 = ((int64_t*)&_1370_x + _1369_t9);
    _1369_t12 = 6;
    _1370_y = (struct struct1) {_1369_t11, _1369_t12};
    _1369_t14 = 1;
    _1369_t17 = 4;
    _1369_t18 = _1370_y._0+_1369_t14;
    _1370_z = (struct struct1) {_1369_t18, _1369_t17};
    _1369_t22 = 2;
    $bounds_check(_1369_t22, _1370_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1370_z._0 + _1369_t22) = 10;
    _1369_t23 = (function2) _1371_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1369_t24 = _1369_t23(_1370_z);
    $line_idx--;
    _1369_$retval = _1369_t24;
    return _1369_$retval;
}

int64_t _1371_sum_up(struct struct1 _1371_xs){
    int64_t _1372_sum;
    int64_t _1373_i;
    uint8_t _1371_t5;
    int64_t _1371_t7;
    int64_t _1371_$retval;
    _1372_sum = 0;
    _1373_i = 0;
    goto BB1608;
BB1608:
    _1371_t5 = _1373_i<_1371_xs._1;
    if (_1371_t5) {
        goto BB1609;
    } else {
        goto BB1614;
    }
BB1609:
    $bounds_check(_1373_i, _1371_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1372_sum = $add_int64_t(_1372_sum, *((int64_t*)_1371_xs._0 + _1373_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1371_t7 = 1;
    _1373_i = $add_int64_t(_1373_i, _1371_t7, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1608;
BB1614:
    _1371_$retval = _1372_sum;
    return _1371_$retval;
}


int main(void) {
  printf("%ld",_1369_main());
  return 0;
}
