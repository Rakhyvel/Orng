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
int64_t _924_main(void);
int64_t _926_sum_up(struct1 _926_xs);

/* Function definitions */
int64_t _924_main(void) {
    int64_t _924_t1;
    int64_t _924_t2;
    int64_t _924_t3;
    int64_t _924_t4;
    int64_t _924_t5;
    int64_t _924_t6;
    struct0 _925_x;
    int64_t _924_t8;
    int64_t* _924_t9;
    int64_t _924_t10;
    struct1 _925_y;
    int64_t _924_t14;
    int64_t* _924_t15;
    struct1 _925_z;
    function2 _924_t17;
    int64_t _924_t18;
    int64_t _924_$retval;
    _924_t1 = 100;
    _924_t2 = 8;
    _924_t3 = 2;
    _924_t4 = 4;
    _924_t5 = 35;
    _924_t6 = 6;
    _925_x = (struct0) {_924_t1, _924_t2, _924_t3, _924_t4, _924_t5, _924_t6};
    _924_t8 = 0;
    _924_t9 = ((int64_t*)&_925_x + _924_t8);
    _924_t10 = 6;
    _925_y = (struct1) {_924_t9, _924_t10};
    _924_t14 = 3;
    _924_t15 = _925_y._0;
    _925_z = (struct1) {_924_t15, _924_t14};
    _924_t17 = _926_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _924_t18 = _924_t17(_925_z);
    $line_idx--;
    _924_$retval = _924_t18;
    return _924_$retval;
}

int64_t _926_sum_up(struct1 _926_xs) {
    int64_t _927_sum;
    int64_t _928_i;
    uint8_t _926_t3;
    int64_t _926_t5;
    int64_t _926_$retval;
    _927_sum = 0;
    _928_i = 0;
    goto BB1;
BB1:
    _926_t3 = _928_i < _926_xs._1;
    if (_926_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _927_sum = $add_int64_t(_927_sum, *((int64_t*)_926_xs._0 + _928_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _926_t5 = 1;
    _928_i = $add_int64_t(_928_i, _926_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _926_$retval = _927_sum;
    return _926_$retval;
}

int main(void) {
  printf("%ld",_924_main());
  return 0;
}
