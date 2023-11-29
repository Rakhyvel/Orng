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
int64_t _23_main(void);
int64_t _27_sum(int64_t _27_x,int64_t _27_y);
int64_t _29_diff(int64_t _29_x,int64_t _29_y);
int64_t _33_div(int64_t _33_x,int64_t _33_y);
int64_t _35_double(int64_t _35_x);
int64_t _37_halve(int64_t _37_x);
int64_t _31_mult(int64_t _31_x,int64_t _31_y);

/* Function definitions */
int64_t _23_main(void) {
    function0 _23_t1;
    function0 _23_t2;
    function0 _23_t3;
    struct2 _24_x;
    function3 _23_t5;
    function3 _23_t6;
    function3 _23_t7;
    struct4 _24_y;
    int64_t _23_t9;
    int64_t _23_t10;
    int64_t _23_t12;
    int64_t _23_t14;
    int64_t _23_t15;
    int64_t _23_t13;
    int64_t _23_t11;
    int64_t _23_$retval;
    _23_t1 = _27_sum;
    _23_t2 = _29_diff;
    _23_t3 = _33_div;
    _24_x = (struct2) {_23_t1, _23_t2, _23_t3};
    _23_t5 = _35_double;
    _23_t6 = _37_halve;
    _23_t7 = _35_double;
    _24_y = (struct4) {_23_t5, _23_t6, _23_t7};
    _23_t9 = 1;
    *((function0*)&_24_x + _23_t9) = _31_mult;
    _23_t10 = 1;
    _23_t12 = 1;
    _23_t14 = 4;
    _23_t15 = 107;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    _23_t13 = (*((function0*)&_24_x + _23_t12))(_23_t14, _23_t15);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    _23_t11 = (*((function3*)&_24_y + _23_t10))(_23_t13);
    $line_idx--;
    _23_$retval = _23_t11;
    return _23_$retval;
}

int64_t _27_sum(int64_t _27_x,int64_t _27_y) {
    int64_t _27_$retval;
    _27_$retval = $add_int64_t(_27_x, _27_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _27_$retval;
}

int64_t _29_diff(int64_t _29_x,int64_t _29_y) {
    int64_t _29_$retval;
    _29_$retval = $sub_int64_t(_29_x, _29_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _29_$retval;
}

int64_t _33_div(int64_t _33_x,int64_t _33_y) {
    int64_t _33_$retval;
    _33_$retval = $div_int64_t(_33_x, _33_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _33_$retval;
}

int64_t _35_double(int64_t _35_x) {
    int64_t _35_t0;
    int64_t _35_$retval;
    _35_t0 = 2;
    _35_$retval = $mult_int64_t(_35_t0, _35_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _35_$retval;
}

int64_t _37_halve(int64_t _37_x) {
    int64_t _37_t0;
    int64_t _37_$retval;
    _37_t0 = 2;
    _37_$retval = $div_int64_t(_37_x, _37_t0, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _37_$retval;
}

int64_t _31_mult(int64_t _31_x,int64_t _31_y) {
    int64_t _31_$retval;
    _31_$retval = $mult_int64_t(_31_x, _31_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _31_$retval;
}

int main(void) {
  printf("%ld",_23_main());
  return 0;
}
