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
int64_t _1054_main(void);
int64_t _1057_sum_up(struct1 _1057_xs);

/* Function definitions */
int64_t _1054_main(void) {
    int64_t _1054_t1;
    int64_t _1054_t2;
    int64_t _1054_t3;
    int64_t _1054_t4;
    int64_t _1054_t5;
    int64_t _1054_t6;
    struct0 _1055_x;
    int64_t _1054_t8;
    int64_t* _1054_t9;
    int64_t _1054_t10;
    struct1 _1055_y;
    int64_t _1054_t11;
    int64_t _1054_t14;
    int64_t* _1054_t15;
    struct1 _1055_z;
    int64_t _1054_t18;
    function2 _1054_t19;
    int64_t _1054_t20;
    int64_t _1054_$retval;
    _1054_t1 = 1;
    _1054_t2 = 15;
    _1054_t3 = 24;
    _1054_t4 = 4;
    _1054_t5 = 35;
    _1054_t6 = 6;
    _1055_x = (struct0) {_1054_t1, _1054_t2, _1054_t3, _1054_t4, _1054_t5, _1054_t6};
    _1054_t8 = 0;
    _1054_t9 = ((int64_t*)&_1055_x + _1054_t8);
    _1054_t10 = 6;
    _1055_y = (struct1) {_1054_t9, _1054_t10};
    _1054_t11 = 1;
    _1054_t14 = 4;
    _1054_t15 = _1055_y._0 + _1054_t11;
    _1055_z = (struct1) {_1054_t15, _1054_t14};
    _1054_t18 = 2;
    *((int64_t*)_1055_z._0 + _1054_t18) = 10;
    _1054_t19 = _1057_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1054_t20 = _1054_t19(_1055_z);
    $line_idx--;
    _1054_$retval = _1054_t20;
    return _1054_$retval;
}

int64_t _1057_sum_up(struct1 _1057_xs) {
    int64_t _1058_sum;
    int64_t _1059_i;
    uint8_t _1057_t3;
    int64_t _1057_t5;
    int64_t _1057_$retval;
    _1058_sum = 0;
    _1059_i = 0;
    goto BB1;
BB1:
    _1057_t3 = _1059_i < _1057_xs._1;
    if (_1057_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1058_sum = $add_int64_t(_1058_sum, *((int64_t*)_1057_xs._0 + _1059_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1057_t5 = 1;
    _1059_i = $add_int64_t(_1059_i, _1057_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1057_$retval = _1058_sum;
    return _1057_$retval;
}

int main(void) {
  printf("%ld",_1054_main());
  return 0;
}
