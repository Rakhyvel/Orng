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
int64_t _900_main(void);
int64_t _902_sum_up(struct1 _902_xs);

/* Function definitions */
int64_t _900_main(void) {
    int64_t _900_t1;
    int64_t _900_t2;
    int64_t _900_t3;
    int64_t _900_t4;
    int64_t _900_t5;
    int64_t _900_t6;
    struct0 _901_x;
    int64_t _900_t8;
    int64_t* _900_t9;
    int64_t _900_t10;
    struct1 _901_y;
    int64_t _900_t11;
    uint8_t _900_t12;
    int64_t _900_t13;
    int64_t* _900_t14;
    struct1 _901_z;
    function2 _900_t16;
    int64_t _900_t17;
    int64_t _900_$retval;
    _900_t1 = 34;
    _900_t2 = 25;
    _900_t3 = 34;
    _900_t4 = 100;
    _900_t5 = 8;
    _900_t6 = 3;
    _901_x = (struct0) {_900_t1, _900_t2, _900_t3, _900_t4, _900_t5, _900_t6};
    _900_t8 = 0;
    _900_t9 = ((int64_t*)&_901_x + _900_t8);
    _900_t10 = 6;
    _901_y = (struct1) {_900_t9, _900_t10};
    _900_t11 = 3;
    _900_t12 = _900_t11 > _901_y._1;
    if (_900_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _900_t13 = $sub_int64_t(_901_y._1, _900_t11, "tests/integration/slices/infer-upper.orng:5:25:\n    let z: [mut]Int = y[3..]\n                       ^");
    _900_t14 = _901_y._0 + _900_t11;
    _901_z = (struct1) {_900_t14, _900_t13};
    _900_t16 = _902_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-upper.orng:6:12:\n    sum_up(z)\n          ^";
    _900_t17 = _900_t16(_901_z);
    $line_idx--;
    _900_$retval = _900_t17;
    return _900_$retval;
}

int64_t _902_sum_up(struct1 _902_xs) {
    int64_t _903_sum;
    int64_t _904_i;
    uint8_t _902_t3;
    int64_t _902_t5;
    int64_t _902_$retval;
    _903_sum = 0;
    _904_i = 0;
    goto BB1;
BB1:
    _902_t3 = _904_i < _902_xs._1;
    if (_902_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _903_sum = $add_int64_t(_903_sum, *((int64_t*)_902_xs._0 + _904_i), "tests/integration/slices/infer-upper.orng:12:15:\n        sum += xs[i]\n             ^");
    _902_t5 = 1;
    _904_i = $add_int64_t(_904_i, _902_t5, "tests/integration/slices/infer-upper.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _902_$retval = _903_sum;
    return _902_$retval;
}

int main(void) {
  printf("%ld",_900_main());
  return 0;
}
