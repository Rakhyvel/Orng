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
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1401_main(void);
int64_t _1406_sum_up(struct1 _1406_xs);

/* Function definitions */
int64_t _1401_main(void){
    int64_t _1401_t1;
    int64_t _1401_t2;
    int64_t _1401_t3;
    struct0 _1402_x;
    int64_t _1401_t5;
    int64_t _1401_t6;
    int64_t* _1401_t7;
    int64_t _1401_t8;
    struct1 _1402_y;
    int64_t _1401_t9;
    uint8_t _1401_t10;
    int64_t _1401_t11;
    int64_t* _1401_t12;
    struct1 _1402_z;
    function2 _1401_t14;
    int64_t _1401_t15;
    int64_t _1401_$retval;
    _1401_t1 = 100;
    _1401_t2 = 10;
    _1401_t3 = 1;
    _1402_x = (struct0) {_1401_t1, _1401_t2, _1401_t3};
    _1401_t5 = 0;
    _1401_t6 = 3;
    $bounds_check(_1401_t5, _1401_t6, "tests/integration/slices/infer-both.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1401_t7 = ((int64_t*)&_1402_x + _1401_t5);
    _1401_t8 = 3;
    _1402_y = (struct1) {_1401_t7, _1401_t8};
    _1401_t9 = 0;
    _1401_t10 = _1401_t9 > _1402_y._1;
    if (_1401_t10) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1401_t11 = $sub_int64_t(_1402_y._1, _1401_t9, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1401_t12 = _1402_y._0 + _1401_t9;
    _1402_z = (struct1) {_1401_t12, _1401_t11};
    _1401_t14 = _1406_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1401_t15 = _1401_t14(_1402_z);
    $line_idx--;
    _1401_$retval = _1401_t15;
    return _1401_$retval;
}

int64_t _1406_sum_up(struct1 _1406_xs){
    int64_t _1409_sum;
    int64_t _1410_i;
    uint8_t _1406_t3;
    int64_t _1406_t5;
    int64_t _1406_$retval;
    _1409_sum = 0;
    _1410_i = 0;
    goto BB1;
BB1:
    _1406_t3 = _1410_i < _1406_xs._1;
    if (_1406_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1410_i, _1406_xs._1, "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1409_sum = $add_int64_t(_1409_sum, *((int64_t*)_1406_xs._0 + _1410_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1406_t5 = 1;
    _1410_i = $add_int64_t(_1410_i, _1406_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1406_$retval = _1409_sum;
    return _1406_$retval;
}

int main(void) {
  printf("%ld",_1401_main());
  return 0;
}
