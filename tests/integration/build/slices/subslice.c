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
int64_t _1303_main(void);
int64_t _1308_sum_up(struct1 _1308_xs);

/* Function definitions */
int64_t _1303_main(void) {
    int64_t _1303_t1;
    int64_t _1303_t2;
    int64_t _1303_t3;
    int64_t _1303_t4;
    int64_t _1303_t5;
    int64_t _1303_t6;
    struct0 _1304_x;
    int64_t _1303_t8;
    int64_t* _1303_t9;
    int64_t _1303_t10;
    struct1 _1304_y;
    int64_t _1303_t11;
    int64_t _1303_t14;
    int64_t* _1303_t15;
    struct1 _1304_z;
    int64_t _1303_t18;
    function2 _1303_t19;
    int64_t _1303_t20;
    int64_t _1303_$retval;
    _1303_t1 = 1;
    _1303_t2 = 15;
    _1303_t3 = 24;
    _1303_t4 = 4;
    _1303_t5 = 35;
    _1303_t6 = 6;
    _1304_x = (struct0) {_1303_t1, _1303_t2, _1303_t3, _1303_t4, _1303_t5, _1303_t6};
    _1303_t8 = 0;
    _1303_t9 = ((int64_t*)&_1304_x + _1303_t8);
    _1303_t10 = 6;
    _1304_y = (struct1) {_1303_t9, _1303_t10};
    _1303_t11 = 1;
    _1303_t14 = 4;
    _1303_t15 = _1304_y._0 + _1303_t11;
    _1304_z = (struct1) {_1303_t15, _1303_t14};
    _1303_t18 = 2;
    *((int64_t*)_1304_z._0 + _1303_t18) = 10;
    _1303_t19 = _1308_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1303_t20 = _1303_t19(_1304_z);
    $line_idx--;
    _1303_$retval = _1303_t20;
    return _1303_$retval;
}

int64_t _1308_sum_up(struct1 _1308_xs) {
    int64_t _1311_sum;
    int64_t _1312_i;
    uint8_t _1308_t3;
    int64_t _1308_t5;
    int64_t _1308_$retval;
    _1311_sum = 0;
    _1312_i = 0;
    goto BB1;
BB1:
    _1308_t3 = _1312_i < _1308_xs._1;
    if (_1308_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1311_sum = $add_int64_t(_1311_sum, *((int64_t*)_1308_xs._0 + _1312_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1308_t5 = 1;
    _1312_i = $add_int64_t(_1312_i, _1308_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1308_$retval = _1311_sum;
    return _1308_$retval;
}

int main(void) {
  printf("%ld",_1303_main());
  return 0;
}
