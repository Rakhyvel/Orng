/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct2;
struct struct3;
struct struct4;
struct struct6;

/* Struct, union, and function definitions */
struct struct2 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
};

struct struct1 {
    struct struct2 _0;
    struct struct2 _1;
};

struct struct4 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

struct struct3 {
    struct struct4 _0;
    struct struct4 _1;
    struct struct4 _2;
};

typedef struct struct3(*function0)(struct struct2, struct struct2);

struct struct6 {
    int64_t _0;
    int64_t _1;
};

typedef struct struct4(*function5)(int64_t, int64_t);

/* Function forward definitions */
int64_t _39_main(void);
struct struct3 _41_safe_div_vec(struct struct2 _41_x, struct struct2 _41_y);
struct struct4 _43_safe_div(int64_t _43_x, int64_t _43_y);


/* Function definitions */
int64_t _39_main(void){
    function0 _39_t0;
    int64_t _39_t3;
    int64_t _39_t4;
    int64_t _39_t5;
    struct struct2 _39_t2;
    int64_t _39_t7;
    int64_t _39_t8;
    int64_t _39_t9;
    struct struct2 _39_t6;
    struct struct3 _39_t1;
    struct struct3 _40_res;
    int64_t _39_t11;
    int64_t _39_t12;
    uint64_t _39_t13;
    int64_t _39_$retval;
    _39_t0 = (function0) _41_safe_div_vec;
    _39_t3 = 216;
    _39_t4 = 432;
    _39_t5 = 648;
    _39_t2 = (struct struct2) {_39_t3, _39_t4, _39_t5};
    _39_t7 = 1;
    _39_t8 = 2;
    _39_t9 = 3;
    _39_t6 = (struct struct2) {_39_t7, _39_t8, _39_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _39_t1 = _39_t0(_39_t2, _39_t6);
    $line_idx--;
    _40_res = _39_t1;
    _39_t11 = 1;
    _39_t12 = 3;
    $bounds_check(_39_t11, _39_t12, "tests/integration/arrays/array-optional.orng:4:12:\n    res[1].some\n          ^");
    _39_t13 = (*((struct struct4*)&_40_res + _39_t11)).tag;
    $bounds_check(_39_t11, _39_t12, "tests/integration/arrays/array-optional.orng:2:8:\nfn main() -> Int {\n      ^");
    $tag_check(_39_t13, 0, "tests/integration/arrays/array-optional.orng:2:8:\nfn main() -> Int {\n      ^");
    _39_$retval = (*((struct struct4*)&_40_res + _39_t11))._0;
    return _39_$retval;
}

struct struct3 _41_safe_div_vec(struct struct2 _41_x, struct struct2 _41_y){
    struct struct4 _41_t2;
    struct struct4 _41_t4;
    struct struct4 _41_t6;
    struct struct3 _42_retval;
    function5 _41_t8;
    int64_t _41_t10;
    int64_t _41_t11;
    int64_t _41_t12;
    int64_t _41_t13;
    struct struct4 _41_t9;
    int64_t _41_t14;
    int64_t _41_t15;
    function5 _41_t16;
    int64_t _41_t18;
    int64_t _41_t19;
    int64_t _41_t20;
    int64_t _41_t21;
    struct struct4 _41_t17;
    int64_t _41_t22;
    int64_t _41_t23;
    function5 _41_t24;
    int64_t _41_t26;
    int64_t _41_t27;
    int64_t _41_t28;
    int64_t _41_t29;
    struct struct4 _41_t25;
    int64_t _41_t30;
    int64_t _41_t31;
    struct struct3 _41_$retval;
    _41_t2 = (struct struct4) {.tag=1};
    _41_t4 = (struct struct4) {.tag=1};
    _41_t6 = (struct struct4) {.tag=1};
    _42_retval = (struct struct3) {_41_t2, _41_t4, _41_t6};
    _41_t8 = (function5) _43_safe_div;
    _41_t10 = 0;
    _41_t11 = 3;
    _41_t12 = 0;
    _41_t13 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    $bounds_check(_41_t10, _41_t11, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    $bounds_check(_41_t12, _41_t13, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    _41_t9 = _41_t8(*((int64_t*)&_41_x + _41_t10), *((int64_t*)&_41_y + _41_t12));
    $line_idx--;
    _41_t14 = 0;
    _41_t15 = 3;
    $bounds_check(_41_t14, _41_t15, "tests/integration/arrays/array-optional.orng:9:12:\n    retval[0] = safe_div(x[0], y[0])\n          ^");
    *((struct struct4*)&_42_retval + _41_t14) = _41_t9;
    _41_t16 = (function5) _43_safe_div;
    _41_t18 = 1;
    _41_t19 = 3;
    _41_t20 = 1;
    _41_t21 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    $bounds_check(_41_t18, _41_t19, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    $bounds_check(_41_t20, _41_t21, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    _41_t17 = _41_t16(*((int64_t*)&_41_x + _41_t18), *((int64_t*)&_41_y + _41_t20));
    $line_idx--;
    _41_t22 = 1;
    _41_t23 = 3;
    $bounds_check(_41_t22, _41_t23, "tests/integration/arrays/array-optional.orng:10:12:\n    retval[1] = safe_div(x[1], y[1])\n          ^");
    *((struct struct4*)&_42_retval + _41_t22) = _41_t17;
    _41_t24 = (function5) _43_safe_div;
    _41_t26 = 2;
    _41_t27 = 3;
    _41_t28 = 2;
    _41_t29 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    $bounds_check(_41_t26, _41_t27, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    $bounds_check(_41_t28, _41_t29, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    _41_t25 = _41_t24(*((int64_t*)&_41_x + _41_t26), *((int64_t*)&_41_y + _41_t28));
    $line_idx--;
    _41_t30 = 2;
    _41_t31 = 3;
    $bounds_check(_41_t30, _41_t31, "tests/integration/arrays/array-optional.orng:11:12:\n    retval[2] = safe_div(x[2], y[2])\n          ^");
    *((struct struct4*)&_42_retval + _41_t30) = _41_t25;
    _41_$retval = _42_retval;
    return _41_$retval;
}

struct struct4 _43_safe_div(int64_t _43_x, int64_t _43_y){
    int64_t _43_t1;
    uint8_t _43_t3;
    int64_t _43_t6;
    struct struct4 _43_t0;
    struct struct4 _43_$retval;
    _43_t1 = 0;
    _43_t3 = _43_y==_43_t1;
    if (_43_t3) {
        goto BB32;
    } else {
        goto BB36;
    }
BB32:
    _43_t0 = (struct struct4) {.tag=1};
    goto BB35;
BB36:
    _43_t6 = $div_int64_t(_43_x, _43_y, "tests/integration/arrays/array-optional.orng:19:18:\n        .some(x / y)\n                ^");
    _43_t0 = (struct struct4) {.tag=0, ._0=_43_t6};
    goto BB35;
BB35:
    _43_$retval = _43_t0;
    return _43_$retval;
}


int main(void) {
  printf("%ld",_39_main());
  return 0;
}
