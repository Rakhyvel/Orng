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
int64_t _43_main(void);
struct struct3 _45_safe_div_vec(struct struct2 _45_x, struct struct2 _45_y);
struct struct4 _47_safe_div(int64_t _47_x, int64_t _47_y);


/* Function definitions */
int64_t _43_main(void){
    function0 _43_t0;
    int64_t _43_t3;
    int64_t _43_t4;
    int64_t _43_t5;
    struct struct2 _43_t2;
    int64_t _43_t7;
    int64_t _43_t8;
    int64_t _43_t9;
    struct struct2 _43_t6;
    struct struct3 _43_t1;
    struct struct3 _44_res;
    int64_t _43_t11;
    int64_t _43_t12;
    uint64_t _43_t13;
    int64_t _43_$retval;
    _43_t0 = (function0) _45_safe_div_vec;
    _43_t3 = 216;
    _43_t4 = 432;
    _43_t5 = 648;
    _43_t2 = (struct struct2) {_43_t3, _43_t4, _43_t5};
    _43_t7 = 1;
    _43_t8 = 2;
    _43_t9 = 3;
    _43_t6 = (struct struct2) {_43_t7, _43_t8, _43_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _43_t1 = _43_t0(_43_t2, _43_t6);
    $line_idx--;
    _44_res = _43_t1;
    _43_t11 = 1;
    _43_t12 = 3;
    $bounds_check(_43_t11, _43_t12, "tests/integration/arrays/array-optional.orng:4:12:\n    res[1].some\n          ^");
    _43_t13 = (*((struct struct4*)&_44_res + _43_t11)).tag;
    $bounds_check(_43_t11, _43_t12, "tests/integration/arrays/array-optional.orng:2:8:\nfn main() -> Int {\n      ^");
    $tag_check(_43_t13, 0, "tests/integration/arrays/array-optional.orng:2:8:\nfn main() -> Int {\n      ^");
    _43_$retval = (*((struct struct4*)&_44_res + _43_t11))._0;
    return _43_$retval;
}

struct struct3 _45_safe_div_vec(struct struct2 _45_x, struct struct2 _45_y){
    struct struct4 _45_t2;
    struct struct4 _45_t4;
    struct struct4 _45_t6;
    struct struct3 _46_retval;
    function5 _45_t8;
    int64_t _45_t10;
    int64_t _45_t11;
    int64_t _45_t12;
    int64_t _45_t13;
    struct struct4 _45_t9;
    int64_t _45_t14;
    int64_t _45_t15;
    function5 _45_t16;
    int64_t _45_t18;
    int64_t _45_t19;
    int64_t _45_t20;
    int64_t _45_t21;
    struct struct4 _45_t17;
    int64_t _45_t22;
    int64_t _45_t23;
    function5 _45_t24;
    int64_t _45_t26;
    int64_t _45_t27;
    int64_t _45_t28;
    int64_t _45_t29;
    struct struct4 _45_t25;
    int64_t _45_t30;
    int64_t _45_t31;
    struct struct3 _45_$retval;
    _45_t2 = (struct struct4) {.tag=1};
    _45_t4 = (struct struct4) {.tag=1};
    _45_t6 = (struct struct4) {.tag=1};
    _46_retval = (struct struct3) {_45_t2, _45_t4, _45_t6};
    _45_t8 = (function5) _47_safe_div;
    _45_t10 = 0;
    _45_t11 = 3;
    _45_t12 = 0;
    _45_t13 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    $bounds_check(_45_t10, _45_t11, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    $bounds_check(_45_t12, _45_t13, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    _45_t9 = _45_t8(*((int64_t*)&_45_x + _45_t10), *((int64_t*)&_45_y + _45_t12));
    $line_idx--;
    _45_t14 = 0;
    _45_t15 = 3;
    $bounds_check(_45_t14, _45_t15, "tests/integration/arrays/array-optional.orng:9:12:\n    retval[0] = safe_div(x[0], y[0])\n          ^");
    *((struct struct4*)&_46_retval + _45_t14) = _45_t9;
    _45_t16 = (function5) _47_safe_div;
    _45_t18 = 1;
    _45_t19 = 3;
    _45_t20 = 1;
    _45_t21 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    $bounds_check(_45_t18, _45_t19, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    $bounds_check(_45_t20, _45_t21, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    _45_t17 = _45_t16(*((int64_t*)&_45_x + _45_t18), *((int64_t*)&_45_y + _45_t20));
    $line_idx--;
    _45_t22 = 1;
    _45_t23 = 3;
    $bounds_check(_45_t22, _45_t23, "tests/integration/arrays/array-optional.orng:10:12:\n    retval[1] = safe_div(x[1], y[1])\n          ^");
    *((struct struct4*)&_46_retval + _45_t22) = _45_t17;
    _45_t24 = (function5) _47_safe_div;
    _45_t26 = 2;
    _45_t27 = 3;
    _45_t28 = 2;
    _45_t29 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    $bounds_check(_45_t26, _45_t27, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    $bounds_check(_45_t28, _45_t29, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    _45_t25 = _45_t24(*((int64_t*)&_45_x + _45_t26), *((int64_t*)&_45_y + _45_t28));
    $line_idx--;
    _45_t30 = 2;
    _45_t31 = 3;
    $bounds_check(_45_t30, _45_t31, "tests/integration/arrays/array-optional.orng:11:12:\n    retval[2] = safe_div(x[2], y[2])\n          ^");
    *((struct struct4*)&_46_retval + _45_t30) = _45_t25;
    _45_$retval = _46_retval;
    return _45_$retval;
}

struct struct4 _47_safe_div(int64_t _47_x, int64_t _47_y){
    int64_t _47_t1;
    uint8_t _47_t3;
    int64_t _47_t6;
    struct struct4 _47_t0;
    struct struct4 _47_$retval;
    _47_t1 = 0;
    _47_t3 = _47_y==_47_t1;
    if (_47_t3) {
        goto BB36;
    } else {
        goto BB40;
    }
BB36:
    _47_t0 = (struct struct4) {.tag=1};
    goto BB39;
BB40:
    _47_t6 = $div_int64_t(_47_x, _47_y, "tests/integration/arrays/array-optional.orng:19:18:\n        .some(x / y)\n                ^");
    _47_t0 = (struct struct4) {.tag=0, ._0=_47_t6};
    goto BB39;
BB39:
    _47_$retval = _47_t0;
    return _47_$retval;
}


int main(void) {
  printf("%ld",_43_main());
  return 0;
}
