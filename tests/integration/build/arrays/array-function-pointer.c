/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct4;

/* Struct, union, and function definitions */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

struct struct2 {
    function0 _0;
    function0 _1;
    function0 _2;
};

typedef int64_t(*function3)(int64_t);

struct struct4 {
    function3 _0;
    function3 _1;
    function3 _2;
};

/* Function forward definitions */
int64_t _26_main(void);
int64_t _28_sum(int64_t _28_x, int64_t _28_y);
int64_t _30_diff(int64_t _30_x, int64_t _30_y);
int64_t _34_div(int64_t _34_x, int64_t _34_y);
int64_t _36_double(int64_t _36_x);
int64_t _38_halve(int64_t _38_x);
int64_t _32_mult(int64_t _32_x, int64_t _32_y);


/* Function definitions */
int64_t _26_main(void){
    function0 _26_t1;
    function0 _26_t2;
    function0 _26_t3;
    struct struct2 _27_x;
    function3 _26_t6;
    function3 _26_t7;
    function3 _26_t8;
    struct struct4 _27_y;
    int64_t _26_t11;
    int64_t _26_t12;
    int64_t _26_t13;
    int64_t _26_t14;
    int64_t _26_t16;
    int64_t _26_t17;
    int64_t _26_t19;
    int64_t _26_t20;
    int64_t _26_t18;
    int64_t _26_t15;
    int64_t _26_$retval;
    _26_t1 = (function0) _28_sum;
    _26_t2 = (function0) _30_diff;
    _26_t3 = (function0) _34_div;
    _27_x = (struct struct2) {_26_t1, _26_t2, _26_t3};
    _26_t6 = (function3) _36_double;
    _26_t7 = (function3) _38_halve;
    _26_t8 = (function3) _36_double;
    _27_y = (struct struct4) {_26_t6, _26_t7, _26_t8};
    _26_t11 = 1;
    _26_t12 = 3;
    $bounds_check(_26_t11, _26_t12, "tests/integration/arrays/array-function-pointer.orng:5:16:\n    x[1] = mult\n              ^");
    *((function0*)&_27_x + _26_t11) = (function0) _32_mult;
    _26_t13 = 1;
    _26_t14 = 3;
    _26_t16 = 1;
    _26_t17 = 3;
    _26_t19 = 4;
    _26_t20 = 107;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    $bounds_check(_26_t16, _26_t17, "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^");
    _26_t18 = (*((function0*)&_27_x + _26_t16))(_26_t19, _26_t20);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    $bounds_check(_26_t13, _26_t14, "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^");
    _26_t15 = (*((function3*)&_27_y + _26_t13))(_26_t18);
    $line_idx--;
    _26_$retval = _26_t15;
    return _26_$retval;
}

int64_t _28_sum(int64_t _28_x, int64_t _28_y){
    int64_t _28_$retval;
    _28_$retval = $add_int64_t(_28_x, _28_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _28_$retval;
}

int64_t _30_diff(int64_t _30_x, int64_t _30_y){
    int64_t _30_$retval;
    _30_$retval = $sub_int64_t(_30_x, _30_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _30_$retval;
}

int64_t _34_div(int64_t _34_x, int64_t _34_y){
    int64_t _34_$retval;
    _34_$retval = $div_int64_t(_34_x, _34_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _34_$retval;
}

int64_t _36_double(int64_t _36_x){
    int64_t _36_t0;
    int64_t _36_$retval;
    _36_t0 = 2;
    _36_$retval = $mult_int64_t(_36_t0, _36_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _36_$retval;
}

int64_t _38_halve(int64_t _38_x){
    int64_t _38_t0;
    int64_t _38_$retval;
    _38_t0 = 2;
    _38_$retval = $div_int64_t(_38_x, _38_t0, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _38_$retval;
}

int64_t _32_mult(int64_t _32_x, int64_t _32_y){
    int64_t _32_$retval;
    _32_$retval = $mult_int64_t(_32_x, _32_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _32_$retval;
}


int main(void) {
  printf("%ld",_26_main());
  return 0;
}
