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
int64_t _40_main(void);
struct3 _42_safe_div_vec(struct2 _42_x,struct2 _42_y);
struct4 _48_safe_div(int64_t _48_x,int64_t _48_y);

/* Function definitions */
int64_t _40_main(void) {
    function0 _40_t0;
    int64_t _40_t3;
    int64_t _40_t4;
    int64_t _40_t5;
    struct2 _40_t2;
    int64_t _40_t7;
    int64_t _40_t8;
    int64_t _40_t9;
    struct2 _40_t6;
    struct3 _40_t1;
    struct3 _41_res;
    int64_t _40_t10;
    int64_t _40_$retval;
    _40_t0 = _42_safe_div_vec;
    _40_t3 = 216;
    _40_t4 = 432;
    _40_t5 = 648;
    _40_t2 = (struct2) {_40_t3, _40_t4, _40_t5};
    _40_t7 = 1;
    _40_t8 = 2;
    _40_t9 = 3;
    _40_t6 = (struct2) {_40_t7, _40_t8, _40_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _40_t1 = _40_t0(_40_t2, _40_t6);
    $line_idx--;
    _41_res = _40_t1;
    _40_t10 = 1;
    _40_$retval = (*((struct4*)&_41_res + _40_t10))._1;
    return _40_$retval;
}

struct3 _42_safe_div_vec(struct2 _42_x,struct2 _42_y) {
    struct4 _42_t1;
    struct4 _42_t2;
    struct4 _42_t3;
    struct3 _46_retval;
    function5 _42_t4;
    int64_t _42_t6;
    int64_t _42_t7;
    struct4 _42_t5;
    int64_t _42_t8;
    function5 _42_t9;
    int64_t _42_t11;
    int64_t _42_t12;
    struct4 _42_t10;
    int64_t _42_t13;
    function5 _42_t14;
    int64_t _42_t16;
    int64_t _42_t17;
    struct4 _42_t15;
    int64_t _42_t18;
    struct3 _42_$retval;
    _42_t1 = (struct4) {.tag=0};
    _42_t2 = (struct4) {.tag=0};
    _42_t3 = (struct4) {.tag=0};
    _46_retval = (struct3) {_42_t1, _42_t2, _42_t3};
    _42_t4 = _48_safe_div;
    _42_t6 = 0;
    _42_t7 = 0;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    _42_t5 = _42_t4(*((int64_t*)&_42_x + _42_t6), *((int64_t*)&_42_y + _42_t7));
    $line_idx--;
    _42_t8 = 0;
    *((struct4*)&_46_retval + _42_t8) = _42_t5;
    _42_t9 = _48_safe_div;
    _42_t11 = 1;
    _42_t12 = 1;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    _42_t10 = _42_t9(*((int64_t*)&_42_x + _42_t11), *((int64_t*)&_42_y + _42_t12));
    $line_idx--;
    _42_t13 = 1;
    *((struct4*)&_46_retval + _42_t13) = _42_t10;
    _42_t14 = _48_safe_div;
    _42_t16 = 2;
    _42_t17 = 2;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    _42_t15 = _42_t14(*((int64_t*)&_42_x + _42_t16), *((int64_t*)&_42_y + _42_t17));
    $line_idx--;
    _42_t18 = 2;
    *((struct4*)&_46_retval + _42_t18) = _42_t15;
    _42_$retval = _46_retval;
    return _42_$retval;
}

struct4 _48_safe_div(int64_t _48_x,int64_t _48_y) {
    int64_t _48_t1;
    uint8_t _48_t3;
    int64_t _48_t5;
    struct4 _48_t0;
    struct4 _48_$retval;
    _48_t1 = 0;
    _48_t3 = _48_y == _48_t1;
    if (_48_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _48_t0 = (struct4) {.tag=0};
    goto BB6;
BB7:
    _48_t5 = $div_int64_t(_48_x, _48_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^");
    _48_t0 = (struct4) {.tag=1, ._1=_48_t5};
    goto BB6;
BB6:
    _48_$retval = _48_t0;
    return _48_$retval;
}

int main(void) {
  printf("%ld",_40_main());
  return 0;
}
