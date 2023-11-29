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
int64_t _1017_main(void);
int64_t _1020_sum_up(struct1 _1020_xs);

/* Function definitions */
int64_t _1017_main(void) {
    int64_t _1017_t1;
    int64_t _1017_t2;
    int64_t _1017_t3;
    int64_t _1017_t4;
    int64_t _1017_t5;
    int64_t _1017_t6;
    struct0 _1018_x;
    int64_t _1017_t8;
    int64_t* _1017_t9;
    int64_t _1017_t10;
    struct1 _1018_y;
    int64_t _1017_t14;
    int64_t* _1017_t15;
    struct1 _1018_z;
    function2 _1017_t17;
    int64_t _1017_t18;
    int64_t _1017_$retval;
    _1017_t1 = 100;
    _1017_t2 = 8;
    _1017_t3 = 2;
    _1017_t4 = 4;
    _1017_t5 = 35;
    _1017_t6 = 6;
    _1018_x = (struct0) {_1017_t1, _1017_t2, _1017_t3, _1017_t4, _1017_t5, _1017_t6};
    _1017_t8 = 0;
    _1017_t9 = ((int64_t*)&_1018_x + _1017_t8);
    _1017_t10 = 6;
    _1018_y = (struct1) {_1017_t9, _1017_t10};
    _1017_t14 = 3;
    _1017_t15 = _1018_y._0;
    _1018_z = (struct1) {_1017_t15, _1017_t14};
    _1017_t17 = _1020_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1017_t18 = _1017_t17(_1018_z);
    $line_idx--;
    _1017_$retval = _1017_t18;
    return _1017_$retval;
}

int64_t _1020_sum_up(struct1 _1020_xs) {
    int64_t _1021_sum;
    int64_t _1022_i;
    uint8_t _1020_t3;
    int64_t _1020_t5;
    int64_t _1020_$retval;
    _1021_sum = 0;
    _1022_i = 0;
    goto BB1;
BB1:
    _1020_t3 = _1022_i < _1020_xs._1;
    if (_1020_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1021_sum = $add_int64_t(_1021_sum, *((int64_t*)_1020_xs._0 + _1022_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1020_t5 = 1;
    _1022_i = $add_int64_t(_1022_i, _1020_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1020_$retval = _1021_sum;
    return _1020_$retval;
}

int main(void) {
  printf("%ld",_1017_main());
  return 0;
}
