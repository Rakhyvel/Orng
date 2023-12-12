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
int64_t _991_main(void);
int64_t _993_sum_up(struct1 _993_xs);

/* Function definitions */
int64_t _991_main(void) {
    int64_t _991_t1;
    int64_t _991_t2;
    int64_t _991_t3;
    int64_t _991_t4;
    int64_t _991_t5;
    int64_t _991_t6;
    struct0 _992_x;
    int64_t _991_t8;
    int64_t* _991_t9;
    int64_t _991_t10;
    struct1 _992_y;
    int64_t _991_t14;
    int64_t* _991_t15;
    struct1 _992_z;
    function2 _991_t17;
    int64_t _991_t18;
    int64_t _991_$retval;
    _991_t1 = 100;
    _991_t2 = 8;
    _991_t3 = 2;
    _991_t4 = 4;
    _991_t5 = 35;
    _991_t6 = 6;
    _992_x = (struct0) {_991_t1, _991_t2, _991_t3, _991_t4, _991_t5, _991_t6};
    _991_t8 = 0;
    _991_t9 = ((int64_t*)&_992_x + _991_t8);
    _991_t10 = 6;
    _992_y = (struct1) {_991_t9, _991_t10};
    _991_t14 = 3;
    _991_t15 = _992_y._0;
    _992_z = (struct1) {_991_t15, _991_t14};
    _991_t17 = _993_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _991_t18 = _991_t17(_992_z);
    $line_idx--;
    _991_$retval = _991_t18;
    return _991_$retval;
}

int64_t _993_sum_up(struct1 _993_xs) {
    int64_t _994_sum;
    int64_t _995_i;
    uint8_t _993_t3;
    int64_t _993_t5;
    int64_t _993_$retval;
    _994_sum = 0;
    _995_i = 0;
    goto BB1;
BB1:
    _993_t3 = _995_i < _993_xs._1;
    if (_993_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _994_sum = $add_int64_t(_994_sum, *((int64_t*)_993_xs._0 + _995_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _993_t5 = 1;
    _995_i = $add_int64_t(_995_i, _993_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _993_$retval = _994_sum;
    return _993_$retval;
}

int main(void) {
  printf("%ld",_991_main());
  return 0;
}
