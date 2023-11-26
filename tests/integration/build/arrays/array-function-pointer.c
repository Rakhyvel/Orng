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

typedef int64_t(*function0)(    int64_t,     int64_t);

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
int64_t _19_main(void);
int64_t _21_sum(int64_t _21_x,int64_t _21_y);
int64_t _23_diff(int64_t _23_x,int64_t _23_y);
int64_t _27_div(int64_t _27_x,int64_t _27_y);
int64_t _29_double(int64_t _29_x);
int64_t _31_halve(int64_t _31_x);
int64_t _25_mult(int64_t _25_x,int64_t _25_y);

/* Function definitions */
int64_t _19_main(void) {
    function0 _19_t1;
    function0 _19_t2;
    function0 _19_t3;
    struct2 _20_x;
    function3 _19_t5;
    function3 _19_t6;
    function3 _19_t7;
    struct4 _20_y;
    int64_t _19_t9;
    int64_t _19_t10;
    int64_t _19_t12;
    int64_t _19_t14;
    int64_t _19_t15;
    int64_t _19_t13;
    int64_t _19_t11;
    int64_t _19_$retval;
    _19_t1 = _21_sum;
    _19_t2 = _23_diff;
    _19_t3 = _27_div;
    _20_x = (struct2) {_19_t1, _19_t2, _19_t3};
    _19_t5 = _29_double;
    _19_t6 = _31_halve;
    _19_t7 = _29_double;
    _20_y = (struct4) {_19_t5, _19_t6, _19_t7};
    _19_t9 = 1;
    *((function0*)&_20_x + _19_t9) = _25_mult;
    _19_t10 = 1;
    _19_t12 = 1;
    _19_t14 = 4;
    _19_t15 = 107;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    _19_t13 = (*((function0*)&_20_x + _19_t12))(_19_t14, _19_t15);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    _19_t11 = (*((function3*)&_20_y + _19_t10))(_19_t13);
    $line_idx--;
    _19_$retval = _19_t11;
    return _19_$retval;
}

int64_t _21_sum(int64_t _21_x,int64_t _21_y) {
    int64_t _21_$retval;
    _21_$retval = $add_int64_t(_21_x, _21_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _21_$retval;
}

int64_t _23_diff(int64_t _23_x,int64_t _23_y) {
    int64_t _23_$retval;
    _23_$retval = $sub_int64_t(_23_x, _23_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _23_$retval;
}

int64_t _27_div(int64_t _27_x,int64_t _27_y) {
    int64_t _27_$retval;
    _27_$retval = $div_int64_t(_27_x, _27_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _27_$retval;
}

int64_t _29_double(int64_t _29_x) {
    int64_t _29_t0;
    int64_t _29_$retval;
    _29_t0 = 2;
    _29_$retval = $mult_int64_t(_29_t0, _29_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _29_$retval;
}

int64_t _31_halve(int64_t _31_x) {
    int64_t _31_t0;
    int64_t _31_$retval;
    _31_t0 = 2;
    _31_$retval = $div_int64_t(_31_x, _31_t0, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _31_$retval;
}

int64_t _25_mult(int64_t _25_x,int64_t _25_y) {
    int64_t _25_$retval;
    _25_$retval = $mult_int64_t(_25_x, _25_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _25_$retval;
}

int main(void) {
  printf("%ld",_19_main());
  return 0;
}
