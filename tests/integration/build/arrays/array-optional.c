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
} struct0;

typedef struct {
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct2;

typedef struct {
    struct2 _0;
    struct2 _1;
    struct2 _2;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);
struct1 _3_safe_div_vec(struct0 _3_x,struct0 _3_y);
struct2 _5_safe_div(int64_t _5_x,int64_t _5_y);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0 _1_t5;
    struct1 _1_t0;
    struct2 _1_t10;
    int64_t _1_$retval;
    _1_t1 = (struct0) {216, 432, 648};
    _1_t5 = (struct0) {1, 2, 3};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:3:28:\n    let res = safe_div_vec((216, 432, 648), (1, 2, 3))\n                          ^";
    _1_t0 = _3_safe_div_vec(_1_t1, _1_t5);
    $line_idx--;
    _1_t10 = *((struct2*)&_1_t0 + 1);
    $tag_check(_1_t10.tag, 1, "tests/integration/arrays/array-optional.orng:4:12:\n    res[1].some\n          ^");
    _1_$retval = ((struct2*)&_1_t0 + 1)->_1;
    return _1_$retval;
}

struct1 _3_safe_div_vec(struct0 _3_x,struct0 _3_y) {
    struct2 _3_t1;
    struct2 _3_t2;
    struct2 _3_t3;
    struct1 _4_retval;
    struct2 _3_t4;
    struct2 _3_t13;
    struct2 _3_t22;
    struct1 _3_$retval;
    _3_t1 = (struct2) {.tag=0};
    _3_t2 = (struct2) {.tag=0};
    _3_t3 = (struct2) {.tag=0};
    _4_retval = (struct1) {_3_t1, _3_t2, _3_t3};
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:9:26:\n    retval[0] = safe_div(x[0], y[0])\n                        ^";
    _3_t4 = _5_safe_div(*(int64_t*)&_3_x, *(int64_t*)&_3_y);
    $line_idx--;
    *(struct2*)&_4_retval = _3_t4;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:10:26:\n    retval[1] = safe_div(x[1], y[1])\n                        ^";
    _3_t13 = _5_safe_div(*((int64_t*)&_3_x + 1), *((int64_t*)&_3_y + 1));
    $line_idx--;
    *((struct2*)&_4_retval + 1) = _3_t13;
    $lines[$line_idx++] = "tests/integration/arrays/array-optional.orng:11:26:\n    retval[2] = safe_div(x[2], y[2])\n                        ^";
    _3_t22 = _5_safe_div(*((int64_t*)&_3_x + 2), *((int64_t*)&_3_y + 2));
    $line_idx--;
    *((struct2*)&_4_retval + 2) = _3_t22;
    _3_$retval = _4_retval;
    return _3_$retval;
}

struct2 _5_safe_div(int64_t _5_x,int64_t _5_y) {
    struct2 _5_t0;
    struct2 _5_$retval;
    if (_5_y) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _5_t0 = (struct2) {.tag=1, ._1=($div_int64_t(_5_x, _5_y, "tests/integration/arrays/array-optional.orng:19:21:\n        .some <- x / y\n                   ^"))};
    goto BB4;
BB1:
    _5_t0 = (struct2) {.tag=0};
BB4:
    _5_$retval = _5_t0;
    return _5_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
