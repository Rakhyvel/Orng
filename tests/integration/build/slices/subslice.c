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
int64_t _1014_main(void);
int64_t _1016_sum_up(struct1 _1016_xs);

/* Function definitions */
int64_t _1014_main(void) {
    int64_t _1014_t1;
    int64_t _1014_t2;
    int64_t _1014_t3;
    int64_t _1014_t4;
    int64_t _1014_t5;
    int64_t _1014_t6;
    struct0 _1015_x;
    int64_t _1014_t8;
    int64_t* _1014_t9;
    int64_t _1014_t10;
    struct1 _1015_y;
    int64_t _1014_t11;
    int64_t _1014_t14;
    int64_t* _1014_t15;
    struct1 _1015_z;
    int64_t _1014_t18;
    function2 _1014_t19;
    int64_t _1014_t20;
    int64_t _1014_$retval;
    _1014_t1 = 1;
    _1014_t2 = 15;
    _1014_t3 = 24;
    _1014_t4 = 4;
    _1014_t5 = 35;
    _1014_t6 = 6;
    _1015_x = (struct0) {_1014_t1, _1014_t2, _1014_t3, _1014_t4, _1014_t5, _1014_t6};
    _1014_t8 = 0;
    _1014_t9 = ((int64_t*)&_1015_x + _1014_t8);
    _1014_t10 = 6;
    _1015_y = (struct1) {_1014_t9, _1014_t10};
    _1014_t11 = 1;
    _1014_t14 = 4;
    _1014_t15 = _1015_y._0 + _1014_t11;
    _1015_z = (struct1) {_1014_t15, _1014_t14};
    _1014_t18 = 2;
    *((int64_t*)_1015_z._0 + _1014_t18) = 10;
    _1014_t19 = _1016_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1014_t20 = _1014_t19(_1015_z);
    $line_idx--;
    _1014_$retval = _1014_t20;
    return _1014_$retval;
}

int64_t _1016_sum_up(struct1 _1016_xs) {
    int64_t _1017_sum;
    int64_t _1018_i;
    uint8_t _1016_t3;
    int64_t _1016_t5;
    int64_t _1016_$retval;
    _1017_sum = 0;
    _1018_i = 0;
    goto BB1;
BB1:
    _1016_t3 = _1018_i < _1016_xs._1;
    if (_1016_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1017_sum = $add_int64_t(_1017_sum, *((int64_t*)_1016_xs._0 + _1018_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1016_t5 = 1;
    _1018_i = $add_int64_t(_1018_i, _1016_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1016_$retval = _1017_sum;
    return _1016_$retval;
}

int main(void) {
  printf("%ld",_1014_main());
  return 0;
}
