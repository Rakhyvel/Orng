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
int64_t _1249_main(void);
int64_t _1254_sum_up(struct1 _1254_xs);

/* Function definitions */
int64_t _1249_main(void) {
    int64_t _1249_t1;
    int64_t _1249_t2;
    int64_t _1249_t3;
    int64_t _1249_t4;
    int64_t _1249_t5;
    int64_t _1249_t6;
    struct0 _1250_x;
    int64_t _1249_t8;
    int64_t* _1249_t9;
    int64_t _1249_t10;
    struct1 _1250_y;
    int64_t _1249_t14;
    int64_t* _1249_t15;
    struct1 _1250_z;
    function2 _1249_t17;
    int64_t _1249_t18;
    int64_t _1249_$retval;
    _1249_t1 = 100;
    _1249_t2 = 8;
    _1249_t3 = 2;
    _1249_t4 = 4;
    _1249_t5 = 35;
    _1249_t6 = 6;
    _1250_x = (struct0) {_1249_t1, _1249_t2, _1249_t3, _1249_t4, _1249_t5, _1249_t6};
    _1249_t8 = 0;
    _1249_t9 = ((int64_t*)&_1250_x + _1249_t8);
    _1249_t10 = 6;
    _1250_y = (struct1) {_1249_t9, _1249_t10};
    _1249_t14 = 3;
    _1249_t15 = _1250_y._0;
    _1250_z = (struct1) {_1249_t15, _1249_t14};
    _1249_t17 = _1254_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1249_t18 = _1249_t17(_1250_z);
    $line_idx--;
    _1249_$retval = _1249_t18;
    return _1249_$retval;
}

int64_t _1254_sum_up(struct1 _1254_xs) {
    int64_t _1256_sum;
    int64_t _1258_i;
    uint8_t _1254_t3;
    int64_t _1254_t5;
    int64_t _1254_$retval;
    _1256_sum = 0;
    _1258_i = 0;
    goto BB1;
BB1:
    _1254_t3 = _1258_i < _1254_xs._1;
    if (_1254_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1256_sum = $add_int64_t(_1256_sum, *((int64_t*)_1254_xs._0 + _1258_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1254_t5 = 1;
    _1258_i = $add_int64_t(_1258_i, _1254_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1254_$retval = _1256_sum;
    return _1254_$retval;
}

int main(void) {
  printf("%ld",_1249_main());
  return 0;
}
