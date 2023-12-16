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
int64_t _1256_main(void);
int64_t _1261_sum_up(struct1 _1261_xs);

/* Function definitions */
int64_t _1256_main(void){
    int64_t _1256_t1;
    int64_t _1256_t2;
    int64_t _1256_t3;
    struct0 _1257_x;
    int64_t _1256_t5;
    int64_t* _1256_t6;
    int64_t _1256_t7;
    struct1 _1257_y;
    int64_t _1256_t8;
    uint8_t _1256_t9;
    int64_t _1256_t10;
    int64_t* _1256_t11;
    struct1 _1257_z;
    function2 _1256_t13;
    int64_t _1256_t14;
    int64_t _1256_$retval;
    _1256_t1 = 100;
    _1256_t2 = 10;
    _1256_t3 = 1;
    _1257_x = (struct0) {_1256_t1, _1256_t2, _1256_t3};
    _1256_t5 = 0;
    _1256_t6 = ((int64_t*)&_1257_x + _1256_t5);
    _1256_t7 = 3;
    _1257_y = (struct1) {_1256_t6, _1256_t7};
    _1256_t8 = 0;
    _1256_t9 = _1256_t8 > _1257_y._1;
    if (_1256_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1256_t10 = $sub_int64_t(_1257_y._1, _1256_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _1256_t11 = _1257_y._0 + _1256_t8;
    _1257_z = (struct1) {_1256_t11, _1256_t10};
    _1256_t13 = _1261_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _1256_t14 = _1256_t13(_1257_z);
    $line_idx--;
    _1256_$retval = _1256_t14;
    return _1256_$retval;
}

int64_t _1261_sum_up(struct1 _1261_xs){
    int64_t _1264_sum;
    int64_t _1265_i;
    uint8_t _1261_t3;
    int64_t _1261_t5;
    int64_t _1261_$retval;
    _1264_sum = 0;
    _1265_i = 0;
    goto BB1;
BB1:
    _1261_t3 = _1265_i < _1261_xs._1;
    if (_1261_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1264_sum = $add_int64_t(_1264_sum, *((int64_t*)_1261_xs._0 + _1265_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _1261_t5 = 1;
    _1265_i = $add_int64_t(_1265_i, _1261_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1261_$retval = _1264_sum;
    return _1261_$retval;
}

int main(void) {
  printf("%ld",_1256_main());
  return 0;
}
