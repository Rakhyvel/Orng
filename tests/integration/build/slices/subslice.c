/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1344_main(void);
int64_t _1346_sum_up(struct struct1 _1346_xs);

/* Function definitions */
int64_t _1344_main(void){
    int64_t _1344_t1;
    int64_t _1344_t2;
    int64_t _1344_t3;
    int64_t _1344_t4;
    int64_t _1344_t5;
    int64_t _1344_t6;
    struct struct0 _1345_x;
    int64_t _1344_t8;
    int64_t _1344_t9;
    int64_t* _1344_t10;
    int64_t _1344_t11;
    struct struct1 _1345_y;
    int64_t _1344_t12;
    int64_t _1344_t15;
    int64_t* _1344_t16;
    struct struct1 _1345_z;
    int64_t _1344_t19;
    function2 _1344_t20;
    int64_t _1344_t21;
    int64_t _1344_$retval;
    _1344_t1 = 1;
    _1344_t2 = 15;
    _1344_t3 = 24;
    _1344_t4 = 4;
    _1344_t5 = 35;
    _1344_t6 = 6;
    _1345_x = (struct struct0) {_1344_t1, _1344_t2, _1344_t3, _1344_t4, _1344_t5, _1344_t6};
    _1344_t8 = 0;
    _1344_t9 = 6;
    $bounds_check(_1344_t8, _1344_t9, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1344_t10 = ((int64_t*)&_1345_x + _1344_t8);
    _1344_t11 = 6;
    _1345_y = (struct struct1) {_1344_t10, _1344_t11};
    _1344_t12 = 1;
    _1344_t15 = 4;
    _1344_t16 = _1345_y._0+_1344_t12;
    _1345_z = (struct struct1) {_1344_t16, _1344_t15};
    _1344_t19 = 2;
    $bounds_check(_1344_t19, _1345_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1345_z._0 + _1344_t19) = 10;
    _1344_t20 = _1346_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1344_t21 = _1344_t20(_1345_z);
    $line_idx--;
    _1344_$retval = _1344_t21;
    return _1344_$retval;
}

int64_t _1346_sum_up(struct struct1 _1346_xs){
    int64_t _1347_sum;
    int64_t _1348_i;
    uint8_t _1346_t3;
    int64_t _1346_t5;
    int64_t _1346_$retval;
    _1347_sum = 0;
    _1348_i = 0;
    goto BB1619;
BB1619:
    _1346_t3 = _1348_i<_1346_xs._1;
    if (_1346_t3) {
        goto BB1620;
    } else {
        goto BB1625;
    }
BB1620:
    $bounds_check(_1348_i, _1346_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1347_sum = $add_int64_t(_1347_sum, *((int64_t*)_1346_xs._0 + _1348_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1346_t5 = 1;
    _1348_i = $add_int64_t(_1348_i, _1346_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1619;
BB1625:
    _1346_$retval = _1347_sum;
    return _1346_$retval;
}

int main(void) {
  printf("%ld",_1344_main());
  return 0;
}
