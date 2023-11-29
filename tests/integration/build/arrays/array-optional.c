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
int64_t _2_main(void);
struct3 _4_safe_div_vec(struct2 _4_x,struct2 _4_y);
struct4 _6_safe_div(int64_t _6_x,int64_t _6_y);

/* Function definitions */
int64_t _2_main(void) {
    function0 _2_t0;
    int64_t _2_t3;
    int64_t _2_t4;
    int64_t _2_t5;
    struct2 _2_t2;
    int64_t _2_t7;
    int64_t _2_t8;
    int64_t _2_t9;
    struct2 _2_t6;
    struct3 _2_t1;
    struct3 _3_res;
    int64_t _2_t10;
    int64_t _2_$retval;
    _2_t0 = _4_safe_div_vec;
    _2_t3 = 216;
    _2_t4 = 432;
    _2_t5 = 648;
    _2_t2 = (struct2) {_2_t3, _2_t4, _2_t5};
    _2_t7 = 1;
    _2_t8 = 2;
    _2_t9 = 3;
    _2_t6 = (struct2) {_2_t7, _2_t8, _2_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _2_t1 = _2_t0(_2_t2, _2_t6);
    $line_idx--;
    _3_res = _2_t1;
    _2_t10 = 1;
    _2_$retval = (*((struct4*)&_3_res + _2_t10))._1;
    return _2_$retval;
}

struct3 _4_safe_div_vec(struct2 _4_x,struct2 _4_y) {
    struct4 _4_t1;
    struct4 _4_t2;
    struct4 _4_t3;
    struct3 _5_retval;
    function5 _4_t4;
    int64_t _4_t6;
    int64_t _4_t7;
    struct4 _4_t5;
    int64_t _4_t8;
    function5 _4_t9;
    int64_t _4_t11;
    int64_t _4_t12;
    struct4 _4_t10;
    int64_t _4_t13;
    function5 _4_t14;
    int64_t _4_t16;
    int64_t _4_t17;
    struct4 _4_t15;
    int64_t _4_t18;
    struct3 _4_$retval;
    _4_t1 = (struct4) {.tag=0};
    _4_t2 = (struct4) {.tag=0};
    _4_t3 = (struct4) {.tag=0};
    _5_retval = (struct3) {_4_t1, _4_t2, _4_t3};
    _4_t4 = _6_safe_div;
    _4_t6 = 0;
    _4_t7 = 0;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    _4_t5 = _4_t4(*((int64_t*)&_4_x + _4_t6), *((int64_t*)&_4_y + _4_t7));
    $line_idx--;
    _4_t8 = 0;
    *((struct4*)&_5_retval + _4_t8) = _4_t5;
    _4_t9 = _6_safe_div;
    _4_t11 = 1;
    _4_t12 = 1;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    _4_t10 = _4_t9(*((int64_t*)&_4_x + _4_t11), *((int64_t*)&_4_y + _4_t12));
    $line_idx--;
    _4_t13 = 1;
    *((struct4*)&_5_retval + _4_t13) = _4_t10;
    _4_t14 = _6_safe_div;
    _4_t16 = 2;
    _4_t17 = 2;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    _4_t15 = _4_t14(*((int64_t*)&_4_x + _4_t16), *((int64_t*)&_4_y + _4_t17));
    $line_idx--;
    _4_t18 = 2;
    *((struct4*)&_5_retval + _4_t18) = _4_t15;
    _4_$retval = _5_retval;
    return _4_$retval;
}

struct4 _6_safe_div(int64_t _6_x,int64_t _6_y) {
    int64_t _6_t1;
    uint8_t _6_t3;
    int64_t _6_t5;
    struct4 _6_t0;
    struct4 _6_$retval;
    _6_t1 = 0;
    _6_t3 = _6_y == _6_t1;
    if (_6_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _6_t0 = (struct4) {.tag=0};
    goto BB6;
BB7:
    _6_t5 = $div_int64_t(_6_x, _6_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^");
    _6_t0 = (struct4) {.tag=1, ._1=_6_t5};
    goto BB6;
BB6:
    _6_$retval = _6_t0;
    return _6_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
