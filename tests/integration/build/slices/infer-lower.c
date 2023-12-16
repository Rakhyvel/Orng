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
int64_t _1268_main(void);
int64_t _1273_sum_up(struct1 _1273_xs);

/* Function definitions */
int64_t _1268_main(void){
    int64_t _1268_t1;
    int64_t _1268_t2;
    int64_t _1268_t3;
    int64_t _1268_t4;
    int64_t _1268_t5;
    int64_t _1268_t6;
    struct0 _1269_x;
    int64_t _1268_t8;
    int64_t* _1268_t9;
    int64_t _1268_t10;
    struct1 _1269_y;
    int64_t _1268_t14;
    int64_t* _1268_t15;
    struct1 _1269_z;
    function2 _1268_t17;
    int64_t _1268_t18;
    int64_t _1268_$retval;
    _1268_t1 = 100;
    _1268_t2 = 8;
    _1268_t3 = 2;
    _1268_t4 = 4;
    _1268_t5 = 35;
    _1268_t6 = 6;
    _1269_x = (struct0) {_1268_t1, _1268_t2, _1268_t3, _1268_t4, _1268_t5, _1268_t6};
    _1268_t8 = 0;
    _1268_t9 = ((int64_t*)&_1269_x + _1268_t8);
    _1268_t10 = 6;
    _1269_y = (struct1) {_1268_t9, _1268_t10};
    _1268_t14 = 3;
    _1268_t15 = _1269_y._0;
    _1269_z = (struct1) {_1268_t15, _1268_t14};
    _1268_t17 = _1273_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1268_t18 = _1268_t17(_1269_z);
    $line_idx--;
    _1268_$retval = _1268_t18;
    return _1268_$retval;
}

int64_t _1273_sum_up(struct1 _1273_xs){
    int64_t _1276_sum;
    int64_t _1277_i;
    uint8_t _1273_t3;
    int64_t _1273_t5;
    int64_t _1273_$retval;
    _1276_sum = 0;
    _1277_i = 0;
    goto BB1;
BB1:
    _1273_t3 = _1277_i < _1273_xs._1;
    if (_1273_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1276_sum = $add_int64_t(_1276_sum, *((int64_t*)_1273_xs._0 + _1277_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1273_t5 = 1;
    _1277_i = $add_int64_t(_1277_i, _1273_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1273_$retval = _1276_sum;
    return _1273_$retval;
}

int main(void) {
  printf("%ld",_1268_main());
  return 0;
}
