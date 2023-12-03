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
int64_t _959_main(void);
int64_t _961_sum_up(struct1 _961_xs);

/* Function definitions */
int64_t _959_main(void) {
    int64_t _959_t1;
    int64_t _959_t2;
    int64_t _959_t3;
    int64_t _959_t4;
    int64_t _959_t5;
    int64_t _959_t6;
    struct0 _960_x;
    int64_t _959_t8;
    int64_t* _959_t9;
    int64_t _959_t10;
    struct1 _960_y;
    int64_t _959_t14;
    int64_t* _959_t15;
    struct1 _960_z;
    function2 _959_t17;
    int64_t _959_t18;
    int64_t _959_$retval;
    _959_t1 = 100;
    _959_t2 = 8;
    _959_t3 = 2;
    _959_t4 = 4;
    _959_t5 = 35;
    _959_t6 = 6;
    _960_x = (struct0) {_959_t1, _959_t2, _959_t3, _959_t4, _959_t5, _959_t6};
    _959_t8 = 0;
    _959_t9 = ((int64_t*)&_960_x + _959_t8);
    _959_t10 = 6;
    _960_y = (struct1) {_959_t9, _959_t10};
    _959_t14 = 3;
    _959_t15 = _960_y._0;
    _960_z = (struct1) {_959_t15, _959_t14};
    _959_t17 = _961_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _959_t18 = _959_t17(_960_z);
    $line_idx--;
    _959_$retval = _959_t18;
    return _959_$retval;
}

int64_t _961_sum_up(struct1 _961_xs) {
    int64_t _962_sum;
    int64_t _963_i;
    uint8_t _961_t3;
    int64_t _961_t5;
    int64_t _961_$retval;
    _962_sum = 0;
    _963_i = 0;
    goto BB1;
BB1:
    _961_t3 = _963_i < _961_xs._1;
    if (_961_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _962_sum = $add_int64_t(_962_sum, *((int64_t*)_961_xs._0 + _963_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _961_t5 = 1;
    _963_i = $add_int64_t(_963_i, _961_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _961_$retval = _962_sum;
    return _961_$retval;
}

int main(void) {
  printf("%ld",_959_main());
  return 0;
}
