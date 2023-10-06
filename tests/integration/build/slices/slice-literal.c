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
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_sum(struct1 _3_xs);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t2;
    int64_t* _1_t9;
    struct1 _1_t1;
    int64_t _1_$retval;
    _1_t2 = (struct0) {200, 0, 8};
    _1_t9 = (int64_t*)&_1_t2;
    _1_t1 = (struct1) {_1_t9, 3};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    $line_idx--;
    _1_$retval = _3_sum(_1_t1);
    return _1_$retval;
}

int64_t _3_sum(struct1 _3_xs) {
    int64_t _3_t0;
    int64_t* _3_t13;
    int64_t* _3_t14;
    struct1 _3_t15;
    int64_t _3_$retval;
    int64_t _3_t9;
    int64_t _3_t10;
    if (_3_xs._1) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    $bounds_check(0, _3_xs._1, "tests/integration/slices/slice-literal.orng:10:12:\n        xs[0] + sum(xs[1..])\n          ^");
    _3_t9 = 1;
    _3_t10 = _3_xs._1;
    if (_3_t9 > _3_t10) {
        goto BB6;
    } else {
        goto BB7;
    }
BB1:
    _3_t0 = 0;
    goto BB4;
BB6:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB7:
    _3_t13 = _3_xs._0;
    _3_t14 = _3_t13 + _3_t9;
    _3_t15 = (struct1) {_3_t14, ($sub_int64_t(_3_t10, _3_t9, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^"))};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    $line_idx--;
    _3_t0 = $add_int64_t(*(int64_t*)_3_xs._0, _3_sum(_3_t15), "tests/integration/slices/slice-literal.orng:7:7:\n    if xs.length == 0 {\n     ^");
BB4:
    _3_$retval = _3_t0;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
