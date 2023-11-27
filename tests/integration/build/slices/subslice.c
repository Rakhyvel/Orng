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
int64_t _955_main(void);
int64_t _957_sum_up(struct1 _957_xs);

/* Function definitions */
int64_t _955_main(void) {
    int64_t _955_t1;
    int64_t _955_t2;
    int64_t _955_t3;
    int64_t _955_t4;
    int64_t _955_t5;
    int64_t _955_t6;
    struct0 _956_x;
    int64_t _955_t8;
    int64_t* _955_t9;
    int64_t _955_t10;
    struct1 _956_y;
    int64_t _955_t11;
    int64_t _955_t14;
    int64_t* _955_t15;
    struct1 _956_z;
    int64_t _955_t18;
    function2 _955_t19;
    int64_t _955_t20;
    int64_t _955_$retval;
    _955_t1 = 1;
    _955_t2 = 15;
    _955_t3 = 24;
    _955_t4 = 4;
    _955_t5 = 35;
    _955_t6 = 6;
    _956_x = (struct0) {_955_t1, _955_t2, _955_t3, _955_t4, _955_t5, _955_t6};
    _955_t8 = 0;
    _955_t9 = ((int64_t*)&_956_x + _955_t8);
    _955_t10 = 6;
    _956_y = (struct1) {_955_t9, _955_t10};
    _955_t11 = 1;
    _955_t14 = 4;
    _955_t15 = _956_y._0 + _955_t11;
    _956_z = (struct1) {_955_t15, _955_t14};
    _955_t18 = 2;
    *((int64_t*)_956_z._0 + _955_t18) = 10;
    _955_t19 = _957_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _955_t20 = _955_t19(_956_z);
    $line_idx--;
    _955_$retval = _955_t20;
    return _955_$retval;
}

int64_t _957_sum_up(struct1 _957_xs) {
    int64_t _958_sum;
    int64_t _959_i;
    uint8_t _957_t3;
    int64_t _957_t5;
    int64_t _957_$retval;
    _958_sum = 0;
    _959_i = 0;
    goto BB1;
BB1:
    _957_t3 = _959_i < _957_xs._1;
    if (_957_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _958_sum = $add_int64_t(_958_sum, *((int64_t*)_957_xs._0 + _959_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _957_t5 = 1;
    _959_i = $add_int64_t(_959_i, _957_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _957_$retval = _958_sum;
    return _957_$retval;
}

int main(void) {
  printf("%ld",_955_main());
  return 0;
}
