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
int64_t _990_main(void);
int64_t _992_sum_up(struct1 _992_xs);

/* Function definitions */
int64_t _990_main(void) {
    int64_t _990_t1;
    int64_t _990_t2;
    int64_t _990_t3;
    int64_t _990_t4;
    int64_t _990_t5;
    int64_t _990_t6;
    struct0 _991_x;
    int64_t _990_t8;
    int64_t* _990_t9;
    int64_t _990_t10;
    struct1 _991_y;
    int64_t _990_t11;
    int64_t _990_t14;
    int64_t* _990_t15;
    struct1 _991_z;
    int64_t _990_t18;
    function2 _990_t19;
    int64_t _990_t20;
    int64_t _990_$retval;
    _990_t1 = 1;
    _990_t2 = 15;
    _990_t3 = 24;
    _990_t4 = 4;
    _990_t5 = 35;
    _990_t6 = 6;
    _991_x = (struct0) {_990_t1, _990_t2, _990_t3, _990_t4, _990_t5, _990_t6};
    _990_t8 = 0;
    _990_t9 = ((int64_t*)&_991_x + _990_t8);
    _990_t10 = 6;
    _991_y = (struct1) {_990_t9, _990_t10};
    _990_t11 = 1;
    _990_t14 = 4;
    _990_t15 = _991_y._0 + _990_t11;
    _991_z = (struct1) {_990_t15, _990_t14};
    _990_t18 = 2;
    *((int64_t*)_991_z._0 + _990_t18) = 10;
    _990_t19 = _992_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _990_t20 = _990_t19(_991_z);
    $line_idx--;
    _990_$retval = _990_t20;
    return _990_$retval;
}

int64_t _992_sum_up(struct1 _992_xs) {
    int64_t _993_sum;
    int64_t _994_i;
    uint8_t _992_t3;
    int64_t _992_t5;
    int64_t _992_$retval;
    _993_sum = 0;
    _994_i = 0;
    goto BB1;
BB1:
    _992_t3 = _994_i < _992_xs._1;
    if (_992_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _993_sum = $add_int64_t(_993_sum, *((int64_t*)_992_xs._0 + _994_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _992_t5 = 1;
    _994_i = $add_int64_t(_994_i, _992_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _992_$retval = _993_sum;
    return _992_$retval;
}

int main(void) {
  printf("%ld",_990_main());
  return 0;
}
