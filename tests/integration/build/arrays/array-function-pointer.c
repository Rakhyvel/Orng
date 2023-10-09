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
} struct2;

typedef int64_t(*function1)(    int64_t,     int64_t);

typedef struct {
    function1 _0;
    function1 _1;
    function1 _2;
} struct0;

typedef int64_t(*function4)(int64_t);

typedef struct {
    function4 _0;
    function4 _1;
    function4 _2;
} struct3;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_sum(int64_t _3_x,int64_t _3_y);
int64_t _5_diff(int64_t _5_x,int64_t _5_y);
int64_t _9_div(int64_t _9_x,int64_t _9_y);
int64_t _11_double(int64_t _11_x);
int64_t _13_halve(int64_t _13_x);
int64_t _7_mult(int64_t _7_x,int64_t _7_y);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _2_x;
    struct3 _2_y;
    function4 _1_t5;
    function1 _1_t9;
    int64_t _1_$retval;
    _2_x = (struct0) {_3_sum, _5_diff, _9_div};
    _2_y = (struct3) {_11_double, _13_halve, _11_double};
    *((function1*)&_2_x + 1) = _7_mult;
    _1_t5 = *((function4*)&_2_y + 1);
    _1_t9 = *((function1*)&_2_x + 1);
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:15:\n    y[1](x[1](4, 107))\n             ^";
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/arrays/array-function-pointer.orng:6:10:\n    y[1](x[1](4, 107))\n        ^";
    $line_idx--;
    _1_$retval = _1_t5(_1_t9(4, 107));
    return _1_$retval;
}

int64_t _3_sum(int64_t _3_x,int64_t _3_y) {
    int64_t _3_$retval;
    _3_$retval = $add_int64_t(_3_x, _3_y, "tests/integration/arrays/array-function-pointer.orng:10:8:\n    x + y\n      ^");
    return _3_$retval;
}

int64_t _5_diff(int64_t _5_x,int64_t _5_y) {
    int64_t _5_$retval;
    _5_$retval = $sub_int64_t(_5_x, _5_y, "tests/integration/arrays/array-function-pointer.orng:14:8:\n    x - y\n      ^");
    return _5_$retval;
}

int64_t _9_div(int64_t _9_x,int64_t _9_y) {
    int64_t _9_$retval;
    _9_$retval = $div_int64_t(_9_x, _9_y, "tests/integration/arrays/array-function-pointer.orng:22:8:\n    x / y\n      ^");
    return _9_$retval;
}

int64_t _11_double(int64_t _11_x) {
    int64_t _11_$retval;
    _11_$retval = $mult_int64_t(2, _11_x, "tests/integration/arrays/array-function-pointer.orng:26:8:\n    2 * x\n      ^");
    return _11_$retval;
}

int64_t _13_halve(int64_t _13_x) {
    int64_t _13_$retval;
    _13_$retval = $div_int64_t(_13_x, 2, "tests/integration/arrays/array-function-pointer.orng:30:8:\n    x / 2\n      ^");
    return _13_$retval;
}

int64_t _7_mult(int64_t _7_x,int64_t _7_y) {
    int64_t _7_$retval;
    _7_$retval = $mult_int64_t(_7_x, _7_y, "tests/integration/arrays/array-function-pointer.orng:18:8:\n    x * y\n      ^");
    return _7_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
