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
int64_t _1041_main(void);
int64_t _1043_sum_up(struct1 _1043_xs);

/* Function definitions */
int64_t _1041_main(void) {
    int64_t _1041_t1;
    int64_t _1041_t2;
    int64_t _1041_t3;
    int64_t _1041_t4;
    int64_t _1041_t5;
    int64_t _1041_t6;
    struct0 _1042_x;
    int64_t _1041_t8;
    int64_t* _1041_t9;
    int64_t _1041_t10;
    struct1 _1042_y;
    int64_t _1041_t11;
    int64_t _1041_t14;
    int64_t* _1041_t15;
    struct1 _1042_z;
    int64_t _1041_t18;
    function2 _1041_t19;
    int64_t _1041_t20;
    int64_t _1041_$retval;
    _1041_t1 = 1;
    _1041_t2 = 15;
    _1041_t3 = 24;
    _1041_t4 = 4;
    _1041_t5 = 35;
    _1041_t6 = 6;
    _1042_x = (struct0) {_1041_t1, _1041_t2, _1041_t3, _1041_t4, _1041_t5, _1041_t6};
    _1041_t8 = 0;
    _1041_t9 = ((int64_t*)&_1042_x + _1041_t8);
    _1041_t10 = 6;
    _1042_y = (struct1) {_1041_t9, _1041_t10};
    _1041_t11 = 1;
    _1041_t14 = 4;
    _1041_t15 = _1042_y._0 + _1041_t11;
    _1042_z = (struct1) {_1041_t15, _1041_t14};
    _1041_t18 = 2;
    *((int64_t*)_1042_z._0 + _1041_t18) = 10;
    _1041_t19 = _1043_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1041_t20 = _1041_t19(_1042_z);
    $line_idx--;
    _1041_$retval = _1041_t20;
    return _1041_$retval;
}

int64_t _1043_sum_up(struct1 _1043_xs) {
    int64_t _1044_sum;
    int64_t _1045_i;
    uint8_t _1043_t3;
    int64_t _1043_t5;
    int64_t _1043_$retval;
    _1044_sum = 0;
    _1045_i = 0;
    goto BB1;
BB1:
    _1043_t3 = _1045_i < _1043_xs._1;
    if (_1043_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1044_sum = $add_int64_t(_1044_sum, *((int64_t*)_1043_xs._0 + _1045_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1043_t5 = 1;
    _1045_i = $add_int64_t(_1045_i, _1043_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1043_$retval = _1044_sum;
    return _1043_$retval;
}

int main(void) {
  printf("%ld",_1041_main());
  return 0;
}
