/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
    int64_t _4;
    int64_t _5;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1467_main(void);
int64_t _1472_sum_up(struct1 _1472_xs);

/* Function definitions */
int64_t _1467_main(void){
    int64_t _1467_t1;
    int64_t _1467_t2;
    int64_t _1467_t3;
    int64_t _1467_t4;
    int64_t _1467_t5;
    int64_t _1467_t6;
    struct0 _1468_x;
    int64_t _1467_t8;
    int64_t _1467_t9;
    int64_t* _1467_t10;
    int64_t _1467_t11;
    struct1 _1468_y;
    int64_t _1467_t12;
    int64_t _1467_t15;
    int64_t* _1467_t16;
    struct1 _1468_z;
    int64_t _1467_t19;
    function2 _1467_t20;
    int64_t _1467_t21;
    int64_t _1467_$retval;
    _1467_t1 = 1;
    _1467_t2 = 15;
    _1467_t3 = 24;
    _1467_t4 = 4;
    _1467_t5 = 35;
    _1467_t6 = 6;
    _1468_x = (struct0) {_1467_t1, _1467_t2, _1467_t3, _1467_t4, _1467_t5, _1467_t6};
    _1467_t8 = 0;
    _1467_t9 = 6;
    $bounds_check(_1467_t8, _1467_t9, "tests/integration/slices/subslice.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1467_t10 = ((int64_t*)&_1468_x + _1467_t8);
    _1467_t11 = 6;
    _1468_y = (struct1) {_1467_t10, _1467_t11};
    _1467_t12 = 1;
    _1467_t15 = 4;
    _1467_t16 = _1468_y._0 + _1467_t12;
    _1468_z = (struct1) {_1467_t16, _1467_t15};
    _1467_t19 = 2;
    $bounds_check(_1467_t19, _1468_z._1, "tests/integration/slices/subslice.orng:6:14:\n    z[2] = 10\n            ^");
    *((int64_t*)_1468_z._0 + _1467_t19) = 10;
    _1467_t20 = _1472_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1467_t21 = _1467_t20(_1468_z);
    $line_idx--;
    _1467_$retval = _1467_t21;
    return _1467_$retval;
}

int64_t _1472_sum_up(struct1 _1472_xs){
    int64_t _1475_sum;
    int64_t _1476_i;
    uint8_t _1472_t3;
    int64_t _1472_t5;
    int64_t _1472_$retval;
    _1475_sum = 0;
    _1476_i = 0;
    goto BB1;
BB1:
    _1472_t3 = _1476_i < _1472_xs._1;
    if (_1472_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1476_i, _1472_xs._1, "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1475_sum = $add_int64_t(_1475_sum, *((int64_t*)_1472_xs._0 + _1476_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1472_t5 = 1;
    _1476_i = $add_int64_t(_1476_i, _1472_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1472_$retval = _1475_sum;
    return _1472_$retval;
}

int main(void) {
  printf("%ld",_1467_main());
  return 0;
}
