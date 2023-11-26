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
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _886_main(void);
int64_t _888_sum_up(struct1 _888_xs);

/* Function definitions */
int64_t _886_main(void) {
    int64_t _886_t1;
    int64_t _886_t2;
    int64_t _886_t3;
    struct0 _887_x;
    int64_t _886_t5;
    int64_t* _886_t6;
    int64_t _886_t7;
    struct1 _887_y;
    int64_t _886_t8;
    uint8_t _886_t9;
    int64_t _886_t10;
    int64_t* _886_t11;
    struct1 _887_z;
    function2 _886_t13;
    int64_t _886_t14;
    int64_t _886_$retval;
    _886_t1 = 100;
    _886_t2 = 10;
    _886_t3 = 1;
    _887_x = (struct0) {_886_t1, _886_t2, _886_t3};
    _886_t5 = 0;
    _886_t6 = ((int64_t*)&_887_x + _886_t5);
    _886_t7 = 3;
    _887_y = (struct1) {_886_t6, _886_t7};
    _886_t8 = 0;
    _886_t9 = _886_t8 > _887_y._1;
    if (_886_t9) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _886_t10 = $sub_int64_t(_887_y._1, _886_t8, "tests/integration/slices/infer-both.orng:5:25:\n    let z: [mut]Int = y[..]\n                       ^");
    _886_t11 = _887_y._0 + _886_t8;
    _887_z = (struct1) {_886_t11, _886_t10};
    _886_t13 = _888_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-both.orng:6:12:\n    sum_up(z)\n          ^";
    _886_t14 = _886_t13(_887_z);
    $line_idx--;
    _886_$retval = _886_t14;
    return _886_$retval;
}

int64_t _888_sum_up(struct1 _888_xs) {
    int64_t _889_sum;
    int64_t _890_i;
    uint8_t _888_t3;
    int64_t _888_t5;
    int64_t _888_$retval;
    _889_sum = 0;
    _890_i = 0;
    goto BB1;
BB1:
    _888_t3 = _890_i < _888_xs._1;
    if (_888_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _889_sum = $add_int64_t(_889_sum, *((int64_t*)_888_xs._0 + _890_i), "tests/integration/slices/infer-both.orng:12:15:\n        sum += xs[i]\n             ^");
    _888_t5 = 1;
    _890_i = $add_int64_t(_890_i, _888_t5, "tests/integration/slices/infer-both.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _888_$retval = _889_sum;
    return _888_$retval;
}

int main(void) {
  printf("%ld",_886_main());
  return 0;
}
