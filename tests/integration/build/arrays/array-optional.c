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
int64_t _57_main(void);
struct3 _59_safe_div_vec(struct2 _59_x,struct2 _59_y);
struct4 _68_safe_div(int64_t _68_x,int64_t _68_y);

/* Function definitions */
int64_t _57_main(void) {
    function0 _57_t0;
    int64_t _57_t3;
    int64_t _57_t4;
    int64_t _57_t5;
    struct2 _57_t2;
    int64_t _57_t7;
    int64_t _57_t8;
    int64_t _57_t9;
    struct2 _57_t6;
    struct3 _57_t1;
    struct3 _58_res;
    int64_t _57_t10;
    int64_t _57_$retval;
    _57_t0 = _59_safe_div_vec;
    _57_t3 = 216;
    _57_t4 = 432;
    _57_t5 = 648;
    _57_t2 = (struct2) {_57_t3, _57_t4, _57_t5};
    _57_t7 = 1;
    _57_t8 = 2;
    _57_t9 = 3;
    _57_t6 = (struct2) {_57_t7, _57_t8, _57_t9};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _57_t1 = _57_t0(_57_t2, _57_t6);
    $line_idx--;
    _58_res = _57_t1;
    _57_t10 = 1;
    _57_$retval = (*((struct4*)&_58_res + _57_t10))._1;
    return _57_$retval;
}

struct3 _59_safe_div_vec(struct2 _59_x,struct2 _59_y) {
    struct4 _59_t1;
    struct4 _59_t2;
    struct4 _59_t3;
    struct3 _65_retval;
    function5 _59_t4;
    int64_t _59_t6;
    int64_t _59_t7;
    struct4 _59_t5;
    int64_t _59_t8;
    function5 _59_t9;
    int64_t _59_t11;
    int64_t _59_t12;
    struct4 _59_t10;
    int64_t _59_t13;
    function5 _59_t14;
    int64_t _59_t16;
    int64_t _59_t17;
    struct4 _59_t15;
    int64_t _59_t18;
    struct3 _59_$retval;
    _59_t1 = (struct4) {.tag=0};
    _59_t2 = (struct4) {.tag=0};
    _59_t3 = (struct4) {.tag=0};
    _65_retval = (struct3) {_59_t1, _59_t2, _59_t3};
    _59_t4 = _68_safe_div;
    _59_t6 = 0;
    _59_t7 = 0;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    _59_t5 = _59_t4(*((int64_t*)&_59_x + _59_t6), *((int64_t*)&_59_y + _59_t7));
    $line_idx--;
    _59_t8 = 0;
    *((struct4*)&_65_retval + _59_t8) = _59_t5;
    _59_t9 = _68_safe_div;
    _59_t11 = 1;
    _59_t12 = 1;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    _59_t10 = _59_t9(*((int64_t*)&_59_x + _59_t11), *((int64_t*)&_59_y + _59_t12));
    $line_idx--;
    _59_t13 = 1;
    *((struct4*)&_65_retval + _59_t13) = _59_t10;
    _59_t14 = _68_safe_div;
    _59_t16 = 2;
    _59_t17 = 2;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    _59_t15 = _59_t14(*((int64_t*)&_59_x + _59_t16), *((int64_t*)&_59_y + _59_t17));
    $line_idx--;
    _59_t18 = 2;
    *((struct4*)&_65_retval + _59_t18) = _59_t15;
    _59_$retval = _65_retval;
    return _59_$retval;
}

struct4 _68_safe_div(int64_t _68_x,int64_t _68_y) {
    int64_t _68_t1;
    uint8_t _68_t3;
    int64_t _68_t5;
    struct4 _68_t0;
    struct4 _68_$retval;
    _68_t1 = 0;
    _68_t3 = _68_y == _68_t1;
    if (_68_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _68_t0 = (struct4) {.tag=0};
    goto BB6;
BB7:
    _68_t5 = $div_int64_t(_68_x, _68_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^");
    _68_t0 = (struct4) {.tag=1, ._1=_68_t5};
    goto BB6;
BB6:
    _68_$retval = _68_t0;
    return _68_$retval;
}

int main(void) {
  printf("%ld",_57_main());
  return 0;
}
