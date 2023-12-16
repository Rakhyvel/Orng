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
int64_t _1257_main(void);
int64_t _1262_sum_up(struct1 _1262_xs);

/* Function definitions */
int64_t _1257_main(void){
    int64_t _1257_t1;
    int64_t _1257_t2;
    int64_t _1257_t3;
    int64_t _1257_t4;
    int64_t _1257_t5;
    int64_t _1257_t6;
    struct0 _1258_x;
    int64_t _1257_t8;
    int64_t* _1257_t9;
    int64_t _1257_t10;
    struct1 _1258_y;
    int64_t _1257_t14;
    int64_t* _1257_t15;
    struct1 _1258_z;
    function2 _1257_t17;
    int64_t _1257_t18;
    int64_t _1257_$retval;
    _1257_t1 = 100;
    _1257_t2 = 8;
    _1257_t3 = 2;
    _1257_t4 = 4;
    _1257_t5 = 35;
    _1257_t6 = 6;
    _1258_x = (struct0) {_1257_t1, _1257_t2, _1257_t3, _1257_t4, _1257_t5, _1257_t6};
    _1257_t8 = 0;
    _1257_t9 = ((int64_t*)&_1258_x + _1257_t8);
    _1257_t10 = 6;
    _1258_y = (struct1) {_1257_t9, _1257_t10};
    _1257_t14 = 3;
    _1257_t15 = _1258_y._0;
    _1258_z = (struct1) {_1257_t15, _1257_t14};
    _1257_t17 = _1262_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1257_t18 = _1257_t17(_1258_z);
    $line_idx--;
    _1257_$retval = _1257_t18;
    return _1257_$retval;
}

int64_t _1262_sum_up(struct1 _1262_xs){
    int64_t _1265_sum;
    int64_t _1266_i;
    uint8_t _1262_t3;
    int64_t _1262_t5;
    int64_t _1262_$retval;
    _1265_sum = 0;
    _1266_i = 0;
    goto BB1;
BB1:
    _1262_t3 = _1266_i < _1262_xs._1;
    if (_1262_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1265_sum = $add_int64_t(_1265_sum, *((int64_t*)_1262_xs._0 + _1266_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1262_t5 = 1;
    _1266_i = $add_int64_t(_1266_i, _1262_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1262_$retval = _1265_sum;
    return _1262_$retval;
}

int main(void) {
  printf("%ld",_1257_main());
  return 0;
}
