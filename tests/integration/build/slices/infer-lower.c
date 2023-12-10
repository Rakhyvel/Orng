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
int64_t _983_main(void);
int64_t _985_sum_up(struct1 _985_xs);

/* Function definitions */
int64_t _983_main(void) {
    int64_t _983_t1;
    int64_t _983_t2;
    int64_t _983_t3;
    int64_t _983_t4;
    int64_t _983_t5;
    int64_t _983_t6;
    struct0 _984_x;
    int64_t _983_t8;
    int64_t* _983_t9;
    int64_t _983_t10;
    struct1 _984_y;
    int64_t _983_t14;
    int64_t* _983_t15;
    struct1 _984_z;
    function2 _983_t17;
    int64_t _983_t18;
    int64_t _983_$retval;
    _983_t1 = 100;
    _983_t2 = 8;
    _983_t3 = 2;
    _983_t4 = 4;
    _983_t5 = 35;
    _983_t6 = 6;
    _984_x = (struct0) {_983_t1, _983_t2, _983_t3, _983_t4, _983_t5, _983_t6};
    _983_t8 = 0;
    _983_t9 = ((int64_t*)&_984_x + _983_t8);
    _983_t10 = 6;
    _984_y = (struct1) {_983_t9, _983_t10};
    _983_t14 = 3;
    _983_t15 = _984_y._0;
    _984_z = (struct1) {_983_t15, _983_t14};
    _983_t17 = _985_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _983_t18 = _983_t17(_984_z);
    $line_idx--;
    _983_$retval = _983_t18;
    return _983_$retval;
}

int64_t _985_sum_up(struct1 _985_xs) {
    int64_t _986_sum;
    int64_t _987_i;
    uint8_t _985_t3;
    int64_t _985_t5;
    int64_t _985_$retval;
    _986_sum = 0;
    _987_i = 0;
    goto BB1;
BB1:
    _985_t3 = _987_i < _985_xs._1;
    if (_985_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _986_sum = $add_int64_t(_986_sum, *((int64_t*)_985_xs._0 + _987_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _985_t5 = 1;
    _987_i = $add_int64_t(_987_i, _985_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _985_$retval = _986_sum;
    return _985_$retval;
}

int main(void) {
  printf("%ld",_983_main());
  return 0;
}
