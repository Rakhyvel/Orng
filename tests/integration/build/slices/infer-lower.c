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
int64_t _1251_main(void);
int64_t _1256_sum_up(struct1 _1256_xs);

/* Function definitions */
int64_t _1251_main(void) {
    int64_t _1251_t1;
    int64_t _1251_t2;
    int64_t _1251_t3;
    int64_t _1251_t4;
    int64_t _1251_t5;
    int64_t _1251_t6;
    struct0 _1252_x;
    int64_t _1251_t8;
    int64_t* _1251_t9;
    int64_t _1251_t10;
    struct1 _1252_y;
    int64_t _1251_t14;
    int64_t* _1251_t15;
    struct1 _1252_z;
    function2 _1251_t17;
    int64_t _1251_t18;
    int64_t _1251_$retval;
    _1251_t1 = 100;
    _1251_t2 = 8;
    _1251_t3 = 2;
    _1251_t4 = 4;
    _1251_t5 = 35;
    _1251_t6 = 6;
    _1252_x = (struct0) {_1251_t1, _1251_t2, _1251_t3, _1251_t4, _1251_t5, _1251_t6};
    _1251_t8 = 0;
    _1251_t9 = ((int64_t*)&_1252_x + _1251_t8);
    _1251_t10 = 6;
    _1252_y = (struct1) {_1251_t9, _1251_t10};
    _1251_t14 = 3;
    _1251_t15 = _1252_y._0;
    _1252_z = (struct1) {_1251_t15, _1251_t14};
    _1251_t17 = _1256_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1251_t18 = _1251_t17(_1252_z);
    $line_idx--;
    _1251_$retval = _1251_t18;
    return _1251_$retval;
}

int64_t _1256_sum_up(struct1 _1256_xs) {
    int64_t _1258_sum;
    int64_t _1260_i;
    uint8_t _1256_t3;
    int64_t _1256_t5;
    int64_t _1256_$retval;
    _1258_sum = 0;
    _1260_i = 0;
    goto BB1;
BB1:
    _1256_t3 = _1260_i < _1256_xs._1;
    if (_1256_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1258_sum = $add_int64_t(_1258_sum, *((int64_t*)_1256_xs._0 + _1260_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1256_t5 = 1;
    _1260_i = $add_int64_t(_1260_i, _1256_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1256_$retval = _1258_sum;
    return _1256_$retval;
}

int main(void) {
  printf("%ld",_1251_main());
  return 0;
}
