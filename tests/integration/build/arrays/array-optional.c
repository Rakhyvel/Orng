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
} struct2;

typedef struct {
    struct2 _0;
    struct2 _1;
} struct1;

typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct4;

typedef struct {
    struct4 _0;
    struct4 _1;
    struct4 _2;
} struct3;

typedef struct3(*function0)(struct2, struct2);

typedef struct {
    int64_t _0;
    int64_t _1;
} struct6;

typedef struct4(*function5)(int64_t, int64_t);

/* Function forward definitions */
int64_t _34_main(void);
struct3 _36_safe_div_vec(struct2 _36_x,struct2 _36_y);
struct4 _38_safe_div(int64_t _38_x,int64_t _38_y);

/* Function definitions */
int64_t _34_main(void){
    function0 _34_t0;
    int64_t _34_t3;
    int64_t _34_t4;
    int64_t _34_t5;
    struct2 _34_t2;
    int64_t _34_t7;
    int64_t _34_t8;
    int64_t _34_t9;
    struct2 _34_t6;
    struct3 _34_t1;
    struct3 _35_res;
    int64_t _34_t10;
    int64_t _34_t11;
    uint64_t _34_t12;
    int64_t _34_$retval;
    _34_t0 = _36_safe_div_vec;
    _34_t3 = 216;
    _34_t4 = 432;
    _34_t5 = 648;
    _34_t2 = (struct2) {_34_t3, _34_t4, _34_t5};
    _34_t7 = 1;
    _34_t8 = 2;
    _34_t9 = 3;
    _34_t6 = (struct2) {_34_t7, _34_t8, _34_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _34_t1 = _34_t0(_34_t2, _34_t6);
    $line_idx--;
    _35_res = _34_t1;
    _34_t10 = 1;
    _34_t11 = 3;
    $bounds_check(_34_t10, _34_t11, "tests/integration/arrays/array-optional.orng:4:12:\n    res[1].some\n          ^");
    _34_t12 = (*((struct4*)&_35_res + _34_t10)).tag;
    $bounds_check(_34_t10, _34_t11, "tests/integration/arrays/array-optional.orng:2:3:\nfn main() -> Int {\n ^");
    $tag_check(_34_t12, 1, "tests/integration/arrays/array-optional.orng:2:3:\nfn main() -> Int {\n ^");
    _34_$retval = (*((struct4*)&_35_res + _34_t10))._1;
    return _34_$retval;
}

struct3 _36_safe_div_vec(struct2 _36_x,struct2 _36_y){
    struct4 _36_t1;
    struct4 _36_t2;
    struct4 _36_t3;
    struct3 _37_retval;
    function5 _36_t4;
    int64_t _36_t6;
    int64_t _36_t7;
    int64_t _36_t8;
    int64_t _36_t9;
    struct4 _36_t5;
    int64_t _36_t10;
    int64_t _36_t11;
    function5 _36_t12;
    int64_t _36_t14;
    int64_t _36_t15;
    int64_t _36_t16;
    int64_t _36_t17;
    struct4 _36_t13;
    int64_t _36_t18;
    int64_t _36_t19;
    function5 _36_t20;
    int64_t _36_t22;
    int64_t _36_t23;
    int64_t _36_t24;
    int64_t _36_t25;
    struct4 _36_t21;
    int64_t _36_t26;
    int64_t _36_t27;
    struct3 _36_$retval;
    _36_t1 = (struct4) {.tag=0};
    _36_t2 = (struct4) {.tag=0};
    _36_t3 = (struct4) {.tag=0};
    _37_retval = (struct3) {_36_t1, _36_t2, _36_t3};
    _36_t4 = _38_safe_div;
    _36_t6 = 0;
    _36_t7 = 3;
    _36_t8 = 0;
    _36_t9 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    $bounds_check(_36_t6, _36_t7, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    $bounds_check(_36_t8, _36_t9, "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^");
    _36_t5 = _36_t4(*((int64_t*)&_36_x + _36_t6), *((int64_t*)&_36_y + _36_t8));
    $line_idx--;
    _36_t10 = 0;
    _36_t11 = 3;
    $bounds_check(_36_t10, _36_t11, "tests/integration/arrays/array-optional.orng:9:12:\n    retval[0] = safe_div(x[0], y[0])\n          ^");
    *((struct4*)&_37_retval + _36_t10) = _36_t5;
    _36_t12 = _38_safe_div;
    _36_t14 = 1;
    _36_t15 = 3;
    _36_t16 = 1;
    _36_t17 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    $bounds_check(_36_t14, _36_t15, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    $bounds_check(_36_t16, _36_t17, "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^");
    _36_t13 = _36_t12(*((int64_t*)&_36_x + _36_t14), *((int64_t*)&_36_y + _36_t16));
    $line_idx--;
    _36_t18 = 1;
    _36_t19 = 3;
    $bounds_check(_36_t18, _36_t19, "tests/integration/arrays/array-optional.orng:10:12:\n    retval[1] = safe_div(x[1], y[1])\n          ^");
    *((struct4*)&_37_retval + _36_t18) = _36_t13;
    _36_t20 = _38_safe_div;
    _36_t22 = 2;
    _36_t23 = 3;
    _36_t24 = 2;
    _36_t25 = 3;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    $bounds_check(_36_t22, _36_t23, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    $bounds_check(_36_t24, _36_t25, "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^");
    _36_t21 = _36_t20(*((int64_t*)&_36_x + _36_t22), *((int64_t*)&_36_y + _36_t24));
    $line_idx--;
    _36_t26 = 2;
    _36_t27 = 3;
    $bounds_check(_36_t26, _36_t27, "tests/integration/arrays/array-optional.orng:11:12:\n    retval[2] = safe_div(x[2], y[2])\n          ^");
    *((struct4*)&_37_retval + _36_t26) = _36_t21;
    _36_$retval = _37_retval;
    return _36_$retval;
}

struct4 _38_safe_div(int64_t _38_x,int64_t _38_y){
    int64_t _38_t1;
    uint8_t _38_t3;
    int64_t _38_t5;
    struct4 _38_t0;
    struct4 _38_$retval;
    _38_t1 = 0;
    _38_t3 = _38_y == _38_t1;
    if (_38_t3) {
        goto BB29;
    } else {
        goto BB33;
    }
BB29:
    _38_t0 = (struct4) {.tag=0};
    goto BB32;
BB33:
    _38_t5 = $div_int64_t(_38_x, _38_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^");
    _38_t0 = (struct4) {.tag=1, ._1=_38_t5};
    goto BB32;
BB32:
    _38_$retval = _38_t0;
    return _38_$retval;
}

int main(void) {
  printf("%ld",_34_main());
  return 0;
}
