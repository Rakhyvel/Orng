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
int64_t _1316_main(void);
int64_t _1321_sum_up(struct1 _1321_xs);

/* Function definitions */
int64_t _1316_main(void){
    int64_t _1316_t1;
    int64_t _1316_t2;
    int64_t _1316_t3;
    struct0 _1317_x;
    int64_t _1316_t5;
    int64_t* _1316_t6;
    int64_t _1316_t7;
    struct1 _1317_y;
    int64_t _1316_t8;
    uint8_t _1316_t9;
    int64_t _1316_t10;
    int64_t* _1316_t11;
    struct1 _1317_z;
    function2 _1316_t13;
    int64_t _1316_t14;
    int64_t _1316_$retval;
    _1316_t1 = 100;
    _1316_t2 = 10;
    _1316_t3 = 1;
    _1317_x = (struct0) {_1316_t1, _1316_t2, _1316_t3};
    _1316_t5 = 0;
    _1316_t6 = ((int64_t*)&_1317_x + _1316_t5);
    _1316_t7 = 3;
    _1317_y = (struct1) {_1316_t6, _1316_t7};
    _1316_t8 = 0;
    _1316_t9 = _1316_t8 > _1317_y._1;
    if (_1316_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1316_t10 = $sub_int64_t(_1317_y._1, _1316_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1316_t11 = _1317_y._0 + _1316_t8;
    _1317_z = (struct1) {_1316_t11, _1316_t10};
    _1316_t13 = _1321_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1316_t14 = _1316_t13(_1317_z);
    $line_idx--;
    _1316_$retval = _1316_t14;
    return _1316_$retval;
}

int64_t _1321_sum_up(struct1 _1321_xs){
    int64_t _1324_sum;
    int64_t _1325_i;
    uint8_t _1321_t3;
    int64_t _1321_t5;
    int64_t _1321_$retval;
    _1324_sum = 0;
    _1325_i = 0;
    goto BB1;
BB1:
    _1321_t3 = _1325_i < _1321_xs._1;
    if (_1321_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1324_sum = $add_int64_t(_1324_sum, *((int64_t*)_1321_xs._0 + _1325_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1321_t5 = 1;
    _1325_i = $add_int64_t(_1325_i, _1321_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1321_$retval = _1324_sum;
    return _1321_$retval;
}

int main(void) {
  printf("%ld",_1316_main());
  return 0;
}
