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
int64_t _50_main(void);
int64_t _52_sum_up(struct1 _52_xs);

/* Function definitions */
int64_t _50_main(void) {
    int64_t _50_t1;
    int64_t _50_t2;
    int64_t _50_t3;
    int64_t _50_t4;
    int64_t _50_t5;
    int64_t _50_t6;
    struct0 _51_x;
    int64_t _50_t8;
    int64_t* _50_t9;
    int64_t _50_t10;
    struct1 _51_y;
    int64_t _50_t11;
    int64_t _50_t14;
    int64_t* _50_t15;
    struct1 _51_z;
    int64_t _50_t18;
    function2 _50_t19;
    int64_t _50_t20;
    int64_t _50_$retval;
    _50_t1 = 1;
    _50_t2 = 15;
    _50_t3 = 24;
    _50_t4 = 4;
    _50_t5 = 35;
    _50_t6 = 6;
    _51_x = (struct0) {_50_t1, _50_t2, _50_t3, _50_t4, _50_t5, _50_t6};
    _50_t8 = 0;
    _50_t9 = ((int64_t*)&_51_x + _50_t8);
    _50_t10 = 6;
    _51_y = (struct1) {_50_t9, _50_t10};
    _50_t11 = 1;
    _50_t14 = 4;
    _50_t15 = _51_y._0 + _50_t11;
    _51_z = (struct1) {_50_t15, _50_t14};
    _50_t18 = 2;
    *((int64_t*)_51_z._0 + _50_t18) = 10;
    _50_t19 = _52_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _50_t20 = _50_t19(_51_z);
    $line_idx--;
    _50_$retval = _50_t20;
    return _50_$retval;
}

int64_t _52_sum_up(struct1 _52_xs) {
    int64_t _53_sum;
    int64_t _54_i;
    uint8_t _52_t3;
    int64_t _52_t5;
    int64_t _52_$retval;
    _53_sum = 0;
    _54_i = 0;
    goto BB1;
BB1:
    _52_t3 = _54_i < _52_xs._1;
    if (_52_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _53_sum = $add_int64_t(_53_sum, *((int64_t*)_52_xs._0 + _54_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _52_t5 = 1;
    _54_i = $add_int64_t(_54_i, _52_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _52_$retval = _53_sum;
    return _52_$retval;
}

int main(void) {
  printf("%ld",_50_main());
  return 0;
}
