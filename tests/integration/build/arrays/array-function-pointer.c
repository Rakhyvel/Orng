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
int64_t _30_main(void);
int64_t _36_sum(int64_t _36_x,int64_t _36_y);
int64_t _38_diff(int64_t _38_x,int64_t _38_y);
int64_t _42_div(int64_t _42_x,int64_t _42_y);
int64_t _44_double(int64_t _44_x);
int64_t _46_halve(int64_t _46_x);
int64_t _40_mult(int64_t _40_x,int64_t _40_y);

/* Function definitions */
int64_t _30_main(void){
    function0 _30_t1;
    function0 _30_t2;
    function0 _30_t3;
    struct2 _31_x;
    function3 _30_t5;
    function3 _30_t6;
    function3 _30_t7;
    struct4 _31_y;
    int64_t _30_t9;
    int64_t _30_t10;
    int64_t _30_t12;
    int64_t _30_t14;
    int64_t _30_t15;
    int64_t _30_t13;
    int64_t _30_t11;
    int64_t _30_$retval;
    _30_t1 = _36_sum;
    _30_t2 = _38_diff;
    _30_t3 = _42_div;
    _31_x = (struct2) {_30_t1, _30_t2, _30_t3};
    _30_t5 = _44_double;
    _30_t6 = _46_halve;
    _30_t7 = _44_double;
    _31_y = (struct4) {_30_t5, _30_t6, _30_t7};
    _30_t9 = 1;
    *((function0*)&_31_x + _30_t9) = _40_mult;
    _30_t10 = 1;
    _30_t12 = 1;
    _30_t14 = 4;
    _30_t15 = 107;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    _30_t13 = (*((function0*)&_31_x + _30_t12))(_30_t14, _30_t15);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    _30_t11 = (*((function3*)&_31_y + _30_t10))(_30_t13);
    $line_idx--;
    _30_$retval = _30_t11;
    return _30_$retval;
}

int64_t _36_sum(int64_t _36_x,int64_t _36_y){
    int64_t _36_$retval;
    _36_$retval = $add_int64_t(_36_x, _36_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _36_$retval;
}

int64_t _38_diff(int64_t _38_x,int64_t _38_y){
    int64_t _38_$retval;
    _38_$retval = $sub_int64_t(_38_x, _38_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _38_$retval;
}

int64_t _42_div(int64_t _42_x,int64_t _42_y){
    int64_t _42_$retval;
    _42_$retval = $div_int64_t(_42_x, _42_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _42_$retval;
}

int64_t _44_double(int64_t _44_x){
    int64_t _44_t0;
    int64_t _44_$retval;
    _44_t0 = 2;
    _44_$retval = $mult_int64_t(_44_t0, _44_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _44_$retval;
}

int64_t _46_halve(int64_t _46_x){
    int64_t _46_t0;
    int64_t _46_$retval;
    _46_t0 = 2;
    _46_$retval = $div_int64_t(_46_x, _46_t0, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _46_$retval;
}

int64_t _40_mult(int64_t _40_x,int64_t _40_y){
    int64_t _40_$retval;
    _40_$retval = $mult_int64_t(_40_x, _40_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _40_$retval;
}

int main(void) {
  printf("%ld",_30_main());
  return 0;
}
