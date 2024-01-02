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
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(struct struct1);

/* Function forward definitions */
int64_t _1303_main(void);
int64_t _1305_sum_up(struct struct1 _1305_xs);

/* Function definitions */
int64_t _1303_main(void){
    int64_t _1303_t1;
    int64_t _1303_t2;
    int64_t _1303_t3;
    struct struct0 _1304_x;
    int64_t _1303_t5;
    int64_t _1303_t6;
    int64_t* _1303_t7;
    int64_t _1303_t8;
    struct struct1 _1304_y;
    int64_t _1303_t9;
    uint8_t _1303_t10;
    int64_t _1303_t11;
    int64_t* _1303_t12;
    struct struct1 _1304_z;
    function2 _1303_t14;
    int64_t _1303_t15;
    int64_t _1303_$retval;
    _1303_t1 = 100;
    _1303_t2 = 10;
    _1303_t3 = 1;
    _1304_x = (struct struct0) {_1303_t1, _1303_t2, _1303_t3};
    _1303_t5 = 0;
    _1303_t6 = 3;
    $bounds_check(_1303_t5, _1303_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1303_t7 = ((int64_t*)&_1304_x + _1303_t5);
    _1303_t8 = 3;
    _1304_y = (struct struct1) {_1303_t7, _1303_t8};
    _1303_t9 = 0;
    _1303_t10 = _1303_t9>_1304_y._1;
    if (_1303_t10) {
        goto BB1571;
    } else {
        goto BB1572;
    }
BB1571:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1572:
    _1303_t11 = $sub_int64_t(_1304_y._1, _1303_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1303_t12 = _1304_y._0+_1303_t9;
    _1304_z = (struct struct1) {_1303_t12, _1303_t11};
    _1303_t14 = _1305_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1303_t15 = _1303_t14(_1304_z);
    $line_idx--;
    _1303_$retval = _1303_t15;
    return _1303_$retval;
}

int64_t _1305_sum_up(struct struct1 _1305_xs){
    int64_t _1306_sum;
    int64_t _1307_i;
    uint8_t _1305_t3;
    int64_t _1305_t5;
    int64_t _1305_$retval;
    _1306_sum = 0;
    _1307_i = 0;
    goto BB1563;
BB1563:
    _1305_t3 = _1307_i<_1305_xs._1;
    if (_1305_t3) {
        goto BB1564;
    } else {
        goto BB1569;
    }
BB1564:
    $bounds_check(_1307_i, _1305_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1306_sum = $add_int64_t(_1306_sum, *((int64_t*)_1305_xs._0 + _1307_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1305_t5 = 1;
    _1307_i = $add_int64_t(_1307_i, _1305_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1563;
BB1569:
    _1305_$retval = _1306_sum;
    return _1305_$retval;
}

int main(void) {
  printf("%ld",_1303_main());
  return 0;
}
