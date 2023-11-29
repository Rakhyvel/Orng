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
int64_t _19_main(void);
int64_t _21_sum_up(struct1 _21_xs);

/* Function definitions */
int64_t _19_main(void) {
    int64_t _19_t1;
    int64_t _19_t2;
    int64_t _19_t3;
    int64_t _19_t4;
    int64_t _19_t5;
    int64_t _19_t6;
    struct0 _20_x;
    int64_t _19_t8;
    int64_t* _19_t9;
    int64_t _19_t10;
    struct1 _20_y;
    int64_t _19_t14;
    int64_t* _19_t15;
    struct1 _20_z;
    function2 _19_t17;
    int64_t _19_t18;
    int64_t _19_$retval;
    _19_t1 = 100;
    _19_t2 = 8;
    _19_t3 = 2;
    _19_t4 = 4;
    _19_t5 = 35;
    _19_t6 = 6;
    _20_x = (struct0) {_19_t1, _19_t2, _19_t3, _19_t4, _19_t5, _19_t6};
    _19_t8 = 0;
    _19_t9 = ((int64_t*)&_20_x + _19_t8);
    _19_t10 = 6;
    _20_y = (struct1) {_19_t9, _19_t10};
    _19_t14 = 3;
    _19_t15 = _20_y._0;
    _20_z = (struct1) {_19_t15, _19_t14};
    _19_t17 = _21_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _19_t18 = _19_t17(_20_z);
    $line_idx--;
    _19_$retval = _19_t18;
    return _19_$retval;
}

int64_t _21_sum_up(struct1 _21_xs) {
    int64_t _22_sum;
    int64_t _23_i;
    uint8_t _21_t3;
    int64_t _21_t5;
    int64_t _21_$retval;
    _22_sum = 0;
    _23_i = 0;
    goto BB1;
BB1:
    _21_t3 = _23_i < _21_xs._1;
    if (_21_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _22_sum = $add_int64_t(_22_sum, *((int64_t*)_21_xs._0 + _23_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _21_t5 = 1;
    _23_i = $add_int64_t(_23_i, _21_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _21_$retval = _22_sum;
    return _21_$retval;
}

int main(void) {
  printf("%ld",_19_main());
  return 0;
}
