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
int64_t _1284_main(void);
int64_t _1286_sum_up(struct1 _1286_xs);

/* Function definitions */
int64_t _1284_main(void){
    int64_t _1284_t1;
    int64_t _1284_t2;
    int64_t _1284_t3;
    int64_t _1284_t4;
    int64_t _1284_t5;
    int64_t _1284_t6;
    struct0 _1285_x;
    int64_t _1284_t8;
    int64_t _1284_t9;
    int64_t* _1284_t10;
    int64_t _1284_t11;
    struct1 _1285_y;
    int64_t _1284_t15;
    int64_t* _1284_t16;
    struct1 _1285_z;
    function2 _1284_t18;
    int64_t _1284_t19;
    int64_t _1284_$retval;
    _1284_t1 = 100;
    _1284_t2 = 8;
    _1284_t3 = 2;
    _1284_t4 = 4;
    _1284_t5 = 35;
    _1284_t6 = 6;
    _1285_x = (struct0) {_1284_t1, _1284_t2, _1284_t3, _1284_t4, _1284_t5, _1284_t6};
    _1284_t8 = 0;
    _1284_t9 = 6;
    $bounds_check(_1284_t8, _1284_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1284_t10 = ((int64_t*)&_1285_x + _1284_t8);
    _1284_t11 = 6;
    _1285_y = (struct1) {_1284_t10, _1284_t11};
    _1284_t15 = 3;
    _1284_t16 = _1285_y._0;
    _1285_z = (struct1) {_1284_t16, _1284_t15};
    _1284_t18 = _1286_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1284_t19 = _1284_t18(_1285_z);
    $line_idx--;
    _1284_$retval = _1284_t19;
    return _1284_$retval;
}

int64_t _1286_sum_up(struct1 _1286_xs){
    int64_t _1287_sum;
    int64_t _1288_i;
    uint8_t _1286_t3;
    int64_t _1286_t5;
    int64_t _1286_$retval;
    _1287_sum = 0;
    _1288_i = 0;
    goto BB1586;
BB1586:
    _1286_t3 = _1288_i<_1286_xs._1;
    if (_1286_t3) {
        goto BB1587;
    } else {
        goto BB1592;
    }
BB1587:
    $bounds_check(_1288_i, _1286_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1287_sum = $add_int64_t(_1287_sum, *((int64_t*)_1286_xs._0 + _1288_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1286_t5 = 1;
    _1288_i = $add_int64_t(_1288_i, _1286_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1586;
BB1592:
    _1286_$retval = _1287_sum;
    return _1286_$retval;
}

int main(void) {
  printf("%ld",_1284_main());
  return 0;
}
