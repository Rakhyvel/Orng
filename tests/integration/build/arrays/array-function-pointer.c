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
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

typedef struct {
    function0 _0;
    function0 _1;
    function0 _2;
} struct2;

typedef int64_t(*function3)(int64_t);

typedef struct {
    function3 _0;
    function3 _1;
    function3 _2;
} struct4;

/* Function forward definitions */
int64_t _28_main(void);
int64_t _34_sum(int64_t _34_x,int64_t _34_y);
int64_t _38_diff(int64_t _38_x,int64_t _38_y);
int64_t _46_div(int64_t _46_x,int64_t _46_y);
int64_t _50_double(int64_t _50_x);
int64_t _53_halve(int64_t _53_x);
int64_t _42_mult(int64_t _42_x,int64_t _42_y);

/* Function definitions */
int64_t _28_main(void) {
    function0 _28_t1;
    function0 _28_t2;
    function0 _28_t3;
    struct2 _29_x;
    function3 _28_t5;
    function3 _28_t6;
    function3 _28_t7;
    struct4 _29_y;
    int64_t _28_t9;
    int64_t _28_t10;
    int64_t _28_t12;
    int64_t _28_t14;
    int64_t _28_t15;
    int64_t _28_t13;
    int64_t _28_t11;
    int64_t _28_$retval;
    _28_t1 = _34_sum;
    _28_t2 = _38_diff;
    _28_t3 = _46_div;
    _29_x = (struct2) {_28_t1, _28_t2, _28_t3};
    _28_t5 = _50_double;
    _28_t6 = _53_halve;
    _28_t7 = _50_double;
    _29_y = (struct4) {_28_t5, _28_t6, _28_t7};
    _28_t9 = 1;
    *((function0*)&_29_x + _28_t9) = _42_mult;
    _28_t10 = 1;
    _28_t12 = 1;
    _28_t14 = 4;
    _28_t15 = 107;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    _28_t13 = (*((function0*)&_29_x + _28_t12))(_28_t14, _28_t15);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    _28_t11 = (*((function3*)&_29_y + _28_t10))(_28_t13);
    $line_idx--;
    _28_$retval = _28_t11;
    return _28_$retval;
}

int64_t _34_sum(int64_t _34_x,int64_t _34_y) {
    int64_t _34_$retval;
    _34_$retval = $add_int64_t(_34_x, _34_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _34_$retval;
}

int64_t _38_diff(int64_t _38_x,int64_t _38_y) {
    int64_t _38_$retval;
    _38_$retval = $sub_int64_t(_38_x, _38_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _38_$retval;
}

int64_t _46_div(int64_t _46_x,int64_t _46_y) {
    int64_t _46_$retval;
    _46_$retval = $div_int64_t(_46_x, _46_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _46_$retval;
}

int64_t _50_double(int64_t _50_x) {
    int64_t _50_t0;
    int64_t _50_$retval;
    _50_t0 = 2;
    _50_$retval = $mult_int64_t(_50_t0, _50_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _50_$retval;
}

int64_t _53_halve(int64_t _53_x) {
    int64_t _53_t0;
    int64_t _53_$retval;
    _53_t0 = 2;
    _53_$retval = $div_int64_t(_53_x, _53_t0, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _53_$retval;
}

int64_t _42_mult(int64_t _42_x,int64_t _42_y) {
    int64_t _42_$retval;
    _42_$retval = $mult_int64_t(_42_x, _42_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _42_$retval;
}

int main(void) {
  printf("%ld",_28_main());
  return 0;
}
