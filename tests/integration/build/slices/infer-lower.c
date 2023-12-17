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
int64_t _1413_main(void);
int64_t _1418_sum_up(struct1 _1418_xs);

/* Function definitions */
int64_t _1413_main(void){
    int64_t _1413_t1;
    int64_t _1413_t2;
    int64_t _1413_t3;
    int64_t _1413_t4;
    int64_t _1413_t5;
    int64_t _1413_t6;
    struct0 _1414_x;
    int64_t _1413_t8;
    int64_t _1413_t9;
    int64_t* _1413_t10;
    int64_t _1413_t11;
    struct1 _1414_y;
    int64_t _1413_t15;
    int64_t* _1413_t16;
    struct1 _1414_z;
    function2 _1413_t18;
    int64_t _1413_t19;
    int64_t _1413_$retval;
    _1413_t1 = 100;
    _1413_t2 = 8;
    _1413_t3 = 2;
    _1413_t4 = 4;
    _1413_t5 = 35;
    _1413_t6 = 6;
    _1414_x = (struct0) {_1413_t1, _1413_t2, _1413_t3, _1413_t4, _1413_t5, _1413_t6};
    _1413_t8 = 0;
    _1413_t9 = 6;
    $bounds_check(_1413_t8, _1413_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1413_t10 = ((int64_t*)&_1414_x + _1413_t8);
    _1413_t11 = 6;
    _1414_y = (struct1) {_1413_t10, _1413_t11};
    _1413_t15 = 3;
    _1413_t16 = _1414_y._0;
    _1414_z = (struct1) {_1413_t16, _1413_t15};
    _1413_t18 = _1418_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1413_t19 = _1413_t18(_1414_z);
    $line_idx--;
    _1413_$retval = _1413_t19;
    return _1413_$retval;
}

int64_t _1418_sum_up(struct1 _1418_xs){
    int64_t _1421_sum;
    int64_t _1422_i;
    uint8_t _1418_t3;
    int64_t _1418_t5;
    int64_t _1418_$retval;
    _1421_sum = 0;
    _1422_i = 0;
    goto BB1;
BB1:
    _1418_t3 = _1422_i < _1418_xs._1;
    if (_1418_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1422_i, _1418_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1421_sum = $add_int64_t(_1421_sum, *((int64_t*)_1418_xs._0 + _1422_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1418_t5 = 1;
    _1422_i = $add_int64_t(_1422_i, _1418_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1418_$retval = _1421_sum;
    return _1418_$retval;
}

int main(void) {
  printf("%ld",_1413_main());
  return 0;
}
